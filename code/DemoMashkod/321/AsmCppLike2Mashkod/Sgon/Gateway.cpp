#include "Gateway.h"

using namespace std;

struct GWSSResponse // ответ на сканирование серверов
{
	int			ver;		// версия 100 => 1.0
	unsigned	sid;		// идентификатор сервера
	sockaddr_in	sock_addr;	// адрес сокета
};

static unsigned capture_tag(string src, string &dst, string tag_op, string tag_cl); // return offset after read

void GatewayServer::start_tcp()
{
	if(!port || runned)return;

	// TCP socket
	if(listener){delete listener; listener=NULL;}
	listener=new Socket;
	listener->sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(listener->sock == INVALID_SOCKET)return;
	listener->sock_addr.sin_family		= AF_INET;
	listener->sock_addr.sin_port		= htons(port); // не забываем о сетевом порядке!!!
	listener->sock_addr.sin_addr.s_addr	= 0;
	if( bind(listener->sock, (sockaddr *)&listener->sock_addr, sizeof(listener->sock_addr)) == SOCKET_ERROR )
	{
		#ifdef WIN32
		if(!forcebind)
		#endif
			return;
		#ifdef WIN32
		listener->sock_addr.sin_port=0;	// любой 
		if( bind(listener->sock, (sockaddr *)&listener->sock_addr, sizeof(listener->sock_addr)) == SOCKET_ERROR )
			return;
		char info[256];
		sockaddr_in *local=(sockaddr_in*)(info+sizeof(CSADDR_INFO));
		sockaddr_in *remote=(sockaddr_in*)(info+sizeof(CSADDR_INFO)+sizeof(sockaddr_in));
		ZeroMemory(info,sizeof(info));
		((CSADDR_INFO*)info)->LocalAddr.lpSockaddr = (sockaddr*)local;
		((CSADDR_INFO*)info)->LocalAddr.iSockaddrLength = sizeof(*local);
		((CSADDR_INFO*)info)->RemoteAddr.lpSockaddr = (sockaddr*)remote;
		((CSADDR_INFO*)info)->RemoteAddr.iSockaddrLength = sizeof(*remote);
		int size = sizeof(info);
		int ret=getsockopt(listener->sock,SOL_SOCKET,SO_BSP_STATE,(char*)&info,&size);
		if(ret == SOCKET_ERROR){
			return;
		}else{
			listener->sock_addr.sin_port = ((sockaddr_in*)((CSADDR_INFO*)info)->LocalAddr.lpSockaddr)->sin_port;
		}
		#endif
	}
	if( listen(listener->sock, 1) == SOCKET_ERROR ) return;
	listener->connected=1;
	runned=1;
}

void GatewayServer::start_udp()
{
	// UDP socket
	if(detector){delete detector; detector=NULL;}
	detector=new Socket;
	detector->sock = socket(AF_INET,SOCK_DGRAM,0);
	detector->sock_addr.sin_family = AF_INET;
	detector->sock_addr.sin_port = htons(port);	// не забываем о сетевом порядке!!!
	detector->sock_addr.sin_addr.s_addr	= htonl(INADDR_ANY);		// означает любой адрес
	u_long brcst = 1;												// Set socket to allow broadcast
	if (setsockopt(detector->sock, SOL_SOCKET, SO_BROADCAST, (char *) &brcst, sizeof(brcst)) == SOCKET_ERROR)return;
	u_long yes = 1;													// переиспользование адреса сокета
	if (setsockopt(detector->sock, SOL_SOCKET, SO_REUSEADDR, (char*)&yes, sizeof(yes) ) == SOCKET_ERROR)return;
	if( bind( detector->sock, (sockaddr*)&detector->sock_addr, sizeof(detector->sock_addr)) == SOCKET_ERROR )return;
}

void GatewayServer::stop_tcp()
{
	if(listener){delete listener; listener=nullptr;}	// TCP socket
	kick_all();
	runned=0;
}

void GatewayServer::stop_udp()
{
	if(detector){delete detector; detector=nullptr;}	// UDP socket
}

Socket * GatewayServer::getClientBySock( SOCKET sock )
{
	for(int i=0;i<clients.size();i++)
		if(clients[i]->sock == sock)
			return clients[i];
	return NULL;
}

