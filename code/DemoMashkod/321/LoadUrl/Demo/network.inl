template<class Socket>
class GatewayServer{
public:
  static fd_set get_fd_set_zero(){fd_set tmp;FD_ZERO(&tmp);return tmp;}
public:
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(Socket,listener,$)\
  ADD(std::vector<Socket>,clients,$)\
  ADD(bool,runned,false)\
  ADD(int,port,7021)\
  ADD(bool,forcebind,false)\
  ADD(bool,raw,true)\
  ADD(qap_fd_set,fdsClients,$)\
  ADD(SOCKET,highclient,NULL)\
  //---
  void operator=(GatewayServer&&ref){oper_set(std::move(ref));}
  GatewayServer(GatewayServer&&ref){DoReset();oper_set(std::move(ref));}
  void oper_set(GatewayServer&&ref)
  {
    #define F(TYPE,NAME,VALUE)this->NAME=std::move(ref.NAME);
    DEF_PRO_VARIABLE(F);
    #undef F
  }
  //===
  #include "defprovar.inl"
  //===
public:
  GatewayServer(){Init();}
  ~GatewayServer(){Free();}
public:
  class TCallback
  {
  public:
    /****************************************************************************************************/
    /*запрещено вызывать: Free,Stop,recv_one(client),recv_all(),kick_one(client),kick_all()          */
    /****************************************************************************************************/
    virtual void OnRecvPack(Socket&client,std::string&data){
      QapNoWay();
    }//приём данных от клиента
    virtual void OnAddClient(Socket&client){
      QapNoWay();
    }//подключение нового клиента
    /****************************************************************************************************/
    /*запрещено вызывать: всё                   */
    /****************************************************************************************************/
    virtual void OnDeleteClient(Socket&client){
      QapNoWay();
    }//отключение клиента
  };
public:
  void Init()
  {
    DoReset();
  }
  void Free()
  {
    TCallback cb;
    stop_tcp(cb);
  }
public:
  void start_tcp()
  {
    if(!port||runned)return;
    Socket::init_wsa();
    listener=std::move(Socket());
    listener.sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(listener.sock==INVALID_SOCKET)return;
    listener.sock_addr.sin_family=AF_INET;
    listener.sock_addr.sin_port=htons(port);//не забываем о сетевом порядке!!!
    listener.sock_addr.sin_addr.s_addr=0;
    if(bind(listener.sock,(sockaddr*)&listener.sock_addr,sizeof(listener.sock_addr))==SOCKET_ERROR)
    {
      #ifdef WIN32
        if(!forcebind)
      #endif
      return;
      #ifdef WIN32
        listener.sock_addr.sin_port=0;//любой 
        if(bind(listener.sock,(sockaddr*)&listener.sock_addr,sizeof(listener.sock_addr))==SOCKET_ERROR)return;
        char info[256];
        sockaddr_in*local=(sockaddr_in*)(info+sizeof(CSADDR_INFO));
        sockaddr_in*remote=(sockaddr_in*)(info+sizeof(CSADDR_INFO)+sizeof(sockaddr_in));
        ZeroMemory(info,sizeof(info));
        ((CSADDR_INFO*)info)->LocalAddr.lpSockaddr=(sockaddr*)local;
        ((CSADDR_INFO*)info)->LocalAddr.iSockaddrLength=sizeof(*local);
        ((CSADDR_INFO*)info)->RemoteAddr.lpSockaddr=(sockaddr*)remote;
        ((CSADDR_INFO*)info)->RemoteAddr.iSockaddrLength=sizeof(*remote);
        int size=sizeof(info);
        int ret=getsockopt(listener.sock,SOL_SOCKET,SO_BSP_STATE,(char*)&info,&size);
        if(ret==SOCKET_ERROR)return;
        listener.sock_addr.sin_port=((sockaddr_in*)((CSADDR_INFO*)info)->LocalAddr.lpSockaddr)->sin_port;
      #endif
    }
    if(listen(listener.sock,SOMAXCONN)==SOCKET_ERROR)return;
    listener.setnoblock(true);
    listener.connected=1;
    runned=1;
  }
  void stop_tcp(TCallback&callback)
  {
    listener=std::move(Socket());
    kick_all(callback);
    runned=false;
  }
  Socket*getClientBySock(SOCKET sock)
  {
    for(int i=0;i<clients.size();i++)
    {
      if(clients[i].sock==sock)
      {
        return &clients[i];
      }
    }
    return nullptr;
  }
public:
  void update_tcp(TCallback&callback)
  {
    accept_all(callback);
    recv_all(callback);
    clean_all(callback);
  }
public:
  void accept_all(TCallback&callback,int n=32)
  {
    static int max_in_a_row=0;
    for(int i=1;i<=n;i++)
    {
      bool ok=accept_one(callback);
      if(!ok)return;
      max_in_a_row=std::max(max_in_a_row,i);
    }
    static int nice=0;nice++;
    int gg=1;
  }
  bool accept_one(TCallback&callback)//принять входящих(редко)
  {
    if(!runned||!listener.connected)return false;
    qap_fd_set fds_src;
    fds_src.set(listener.sock);
    timeval tval={0,0};
    qap_fd_set fds_r=fds_src,fds_e=fds_src;
    int ret=select(listener.sock+1,&fds_r.mem(),NULL,&fds_e.mem(),&tval);
    if(ret==SOCKET_ERROR)return false;//произошла ошибка select
    if(!ret)return false;//нет данных
    if(FD_ISSET(listener.sock,&fds_r.mem()))
    { 
      Socket incom;
      int addr_size=sizeof(incom.sock_addr);
      incom.sock=accept(listener.sock,(sockaddr*)&incom.sock_addr,&addr_size);
      if(incom.sock==SOCKET_ERROR)
      {
        auto err=WSAGetLastError();
        if(err==WSAEWOULDBLOCK)
        {
          return false;
        }
        QapDebugMsg("accept fail: err_code = "+IToS(err));
        listener.Free();
        return false;
      }
      incom.connected=true;
      highclient=incom.sock;
      auto&nc=qap_add_back(clients);
      nc=std::move(incom);
      fdsClients.set(nc.sock);
      if(!FD_ISSET(nc.sock,&fdsClients.mem())){
        int fail=1;
      }
      callback.OnAddClient(nc);
    }
    if(FD_ISSET(listener.sock,&fds_e.mem()))
    {
      listener.Free();
      return false;
    }
    return true;
  }
public:
  void send_one(const std::string&message,Socket*client)//отправка данных клиенту
  {
    if(client->deaded)
    {
      QapDebugMsg("first pass");
      return;
    }
    if(!runned)return;
    if(!client||!client->connected)return;
    if(raw)
    {
      if(client->send_raw(message)!=SOCKET_ERROR)return;
    }
    if(!raw)
    {
      if(client->send(message)!=SOCKET_ERROR)return;
    }
    client->deaded=true;
    //kick_one(client);
  }
  void send_all(const std::string&message)//отправка данных всем клиентам
  {
    if(!runned)return;
    string msg;
    for(int i=0;i<clients.size();++i)
    {
      auto&client=clients[i];
      if(!client.connected)continue;
      if(client.deaded)continue;
      if(raw)
      {
        msg=message;
        if(client.send_raw(msg)==SOCKET_ERROR)
        {
          client.deaded=true;
          //kick_one(client);
          //--i;
        }
        return;
      }
      if(!raw)
      {
        if(client.send(message)==SOCKET_ERROR)
        {
          client.deaded=true;
          //kick_one(client);
          //--i;
        }
        return;
      }
      int end_loop=1;
    }
    int gg=1;
  }
  void recv_all(TCallback&callback)
  {
    if(!runned||clients.empty())return;
    timeval tval={0,0};
    int ret=0;
    for(;;)
    {
      auto fds_r=fdsClients,fds_e=fdsClients;
      QapClock clock;clock.Start();
      int ret=select(highclient+1,&fds_r.mem(),NULL,&fds_e.mem(),&tval);
      real ms=clock.MS();
      int gg=1;
      if(!ret||(ret==SOCKET_ERROR))return;//нет данных или произошла ошибка select
      for(int i=0;i<clients.size();i++)
      {
        auto&client=clients[i];
        if(!client.connected)continue;
        if(client.deaded)continue;
        if(!FD_ISSET(clients[i].sock,&fds_r.mem()))continue;
        if(client.recv_raw()<1)
        {
          //kick_one(client);
          client.deaded=true;
          break;
          //return;
        }
        string msg;
        if(raw)
        {
          msg=client.ibuffer;
          client.ibuffer.clear();
          callback.OnRecvPack(client,msg);
        }
        if(!raw)
        {
          for(;;)
          {
            bool flag=client.unpack(msg)!=-1;
            if(!flag)break;
            callback.OnRecvPack(client,msg); 
          }
        }
      }
      for(int i=0;i<clients.size();i++)
      {
        auto&client=clients[i];
        bool err=FD_ISSET(client.sock,&fds_e.mem());
        if(!err)continue;
        client.deaded=true;
      }
      clean_all(callback);
    }
  }
  void clean_all(TCallback&callback)
  {
    for(int i=0;i<clients.size();i++)
    {
      auto&ex=clients[i];
      if(!ex.deaded)continue;
      callback.OnDeleteClient(ex);
      fdsClients.clr(ex.sock);
      //FD_CLR(client.sock,&fdsClients);
    }
    qap_clean_if_deaded(clients);
  }
  void kick_all(TCallback&callback)//отключить всех клиентов
  {
    for(int i=0;i<clients.size();i++)
    {
      auto&client=clients[i];
      if(!client.deaded)continue;
      callback.OnDeleteClient(client);
    }
    clients.clear();
    fdsClients.zero();
  }
public:
  Socket&operator[](unsigned num){return clients[num];}
  unsigned count(){return clients.size();}
  unsigned size(){return clients.size();}
  operator bool(){return runned;}
public:
};