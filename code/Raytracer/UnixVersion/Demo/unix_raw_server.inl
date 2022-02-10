#ifndef PREPROC
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

#include <thread>
#include <netinet/tcp.h>
#endif //PREPROC
using namespace std;

struct t_serv
{
  sockaddr_in server_addr,client_addr;
  socklen_t clientlen = sizeof(sockaddr_in);
  int option, port, reuse;
  int server=0;
  vector<int> arr;
  bool need_init=true;
  void init()
  {
    need_init=false;
    // setup default arguments
    port = p_urs_port?*p_urs_port:45631;

    QapUserInfo("port = "+IToS(port));
    
      // setup socket address structure
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

      // create socket
    server = socket(PF_INET,SOCK_STREAM,0);
    if (!server) {
        perror("socket");
        exit(-1);
    }

      // set socket to immediately reuse port when the application closes
    reuse = 1;
    if (setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("setsockopt::SO_REUSEADDR");
        exit(-1);
    }
    int flag = 1;
    if (setsockopt(server, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(flag)) < 0) {
        perror("setsockopt::TCP_NODELAY");
        exit(-1);
    }

      // call bind to associate the socket with our local address and
      // port
    if (bind(server,(const struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("bind");
        exit(-1);
    }

      // convert the socket to listen for incoming connections
    if (listen(server,SOMAXCONN) < 0) {
        perror("listen");
        exit(-1);
    }
    for(;;)
    {
      int client=accept(server,(struct sockaddr *)&client_addr,&clientlen);
      if(client<=0)break;
      qap_add_back(arr)=client;
      QapUserInfo("client added: "+IToS(client));
    }
    QapUserInfo("close(server);");
    close(server);
  }
  static t_serv&get(){static t_serv serv;return serv;}
  static int sendall(int s,const char*buf,int len,int flags)
  {
    int n=0;int pos=0;
    for(;pos<len;pos+=n)
    {
      n=send(s,buf+pos,len-pos,flags);
      if(n==-1){
        auto tmp=errno;
        string err=strerror(tmp);
        QapUserInfo("socket::send("+IToS(s)+",...) return "+IToS(n)+"; // errno = "+IToS(tmp)+"; // "+err);
        return -1;
      }
    }
    return pos;
  }
  bool send_one(int client,const string&s){
    int n=sendall(client,s.c_str(),s.size(),MSG_NOSIGNAL);
    return n==s.size();
  }
  void send_rec(const string&s){
    for(int i=0;i<arr.size();i++){
      bool ok=send_one(arr[i],s);
      if(!ok){
        QapUserInfo("client del: "+IToS(arr[i]));
        arr[i]=-1;
      }
    }
    clean_if(arr,[](int ex){return ex<0;});
  };
  static void main(){
    t_serv::get().init();
  }
};
void on_start()
{
  QapUserInfo("unix_raw_server v5");
  std::thread t(t_serv::main);
  t.detach();
}

void on_write_rec(const string&s)
{
  static auto&serv=t_serv::get();
  if(serv.need_init)return;
  serv.send_rec(s);
}