void GatewayServer::accept_all()
{
	if(!runned || !listener || !listener->connected)return;
	fd_set fds_src;
	FD_ZERO(&fds_src);
	FD_SET(listener->sock,&fds_src);
	timeval tval = {0,0};

	fd_set fds_r=fds_src, fds_e=fds_src;
	int ret	= select( listener->sock+1, &fds_r, NULL, &fds_e, &tval );
	if(ret == SOCKET_ERROR) return; // произошла ошибка select
	if(!ret) return;				// нет данных
	if(FD_ISSET(listener->sock,&fds_r)){ 
		/*
		* If listen has been called and a connection is pending, accept will succeed.
		* Data is available for reading (includes OOB data if SO_OOBINLINE is enabled).
		* Connection has been closed/reset/terminated.
		*/
		Socket			*incom		= new Socket;
		#ifdef WIN32
		int				addr_size	= sizeof(incom->sock_addr);
		#else
		socklen_t			addr_size	= sizeof(incom->sock_addr);
		#endif
		incom->sock = accept(listener->sock, (sockaddr *)&incom->sock_addr, &addr_size);
		if(incom->sock == SOCKET_ERROR){
			delete incom; incom=NULL;
			delete listener; listener=NULL;
			return;
		}else{
			incom->connected=1;
			highclient=incom->sock;
			clients.push_back(incom);
			FD_SET(incom->sock,&fdsClients);
			if(callback)callback->OnAddClient(incom);
		}
	}
	if(FD_ISSET(listener->sock,&fds_e)){ 
		/*
		* If processing a connect call (nonblocking), connection attempt failed.
		* OOB data is available for reading (only if SO_OOBINLINE is disabled).
		*/
		delete listener; listener=NULL;
		return;			
	}
}

void GatewayServer::send_one( const std::string &message, Socket* client )
{
	if(!runned)return;

	if(!client || !client->connected)return;

	if(raw){
		string msg = message;
		if(client->send_raw(msg) == SOCKET_ERROR){
			kick_one(client);
		}
	}else{
	if(client->send(message) == SOCKET_ERROR){
		kick_one(client);
	}
}
}

void GatewayServer::send_all( const std::string &message )
{
	if(!runned)return;

	string msg;

	for(int i=0;i<clients.size();++i){
		Socket *client = clients[i];
		if(!client || !client->connected)continue;

		if(raw){
			msg = message;
			if(client->send_raw(msg) == SOCKET_ERROR){
				kick_one(client);
				--i;
			}
		}else{
		if(client->send(message) == SOCKET_ERROR){
			kick_one(client);
			--i;
		}
	}
}
}

void GatewayServer::recv_one( Socket* client )
{
	if(!runned)return;

	if(!client || !client->connected)return;

	fd_set fds_src;
	FD_ZERO(&fds_src);
	FD_SET(client->sock,&fds_src);
	timeval tval = {0,0};

	int ret=0;

	while(1){
		fd_set fds_r=fds_src, fds_e=fds_src;
		int ret	= select( client->sock+1, &fds_r, NULL, &fds_e, &tval );
		if(!ret || (ret == SOCKET_ERROR)) return;	// нет данных или произошла ошибка select
		if(FD_ISSET(client->sock,&fds_r)){ 
			/*
			* If listen has been called and a connection is pending, accept will succeed.
			* Data is available for reading (includes OOB data if SO_OOBINLINE is enabled).
			* Connection has been closed/reset/terminated.
			*/
			if(client->recv_raw()<1){
				kick_one(client);
				return;
			}

			string msg;
			if(raw){
				msg = client->ibuffer;
				client->ibuffer.clear();
				if(callback)callback->OnRecvPack(client,msg);	// передача данных на обработку
			}else{
			while(client->unpack(msg)!=-1)
				if(callback)callback->OnRecvPack(client,msg); // передача данных на обработку
			}
		}
		if(FD_ISSET(client->sock,&fds_e)){ 
			/*
			* If processing a connect call (nonblocking), connection attempt failed.
			* OOB data is available for reading (only if SO_OOBINLINE is disabled).
			*/
			kick_one(client);
			return;			
		}
	}
}

