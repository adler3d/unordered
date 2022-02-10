class Socket{
public:
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(SOCKET,sock,SOCKET(SOCKET_ERROR))\
  ADD(sockaddr_in,sock_addr,get_zero_sockaddr_in())\
  ADD(string,ibuffer,"")\
  ADD(string,rbuffer,"")\
  ADD(bool,connected,false)\
  ADD(void*,userdata,nullptr)\
  ADD(int,reserved,64*1024)\
  ADD(bool,need_kick,false)\
  //===
  #include "defprovar.inl"
  //===
public:
  std::string name()//��������� ������������� ������ ������ ip:port
  {
    char buff[16];
    return string(inet_ntoa(sock_addr.sin_addr))+":"+string(itoa(ntohs(sock_addr.sin_port),buff,10));
  }
  static sockaddr_in get_zero_sockaddr_in(){sockaddr_in tmp;ZeroMemory(&tmp,sizeof(tmp));return tmp;}
  void Init(){DoReset();}
  void Free()
  {
    connected=0;
    if(sock!=SOCKET_ERROR){closesocket(sock);sock=SOCKET_ERROR;}
    ZeroMemory(&sock_addr,sizeof(sock_addr));
    ibuffer.clear();
    rbuffer.clear();
    userdata=NULL;
  }
  Socket(const Socket&){QapNoWay();}
  void operator=(Socket&&ref){oper_set(std::move(ref));}
  Socket(Socket&&ref){oper_set(std::move(ref));}
  void oper_set(Socket&&ref)
  {
    QapAssert(!ref.userdata);
    Free();
    Socket tmp;
    #define F(NAME)std::swap(this->NAME,ref.NAME);
    F(sock     );
    F(sock_addr);
    F(ibuffer  );
    F(rbuffer  );
    F(connected);
    F(userdata );
    F(reserved );
    F(need_kick);
    #undef F
  }
  Socket(){Init();}
 ~Socket(){Free();}
public:
  #ifdef WIN32
    typedef int t_sock_len;
  #else
    typedef socklen_t t_sock_len;
  #endif
public:
  int rcvbuf()
  {
    int buffsize=0;
    t_sock_len size=sizeof(buffsize);
    getsockopt(sock,SOL_SOCKET,SO_RCVBUF,(char*)&buffsize,&size);
    return buffsize;
  }
  void rcvbuf(int newsize)
  {
    int size=sizeof(newsize);
    setsockopt(sock,SOL_SOCKET,SO_RCVBUF,(char*)&newsize,size);
  }
  int sndbuf()
  {
    int buffsize=0;
    t_sock_len size=sizeof(buffsize);
    getsockopt(sock,SOL_SOCKET,SO_SNDBUF,(char*)&buffsize,&size);
    return buffsize;
  }
  void sndbuf(int newsize)
  {
    int size=sizeof(newsize);
    setsockopt(sock,SOL_SOCKET,SO_SNDBUF,(char*)&newsize,size);
  }
  void setbuf(int newsize){rcvbuf(newsize);sndbuf(newsize);reserved=newsize;rbuffer.reserve(newsize);}
  /************************************************************************/
  /* ����������� source �������� ��������� � ��������                    */
  /************************************************************************/
  inline void pack(std::string&dest,const std::string&source)
  {
    int hdr=source.size();
    dest.clear();
    dest.append((char*)&hdr,sizeof(int));
    dest.append(source);
    if(reserved<hdr+4)
    reserved=hdr+4;
  }
  /************************************************************************/
  /* ������������� �� �������� ������ ������ dest                       */
  /************************************************************************/
  inline int unpack(std::string&dest)
  {
    int hdr=header_read();
    if(hdr==-1)return hdr;
    if(ibuffer.size()>=hdr)
    {
      dest=ibuffer.substr(0,hdr);
      ibuffer=ibuffer.substr(hdr);
    }else{
      header_write(hdr);
      hdr=-1;
    }
    return hdr;
  }
  /************************************************************************/
  /* ���������� ������������� ������ �� TCP                              */
  /************************************************************************/
  inline void set_auto_flush(bool f)
  {
    BOOL flag=f;
    setsockopt(sock,IPPROTO_TCP,TCP_NODELAY,(char*)&flag,sizeof(flag));
    //flag=false;
    //setsockopt(sock,IPPROTO_TCP,TCP_NODELAY,(char*)&flag,sizeof(flag));
  }
  inline int send_raw(const std::string&source)
  {
    int ret=0;
    int pos=0;
    int size=source.size();
    auto*pSource=source.c_str();
    for(;;)
    {
      ret=::send(sock,&pSource[pos],size,0);
      if(ret==SOCKET_ERROR)break;
      pos+=ret;
      size-=ret;
      if(!size)break;
    }
    return ret;
  }
  /************************************************************************/
  /* ���������� ����������� ������ �� TCP                               */
  /************************************************************************/
  inline int send(const std::string&source)
  {
    pack(rbuffer,source);//�������� ������ ����������
    return send_raw(rbuffer);//�������� ������
  }
  /************************************************************************/
  /* ���������� ������������� ������ �� UDP(������������ ��������)  */
  /************************************************************************/
  inline int sendto_raw(std::string&source,const sockaddr_in&to)
  {
    int ret=0;
    for(;;)
    {
      source=source.substr(ret);
      ret=::sendto(sock,source.c_str(),source.size(),0,(sockaddr*)&to,sizeof(sockaddr_in));
      if(ret==SOCKET_ERROR)break;
      if(ret==source.size())break;
    }
    return ret;
  }
  /************************************************************************/
  /* ���������� ����������� ������ �� UDP                               */
  /************************************************************************/
  inline int sendto(const std::string&source,const sockaddr_in&to)
  {
    pack(rbuffer,source);//�������� ������ ����������
    return sendto_raw(rbuffer,to);//�������� ������
  }
  /************************************************************************/
  /* ��������� ��������� � ��������                                     */
  /************************************************************************/
  inline int header_read()
  {
    int hdr=-1;//������ ����� ������������
    if(ibuffer.size()>=4)
    { 
      hdr=*(int*)ibuffer.data();//������ ������� �����
      if(rbuffer.capacity()<hdr+4)
      {
        reserved=hdr+4;
        rbuffer.reserve(reserved);
      }
      ibuffer=ibuffer.substr(4);
    }
    return hdr;
  }
  /************************************************************************/
  /* �������� � ������ ��������� � ��������                             */
  /************************************************************************/
  inline void  header_write(int hdr)
  {
    ibuffer.insert(0,(char*)&hdr,4);
  }
  /************************************************************************/
  /* �������� ������������� ������ �� TCP                               */
  /************************************************************************/
  inline int recv_raw()
  {
    if(rbuffer.capacity()<reserved)
    rbuffer.reserve(reserved);
    char*pbuff=const_cast<char*>(rbuffer.data());
    int ret=::recv(sock,pbuff,rbuffer.capacity(),0);
    #ifdef WIN32
      if((ret==SOCKET_ERROR)&&(WSAGetLastError()==WSAEMSGSIZE))
      {
        ret=rbuffer.capacity();
      }else
    #endif
    if(!ret||(ret==SOCKET_ERROR))
    {
      return ret;
    }
    ibuffer.append(pbuff,ret);//������������� ����������� ������
    return ret;
  }
  /************************************************************************/
  /* �������� ������������� ������ �� TCP                               */
  /************************************************************************/
  inline int Socket::recv_raw_ex()
  {
    if(rbuffer.capacity()<reserved)
    {
      rbuffer.reserve(reserved);
    }
    char*pbuff=const_cast<char*>(rbuffer.data());
    int ret=::recv(sock,pbuff,rbuffer.capacity(),0);
    #ifdef WIN32
    {
      if((SOCKET_ERROR==ret)&&(WSAEMSGSIZE==WSAGetLastError()))
      {
        ret=rbuffer.capacity();
        ibuffer.append(pbuff,ret);
        return ret;
      }
    }
    #endif
    if(!ret||(SOCKET_ERROR==ret))
    {
      ibuffer.append(pbuff,ret);
      return ret;
    }
  }
  /************************************************************************/
  /* �������� ������������� ������ �� UDP                               */
  /************************************************************************/
  inline int recvfrom_raw(sockaddr_in&from)
  {
    if(rbuffer.capacity()<reserved)
    rbuffer.reserve(reserved);
    char*pbuff=const_cast<char*>(rbuffer.data());
    t_sock_len fromlen=sizeof(from);
    int ret=::recvfrom(sock,pbuff,rbuffer.capacity(),0,(sockaddr*)&from,&fromlen);
    #ifdef WIN32
      if((ret==SOCKET_ERROR)&&(WSAGetLastError()==WSAEMSGSIZE))
      {
        ret=rbuffer.capacity();
      }else
    #endif
    if(!ret||(ret==SOCKET_ERROR))
    {
      return ret;
    }
    ibuffer.append(pbuff,ret);//������������� ����������� ������
    return ret;
  }
  /************************************************************************/
  /* ������������� ip � ������ ������                                   */
  /************************************************************************/
  static void init_wsa()
  {
    WSADATA wsaData;int iResult=WSAStartup(MAKEWORD(2,2),&wsaData);if(iResult==NO_ERROR)return;
    QapDebugMsg("WSAStartup function failed with error: "+IToS(iResult));
  }
  int setaddr(const std::string&addr)
  {
    #ifdef WIN32
      ADDRINFO net_hint,*net_result=NULL;
      ZeroMemory(&net_hint,sizeof(net_hint));
      net_hint.ai_family=AF_INET;
      net_hint.ai_protocol=IPPROTO_TCP;
      auto err_code=getaddrinfo(addr.c_str(),NULL,&net_hint,&net_result);
      if(err_code==WSANOTINITIALISED)
      {
        init_wsa();
        err_code=getaddrinfo(addr.c_str(),NULL,&net_hint,&net_result);
      }
      if(err_code==SOCKET_ERROR)return -1;
      if(!net_result)return -1;
      sock_addr=*(sockaddr_in*)net_result->ai_addr;
      freeaddrinfo(net_result);
      return 0;
    #else
      HOSTENT*hst;
      //�������������� IP -������. SERVERADDR - ����� �������
      if(inet_addr(addr.c_str())!=INADDR_NONE)    
        sock_addr.sin_addr.s_addr=inet_addr(addr.c_str());
      else//������������ ������� ��������� IP-������ �� ��������� �����
        if(hst=gethostbyname(addr.c_str()))
        ((unsigned long*)&sock_addr.sin_addr)[0]=
        ((unsigned long**)hst->h_addr_list)[0][0];
      else
      {
        return 1;
      }
      return 0;
    #endif
  }
  /************************************************************************/
  /* ������������� ������������� �����                                    */
  /************************************************************************/
  int setnoblock(bool on)
  {
    #ifdef WIN32
      u_long cmd=on;
      if(ioctlsocket(sock,FIONBIO,&cmd))return -1;
      return 0;
    #else
      int f;
      if((f=fcntl(sock,F_GETFL,0))==-1)return -1;
      if(on)
        f|=O_NONBLOCK;
      else 
        f&=~O_NONBLOCK;
      if(fcntl(sock,F_SETFL,f)==-1)return -1;
      return 0;
    #endif
  }
};