void GatewayServer::recv_all()
{
	if(!runned)return;

	timeval tval = {0,0};
	int ret=0;
	while(1){
		fd_set fds_r=fdsClients, fds_e=fdsClients;
		int ret	= select( highclient+1, &fds_r, NULL, &fds_e, &tval );
		if(!ret || (ret == SOCKET_ERROR)) return;	// нет данных или произошла ошибка select
		for(int cid=0; cid<clients.size(); cid++){
			if(clients[cid] && FD_ISSET(clients[cid]->sock,&fds_r)){ 
			/*
			* If listen has been called and a connection is pending, accept will succeed.
			* Data is available for reading (includes OOB data if SO_OOBINLINE is enabled).
			* Connection has been closed/reset/terminated.
			*/
				Socket *client = clients[cid];
				if(!client || !client->connected)continue;
				if(client->recv_raw()<1){
					kick_one(client);
					return;
				}

				string msg;
				if(raw){
					msg = client->ibuffer;
					client->ibuffer.clear();
					if(callback)callback->OnRecvPack(client,msg);	// передача данных на обработку
				}else{
				while(client->unpack(msg)!=-1)
					if(callback)callback->OnRecvPack(client,msg); // передача данных на обработку				
			}
		}
		}
		for(int cid=0; cid<clients.size(); cid++){
			if(clients[cid] && FD_ISSET(clients[cid]->sock,&fds_e)){
			/*
			* If processing a connect call (nonblocking), connection attempt failed.
			* OOB data is available for reading (only if SO_OOBINLINE is disabled).
			*/
				kick_one(clients[cid]);
				--cid;
			}
		}
	}
}

void GatewayServer::kick_one( Socket* client )
{
	for(int i=0;i<clients.size();i++)
		if(clients[i] == client){
			Socket *client=clients[i];
			if(callback)callback->OnDeleteClient(client);
			FD_CLR(client->sock,&fdsClients);
			delete clients[i]; clients[i]=NULL;
			int size = clients.size()-1;
			clients[i]=clients[size];
			clients.resize(size);
			break;
		}
}

void GatewayServer::kick_all()
{
	while(clients.size()){
		Socket *client=clients.back();
		if(callback)callback->OnDeleteClient(client);
		delete client; client=NULL;
		clients.back()=NULL;
		clients.pop_back();
	}
	FD_ZERO(&fdsClients);
}

void GatewayServer::update_lan()
{
	if(!runned || !detector || (detector->sock==SOCKET_ERROR))return;

	fd_set fds_src;
	FD_ZERO(&fds_src);
	FD_SET(detector->sock,&fds_src);
	timeval tval = {0,0};

	int ret=0;
	sockaddr_in sender_addr; // адресс отправителя
	int addr_size = sizeof(sender_addr);

	while(1){
		fd_set fds_r=fds_src, fds_e=fds_src;
		int ret	= select( detector->sock+1, &fds_r, NULL, &fds_e, &tval );
		if(!ret || (ret == SOCKET_ERROR)) return;	// нет данных или произошла ошибка select
		if(FD_ISSET(detector->sock,&fds_r)){ 
			/*
			* If listen has been called and a connection is pending, accept will succeed.
			* Data is available for reading (includes OOB data if SO_OOBINLINE is enabled).
			* Connection has been closed/reset/terminated.
			*/
			if(detector->recvfrom_raw(sender_addr)<1){
				delete detector; detector=NULL;
				return;
			}
			string msg;
			while(detector->unpack(msg)!=-1){
				/************************************************************************/
				/*                    Отправка ответа ищущему клиенту                   */
				/************************************************************************/
				if(msg=="scanning servers"){
					GWSSResponse resp;
					resp.ver=100;
					resp.sid=sid;
					resp.sock_addr=listener->sock_addr;

					detector->sendto(string((char*)&resp,sizeof(resp)),sender_addr);
				}
			}
		}
		if(FD_ISSET(detector->sock,&fds_e)){ 
			/*
			* If processing a connect call (nonblocking), connection attempt failed.
			* OOB data is available for reading (only if SO_OOBINLINE is disabled).
			*/
			delete detector; detector=NULL;
			return;			
		}
	}	
}

#ifdef WIN32
class WinSockUtils{
public:
	DWORD dwRes;					// Результат старта WinSock
	WinSockUtils(){
		dwRes=0;			
		WSADATA wsaData;			// Данные для WinSock
		WORD wVersion = MAKEWORD(2, 2);
		dwRes = WSAStartup(wVersion, &wsaData);
		srand(time(NULL));
	}
	~WinSockUtils(){
		if(!dwRes)WSACleanup();
	}
};

static WinSockUtils WSU;
#endif
void GatewayClient::start()
{
	if(!port || runned)return;

	// TCP socket
	if(server){delete server; server=NULL;}
	server=new GCServer;

	// UDP socket
	if(sender){delete sender; sender=NULL;}
	sender=new Socket;
	sender->sock = socket(AF_INET,SOCK_DGRAM,0);
	sender->sock_addr.sin_family		= AF_INET;
	sender->sock_addr.sin_port			= htons(port);				// не забываем о сетевом порядке!!!
	sender->sock_addr.sin_addr.s_addr	= htonl(INADDR_BROADCAST);	// означает широковещательный адрес
	u_long brcst = 1;												// Set socket to allow broadcast
	if (setsockopt(sender->sock, SOL_SOCKET, SO_BROADCAST, (char *) &brcst, sizeof(brcst)) == SOCKET_ERROR)return;

	runned=1;
}

void GatewayClient::stop()
{
	if(!runned)return;

	scan_lan_end();
	clear_servers();
	connect_end();
	if(server){delete server; server=NULL;}
	if(sender){delete sender; sender=NULL;}
	runned=0;
}

void GatewayClient::clear_servers( unsigned who /*= GCServer::OR_LN*/ )
{
	unsigned mode = who&0x300;
	unsigned mask = who&0x3;

	struct F 
	{
		unsigned mode;
		F(unsigned mode):mode(mode){}

		bool _and(unsigned left, unsigned right){
			return left & right;
		}
		bool _or(unsigned left, unsigned right){
			return left | right;
		}
		bool _xor(unsigned left, unsigned right){
			return left ^ right;
		}
		bool eq(unsigned left, unsigned right){
			return !(left ^ right);
		}
		bool operator()(unsigned left, unsigned right){
			switch(mode){
				case GCServer::AND_U:	return _and(left,right);
				case GCServer::OR_U:	return _or(left,right);
				case GCServer::XOR_U:	return _xor(left,right);
				case GCServer::EQ_U:	return eq(left,right);
				default:				return 0;
			}
		}
	}f(mode);

	for(int skeep=0,i=servers.size()-1; servers.size()-skeep>0;i=servers.size()-skeep-1)
		if(f(*(unsigned*)&servers[i]->state,mask)){
			delete servers[i]; servers[i]=NULL;
			int size = servers.size()-1;
			servers[i]=servers[size];
			servers.resize(size);
		}else{
			skeep++;
		}
}

void GatewayClient::scan_lan_begin()
{
	if(!runned || !sender || scanning_lan)return;

	scan_lan_result();	// выборка старых необработанных ответов от серверов
	scan_lan_end();		// очистка старых необработанных данных
	scanning_lan=1;

	string msg="scanning servers"; // запрос по широковещательному адресу, на поиск серверов

	if(sender->sendto(msg,sender->sock_addr) == SOCKET_ERROR){
		delete sender; sender=NULL;
		return;
	}
}