#define ADD_EVENT(MSG)//printf("%s\n",MSG);
class DownLoader{
public:
  void operator=(DownLoader&&ref){oper_set(std::move(ref));}
  DownLoader(DownLoader&&ref){DoReset();oper_set(std::move(ref));}
  void oper_set(DownLoader&&ref)
  {
    stop();
    #define F(NAME)std::swap(this->NAME,ref.NAME);
    F(shost  );
    F(active );
    F(method );
    F(webhost);
    F(port   );
    F(webpath);
    F(content);
    #undef F
  }
  // ��������� ����������
  DownLoader(const DownLoader&rhs){QapNoWay();}
  void operator=(const DownLoader&rhs){QapNoWay();}
public:
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(Socket,shost,$)\
  ADD(bool,active,false)\
  ADD(string,method,"GET")\
  ADD(string,webhost,"localhost")\
  ADD(int,port,80)\
  ADD(string,webpath,"/")\
  ADD(string,content,"")\
  //===
  #include "defprovar.inl"
  //===
public:
  DownLoader(){DoReset();}
public:
  string&get_data(){return shost.ibuffer;}
  string get_body()
  {
    const Extractor::Gripper tag_http("\r\n\r\n","");Extractor e(GetContent(get_data()));return e.extract(tag_http);
  }
  const string&get_data()const {return shost.ibuffer;}
  bool start(){
    QapAssert(port>=0);
    shost.Init();
    ADD_EVENT("start");Sleep(delay);
    if(shost.setaddr(webhost))return 0;
    shost.sock_addr.sin_port = htons(port);
    shost.sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(shost.sock == INVALID_SOCKET)return 0;
    if(shost.setnoblock(1))return 0;
    connect(shost.sock, (sockaddr *)&shost.sock_addr, sizeof(shost.sock_addr)); // �������� ���������� ����������
    if(shost.setnoblock(0))return 0;
    active = 1;
    return true;
  }
  static const int delay=0;//16;
  bool update(){
    if (!active) return active;

    fd_set fds_src;
    FD_ZERO(&fds_src);
    FD_SET(shost.sock,&fds_src);
    fd_set fds_r=fds_src, fds_w=fds_src, fds_e=fds_src;
    if(shost.connected)FD_ZERO(&fds_w);
    timeval tv={0,0};
    int ret = ::select(shost.sock+1,&fds_r,&fds_w,&fds_e,&tv);
    if(ret){ // ���� �������
      if(FD_ISSET(shost.sock,&fds_r)){ // ������ ������ || ���������� �������
        int ret=shost.recv_raw();
        if(ret<1){ // ���������� �������, ������ ��������
          active = 0;
          ADD_EVENT("close");Sleep(delay);
          return active;
        }
      }
      if(FD_ISSET(shost.sock,&fds_w)){ // ���������� �����������
        shost.connected=1;
        shost.set_auto_flush(true);
        Sleep(delay);
        QapAssert(!qap_find_str(split("POST,GET",","),method).empty());
        string req(
          method+" "+webpath+" HTTP/1.1\r\n"
          "Host: "+webhost+"\r\n"
          "Accept: text/html;q=0.9,*/*;q=0.8\r\n"
          "Content-Length: "+IToS(content.size())+"\r\n"
          "Content-Type: application/x-www-form-urlencoded\r\n"
          "\r\n"
        );
        if(shost.send_raw(req) == SOCKET_ERROR){// ������ ��������, ������ �����������
          active = 0;
          ADD_EVENT("send error");Sleep(delay);
          return active;
        }else if(0){
          shutdown(shost.sock,SD_SEND);
          ADD_EVENT("shutdown");Sleep(delay);
        }
        Sleep(delay);
        if(shost.send_raw(content) == SOCKET_ERROR){// ������ ��������, ������ �����������
          active = 0;
          ADD_EVENT("send error");Sleep(delay);
          return active;
        }else if(0){
          shutdown(shost.sock,SD_SEND);
          ADD_EVENT("shutdown");Sleep(delay);
        }
      }
      if(FD_ISSET(shost.sock,&fds_e)){ // ���������� ��������, ������ �����������
        active = 0;
        ADD_EVENT("fail");Sleep(delay);
        return active;
      }
    }
    return 1;
  }
  static string get_first_part(const string&query,char needle){auto p=query.find(needle);if(p==std::string::npos)return query;return query.substr(0,p);}
  static string get_second_part(const string&query,char needle){auto p=query.find(needle);if(p==std::string::npos)return "";return query.substr(p+1);}
  static string get_first_part(const string&query,const string&needle){auto p=query.find(needle);if(p==std::string::npos)return query;return query.substr(0,p);}
  static string get_second_part(const string&query,const string&needle){auto p=query.find(needle);if(p==std::string::npos)return "";return query.substr(p+needle.size());}
  static string get_param_value(const vector<string>&params,const string&param){
    vector<string> p;for(int i=0;i<params.size();i++){qap_add_back(p)=get_first_part(params[i],'=');}
    auto ids=qap_find_str(p,param);
    if(ids.empty())return "";
    return get_second_part(params[ids[0]],'=');
  }
  static char HToC(const string&str){size_t val;sscanf_s(str.c_str(),"%02x",&val); return char(val);}
  static string urldecode(const string&s)
  {
    auto arr=split(s,"%");
    string out="";
    for(int i=0;i<arr.size();i++){
      auto&ex=arr[i];
      if(i==0){out+=ex;continue;}
      QapAssert(ex.size()>=2);
      out.push_back(char(HToC(ex.substr(0,2))));
      out+=ex.substr(2);
    }
    return out;
  }
  static string get_decoded_param_value(const vector<string>&params,const string&param){
    return urldecode(get_param_value(params,param));
  }
  static string get_query(const string&webpath){return get_second_part(webpath,'?');}
  static bool params_defined(const vector<string>&params,const string&list)
  {
    vector<string> p;for(int i=0;i<params.size();i++){qap_add_back(p)=get_first_part(params[i],'=');}
    auto arr=split(list,",");
    for(int i=0;i<arr.size();i++){if(qap_find_str(p,arr[i]).empty())return false;}
    return true;
  }
  static string header_get_value(const string&header,const string&param)
  {
    auto arr=split(header,"\r\n");
    for(int i=1;i<arr.size();i++)
    {
      auto&ex=arr[i];
      if(param!=get_first_part(ex,':'))continue;
      return join(split(get_second_part(ex,':')," "),"");
    }
    return "";
  }
  static bool is_chunked(const string&header)
  {
    //Extractor::Gripper tag_te("\n","chunked");
    static auto te=LowerStr("Transfer-Encoding");
    string low_header=LowerStr(header);
    auto v=header_get_value(low_header,te);
    return v=="chunked";
  }
  static bool HToI(const string&str,int&val){sscanf_s(str.c_str(),"0x%08X",&val); return true;}
  static int HToI(const string&str){int val;sscanf_s(str.c_str(),"0x%08X",&val); return val;}
  class Extractor{
  public:
    class Gripper{
    public:
      string before;
      string after;
      Gripper(const string&before,const string&after):before(before),after(after){}
      string grip(const string&source)const{return before+source+after;}
    };
  public:
    int pos;
    string source;
    Extractor(const string&source):pos(0),source(source){}
    static inline string ScanParam(const string&Before,const string&Where,const string&After,int&Pos)
    {
      int E=Where.find(Before, Pos);
      if(E==-1){Pos=-1; return "";}
      Pos=Where.find(Before,Pos)+Before.length();
      E=After.empty()?Where.size():Where.find(After,Pos);
      if(E==-1){Pos=-1; return "";}
      string result; result.assign(Where,Pos,E-Pos);
      return result;
    }
    string extract(const Gripper&ref){
      string s=ScanParam(ref.before,source,ref.after,pos);
      if(pos>=0)pos+=s.size()+ref.after.size();
      return s;
    }
    template<class TYPE>
    void extract_all(TYPE&visitor,const Gripper&ref)
    {
      while(pos>=0){
        string s=extract(ref);
        if(pos<0)break;
        visitor.accept(s);
      }
    }
    operator bool(){return pos>=0;}
  };
  static string GetContent(const string&data)
  {
    const Extractor::Gripper tag_http("HTTP/1.1 ","\r\n\r\n");
    const Extractor::Gripper tag_te("transfer-encoding: ","\r\n");
    const Extractor::Gripper tag_line("\r\n","\r\n");
    Extractor e(data);
    string http=e.extract(tag_http);
    if(http.empty())return data;
    http+="\r\n\r\n";
    string http_lowstr=LowerStr(http);
    if(!is_chunked(http))return data;
    e.pos-=tag_line.before.size();
    string result=http;
    while(e){
      string bytes=e.extract(tag_line);
      if(bytes.empty())break;
      int count=HToI("0x"+bytes);
      result.append(data,e.pos,count);
      e.pos+=count;
      if(!count)break;
    }
    return result;
  }
  void stop(){
    ADD_EVENT("stop");Sleep(delay);
    shost.Free();
  }
  static DownLoader LoadContent(const string&method,const string&webhost,int port,const string&webpath,const string&content)
  {
    DownLoader DL;
    DL.method=method;
    DL.webhost=webhost;
    DL.port=port;
    DL.webpath=webpath;
    DL.content=content;
    DL.start();
    Sleep(16);
    while(DL.update()){
      Sleep(16);
      //cout<<"size = "<<DL.data.size()<<endl;
    }
    return DL;
  }
  void start_ex(const string&url){set_host_port_path(url);start();}
  void set_host_port_path(const string&url)
  {
    string&host=webhost;string&path=webpath;string port="80";
    auto a=get_first_part(url,"://");
    host=(a=="http")?get_second_part(url,"://"):url;
    if(host.find('/')!=string::npos)
    {
      path="/"+get_second_part(host,'/');
      host=get_first_part(host,'/');
    }
    if(host.find(':')!=string::npos)
    {
      port=get_second_part(host,':');
      host=get_first_part(host,':');
    }
    bool host_is_ok=host.find(':')==string::npos&&host.find('/')==string::npos;
    QapAssert(host_is_ok);
    if(!host_is_ok)return;
    this->port=SToI(port);
  }
  static DownLoader LoadUrl(const string&method,const string&url,const string&content)
  {
    DownLoader DL;DL.method=method;DL.content=content;DL.set_host_port_path(url);
    DL.start();while(DL.update())Sleep(16);
    return DL;
  }
};