void GatewayClient::scan_lan_result()
{
	if(!runned || !sender)return;

	fd_set fds_src;
	FD_ZERO(&fds_src);
	FD_SET(sender->sock,&fds_src);
	timeval tval = {0,0};

	int ret=0;
	sockaddr_in detector_addr; // адресс отправителя
	int addr_size = sizeof(detector_addr);

	while(1){
		fd_set fds_r=fds_src, fds_e=fds_src;
		int ret	= ::select( sender->sock+1, &fds_r, NULL, &fds_e, &tval );
		if(!ret || (ret == SOCKET_ERROR)){
			 if(!scanning_lan){ // выбросить результаты
				sender->ibuffer.clear();
			 }
			 return;	// нет данных или произошла ошибка select
		}
		if(FD_ISSET(sender->sock,&fds_r)){ 
			/*
			* If listen has been called and a connection is pending, accept will succeed.
			* Data is available for reading (includes OOB data if SO_OOBINLINE is enabled).
			* Connection has been closed/reset/terminated.
			*/
			if(sender->recvfrom_raw(detector_addr)<1){
				delete sender; sender=NULL;
				return;
			}
			if(!scanning_lan){
				continue;
			}
			int hdr = -1;	// размер блока неопределенн
			string msg;
			while((hdr=sender->unpack(msg))!=-1){
				if( hdr >= sizeof(GWSSResponse) ){
					GWSSResponse resp = *(GWSSResponse*)msg.data();
					if(resp.ver==100){ // version 1.0
						GCServer *server = new GCServer;
						server->state.local=1;
						server->sid=resp.sid;
						server->s.sock_addr=resp.sock_addr; // загрузка адреса сервера
						server->s.sock_addr.sin_addr=detector_addr.sin_addr; // правка ip
						for(int i=0; i<servers.size(); i++)
							if(servers[i]->sid == server->sid){ // обновляем информацию о сервере
								servers[i]->state.local=1;
								servers[i]->s.sock_addr = server->s.sock_addr;
								delete server;server=NULL;
								break;
							}
						if(server)servers.push_back(server);
					}
				}
			}
		}
		if(FD_ISSET(sender->sock,&fds_e)){ 
			/*
			* If processing a connect call (nonblocking), connection attempt failed.
			* OOB data is available for reading (only if SO_OOBINLINE is disabled).
			*/
			delete sender; sender=NULL;
			return;			
		}
	}
}

void GatewayClient::scan_lan_end()
{
	scanning_lan=0;
}

void GatewayClient::select( int num )
{
	if(!runned || (num<0) || (num>=servers.size()))return;

	connect_end();
	if(server){delete server; server=NULL;}
	server=new GCServer;
	*server=*servers[num];
	server->s.ibuffer.clear();
	server->s.sock=SOCKET_ERROR;
	server->s.connected=0;
}

void GatewayClient::connect_begin()
{
	if(!runned || !server || server->s.connected || (server->s.sock!=SOCKET_ERROR))return;

	server->s.sock = socket(AF_INET,SOCK_STREAM,0);
	if(server->s.sock == INVALID_SOCKET)return;
	if(server->s.setnoblock(1)) return;
	connect(server->s.sock, (sockaddr *)&server->s.sock_addr, sizeof(server->s.sock_addr)); // пытаемся установить соединение
	if(server->s.setnoblock(0)) return;
}

bool GatewayClient::connect_result()
{
	if(!runned || !server )return false;

	fd_set fds_src;
	FD_ZERO(&fds_src);
	FD_SET(server->s.sock,&fds_src);
	timeval tval = {0,0};
	int ret=0;
	while(1){
		fd_set fds_w=fds_src, fds_e=fds_src;
		int ret	= ::select( server->s.sock+1, NULL, &fds_w, &fds_e, &tval );
		if(!ret || (ret == SOCKET_ERROR)) return false;	// нет данных или произошла ошибка select
		if(FD_ISSET(server->s.sock,&fds_w)){ 
			/*
			* If processing a connect call (nonblocking), connection has succeeded.
			* Data can be sent.
			*/
			return server->s.connected=1;
		}
		if(FD_ISSET(server->s.sock,&fds_e)){ 
			/*
			* If processing a connect call (nonblocking), connection attempt failed.
			* OOB data is available for reading (only if SO_OOBINLINE is disabled).
			*/
			if(server){delete server; server=NULL;}
			return false;		
		}
	}
	return false;
}

void GatewayClient::connect_end()
{
	if(server && server->s.connected){
		server->s.connected=0;
		closesocket(server->s.sock);
		server->s.sock = SOCKET_ERROR;
		if(callback)callback->OnDisconnect();
	}
}

void GatewayClient::send_to_server( const std::string &message )
{
	if(!runned || !server || !server->s.connected)return;

	if(server->s.send(message) == SOCKET_ERROR){
		connect_end();
	}
}

void GatewayClient::recv_from_server()
{
	if(!runned || !server || !server->s.connected)return;

	fd_set fds_src;
	FD_ZERO(&fds_src);
	FD_SET(server->s.sock,&fds_src);
	timeval tval = {0,0};
	int ret=0;

	while(1){
		fd_set fds_r=fds_src, fds_e=fds_src;
		int ret	= ::select( server->s.sock+1, &fds_r, NULL, &fds_e, &tval );
		if(!ret || (ret == SOCKET_ERROR)) return;	// нет данных или произошла ошибка select
		if(FD_ISSET(server->s.sock,&fds_r)){ 
			/*
			* If listen has been called and a connection is pending, accept will succeed.
			* Data is available for reading (includes OOB data if SO_OOBINLINE is enabled).
			* Connection has been closed/reset/terminated.
			*/
			if(server->s.recv_raw()<1){
				connect_end();
				return;
			}
			string msg;
			while(server->s.unpack(msg)!=-1){
				if(callback)callback->OnRecvPack(msg);
				if(!server || !server->s.connected)return;
			}
		}
		if(FD_ISSET(server->s.sock,&fds_e)){ 
			/*
			* If processing a connect call (nonblocking), connection attempt failed.
			* OOB data is available for reading (only if SO_OOBINLINE is disabled).
			*/
			connect_end();
			return;			
		}
	}
}
//
static unsigned capture_tag(string src, string &dst, string tag_op, string tag_cl){ // return offset after read
	unsigned offs=src.find(tag_op);
	unsigned offe=src.find(tag_cl);
	if(offs==src.npos || offe==src.npos) return src.npos;
	dst = src.substr(offs+tag_op.size(),offe-offs-tag_op.size());
	return offe+tag_cl.size();
}

inline void Socket::pack( std::string &dest, const std::string &source )
{
	int hdr = source.size();
	dest.clear();
	dest.append((char*)&hdr,sizeof(int));
	dest.append(source);
	if(reserved<hdr+4)
		reserved=hdr+4;
}

inline int Socket::send_raw( std::string &source )
{
	int ret=0;
	do 
	{
		source = source.substr(ret);
		ret=::send(sock,source.c_str(),source.size(),0);
		if(ret == SOCKET_ERROR){
			break;
		}
	} while (ret != source.size());	
	return ret;
}

inline int Socket::send( const std::string &source )
{
	pack(rbuffer,source);		// упаковка данных заголовком
	return send_raw(rbuffer);	// отправка данных
}

inline int Socket::header_read()
{
	int hdr = -1;					// размер блока неопределенн
	if(ibuffer.size()>=4){ 
		hdr = *(int*)ibuffer.data();	// чтение размера блока
		if(rbuffer.capacity()<hdr+4){
			reserved = hdr+4;
			rbuffer.reserve(reserved);
		}
		ibuffer = ibuffer.substr(4);
	}
	return hdr;
}

void Socket::header_write( int hdr )
{
	ibuffer.insert(0,(char*)&hdr,4);
}

inline int Socket::unpack( std::string &dest )
{
	int hdr=header_read();				// чтение заголовка
	if(hdr==-1)return hdr;				// нет заголовка? не распаковано

	if(ibuffer.size()>= hdr){			// данные полностью загружены
		dest = ibuffer.substr(0,hdr);	// чтение блока данных
		ibuffer = ibuffer.substr(hdr);	// извлечение прочитанного из буфера
	}else{								// данные не полностью загружены
		header_write(hdr);				// запись заголовка, обратно в буфер
		hdr=-1;							// не распаковано
	}
	return hdr;
}

inline int Socket::sendto_raw( std::string &source, const sockaddr_in &to )
{
	int ret=0;
	do 
	{
		source = source.substr(ret);
		ret=::sendto(sock,source.c_str(),source.size(),0,(sockaddr*)&to, sizeof(sockaddr_in));
		if(ret == SOCKET_ERROR){
			break;
		}
	} while (ret != source.size());	
	return ret;
}

inline int Socket::sendto( const std::string &source, const sockaddr_in &to )
{
	pack(rbuffer,source);			// упаковка данных заголовком
	return sendto_raw(rbuffer,to);	// отправка данных
}

int Socket::rcvbuf()
{
	int buffsize=0;
#ifdef WIN32
	int size=sizeof(buffsize);
#else
	socklen_t size=sizeof(buffsize);
#endif
	getsockopt(sock,SOL_SOCKET,SO_RCVBUF,(char*)&buffsize,&size);
	return buffsize;
}

void Socket::rcvbuf( int newsize )
{
	int size=sizeof(newsize);
	setsockopt(sock,SOL_SOCKET,SO_RCVBUF,(char*)&newsize,size);	
}

int Socket::sndbuf()
{
	int buffsize=0;
#ifdef WIN32
	int size=sizeof(buffsize);
#else
	socklen_t size=sizeof(buffsize);
#endif
	getsockopt(sock,SOL_SOCKET,SO_SNDBUF,(char*)&buffsize,&size);
	return buffsize;
}

void Socket::sndbuf( int newsize )
{
	int size=sizeof(newsize);
	setsockopt(sock,SOL_SOCKET,SO_SNDBUF,(char*)&newsize,size);	
}

inline int Socket::recv_raw()
{
	if(rbuffer.capacity()<reserved) 
		rbuffer.reserve(reserved);
	char *pbuff=const_cast<char*>(rbuffer.data());
	int ret = ::recv(sock,pbuff,rbuffer.capacity(),0);
#ifdef WIN32
	if((ret == SOCKET_ERROR) && (WSAGetLastError()==WSAEMSGSIZE)){
		ret = rbuffer.capacity();
	}else
#endif
	if(!ret || (ret == SOCKET_ERROR)){
		return ret;
	}
	ibuffer.append(pbuff,ret);	// присоединение прочитанных данных
	return ret;
}

inline int Socket::recvfrom_raw( sockaddr_in &from )
{
	if(rbuffer.capacity()<reserved) 
		rbuffer.reserve(reserved);
	char *pbuff=const_cast<char*>(rbuffer.data());
#ifdef WIN32
	int fromlen=sizeof(from);
#else
	socklen_t fromlen=sizeof(from);
#endif
	int ret = ::recvfrom(sock,pbuff,rbuffer.capacity(),0,(sockaddr*)&from,&fromlen);
#ifdef WIN32
	if((ret == SOCKET_ERROR) && (WSAGetLastError()==WSAEMSGSIZE)){
		ret = rbuffer.capacity();
	}else
#endif
	if(!ret || (ret == SOCKET_ERROR)){
		return ret;
	}
	ibuffer.append(pbuff,ret);	// присоединение прочитанных данных
	return ret;	
}
int Socket::setaddr(const std::string &addr){
#ifdef WIN32
	ADDRINFO net_hint, *net_result=NULL;
	ZeroMemory(&net_hint,sizeof(net_hint));
	net_hint.ai_family=AF_INET;
	net_hint.ai_protocol=IPPROTO_TCP;
  auto err_code=getaddrinfo(addr.c_str(),NULL,&net_hint,&net_result);
	if(err_code==SOCKET_ERROR)return -1;
  if(!net_result)return -1;
	sock_addr=*(sockaddr_in*)net_result->ai_addr;
	freeaddrinfo(net_result);
	return 0;
#else
	HOSTENT *hst;
	// Преобразование IP -адреса. SERVERADDR - адрес сервера
	if(inet_addr(addr.c_str())!=INADDR_NONE )     
		sock_addr.sin_addr.s_addr=inet_addr(addr.c_str());
	else //Осуществляем попытку получения IP-адреса по доменному имени
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

int Socket::setnoblock(bool on){
#ifdef WIN32
	u_long cmd=on;
	if( ioctlsocket(sock, FIONBIO, &cmd) ) return -1;
	return 0;
#else
	int f;
	if ((f = fcntl(sock, F_GETFL, 0))== -1)
		return -1;
	if(on) 
	  f|= O_NONBLOCK;
	else 
	  f&= ~O_NONBLOCK;
	if(fcntl(sock, F_SETFL, f) == -1)
		return -1;
	return 0;
#endif
}