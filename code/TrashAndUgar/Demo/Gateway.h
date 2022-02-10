#pragma once
#ifndef gateway_H
#define gateway_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <windows.h>
#pragma comment(lib, "Ws2_32.lib")
class Socket // Сокет
{
public:
	SOCKET			sock;		// сокет
	sockaddr_in		sock_addr;	// адресс сокета
	std::string		ibuffer;	// буффер входных данных
	std::string		rbuffer;	// зарезервировано для внутреннего использования (буффер для чтения из сокета)
	bool			connected;	// состояние "соединение установлено", для TCP-сокетов
	void			*userdata;
	int				reserved;	// размер резервируемый в буфере
	std::string		name(){		// строковое представление адреса сокета ip:port
		char buff[16];
		return std::string(inet_ntoa(sock_addr.sin_addr))+std::string(":")+std::string(itoa(ntohs(sock_addr.sin_port),buff,10));
	}
	void Init(){
		connected=0;
		sock=SOCKET_ERROR;
		ZeroMemory(&sock_addr,sizeof(sock_addr));
		ibuffer.clear();
		userdata=NULL;
		ibuffer.clear();
		reserved = 64*1024;//64*1024;			// 64K
		rbuffer.clear();
		rbuffer.reserve(reserved);
	}
	void Free(){
		connected=0;
		if(sock!=SOCKET_ERROR){closesocket(sock);sock=SOCKET_ERROR;}
		ZeroMemory(&sock_addr,sizeof(sock_addr));
		ibuffer.clear();
		rbuffer.clear();
		userdata=NULL;
	}
	Socket(){Init();}
	~Socket(){Free();}

	int				rcvbuf();
	void			rcvbuf(int newsize);
	int				sndbuf();
	void			sndbuf(int newsize);
	void			setbuf(int newsize){rcvbuf(newsize);sndbuf(newsize);reserved=newsize;rbuffer.reserve(newsize);}

	/************************************************************************/
	/*  упаковывает source добавляя заголовок с размером                    */
	/************************************************************************/
	inline void		pack(std::string &dest, const std::string &source);
	/************************************************************************/
	/*  распаковывает из входного буфера данные dest                       */
	/************************************************************************/
	inline int		unpack(std::string &dest);
	/************************************************************************/
	/*  отправляет неупакованные данные по TCP( модифицирует источник )     */
	/************************************************************************/
	inline int		send_raw(std::string &source);
	/************************************************************************/
	/*  отправляет упакованные данные по TCP                                */
	/************************************************************************/
	inline int		send(const std::string &source);
	/************************************************************************/
	/*  отправляет неупакованные данные по UDP( модифицирует источник )     */
	/************************************************************************/
	inline int		sendto_raw(std::string &source, const sockaddr_in &to);
	/************************************************************************/
	/*  отправляет упакованные данные по UDP                                */
	/************************************************************************/
	inline int		sendto(const std::string &source, const sockaddr_in &to);
	/************************************************************************/
	/*  извлекает заголовок с размером                                      */
	/************************************************************************/
	inline int		header_read();
	/************************************************************************/
	/*  помещает в начало заголовок с размером                              */
	/************************************************************************/
	inline void		header_write(int hdr);
	/************************************************************************/
	/*  получает неупакованные данные по TCP                                */
	/************************************************************************/
	inline int		recv_raw();
	/************************************************************************/
	/*  получает неупакованные данные по UDP                                */
	/************************************************************************/
	inline int		recvfrom_raw(sockaddr_in &from);
	/************************************************************************/
	/*  устанавливает ip в адресе сокета                                    */
	/************************************************************************/
	int				setaddr(const std::string &addr);
	/************************************************************************/
	/*  устанавливает неблокирующий режим                                   */
	/************************************************************************/
	int				setnoblock(bool on);
};

class ServerCallback
{
public:
	/****************************************************************************************************/
	/* запрещено вызывать: Free,Stop,recv_one(client),recv_all(),kick_one(client),kick_all()            */
	/****************************************************************************************************/
	virtual void OnRecvPack(Socket *client,std::string &data){}	// приём данных от клиента
	virtual void OnAddClient(Socket *client){}					// подключение нового клиента
	/****************************************************************************************************/
	/* запрещено вызывать: всё																			*/
	/****************************************************************************************************/
	virtual void OnDeleteClient(Socket *client){} 				// отключение клиента
};

class GatewayServer
{
public:
	GatewayServer(){Init();}
	~GatewayServer(){Free();}
	void Init(){
		callback=NULL;
		listener=NULL;
		detector=NULL;
		runned=0;
		port=0;
		FD_ZERO(&fdsClients);
		net_activ=NULL;
		webserver = "dobordx.site88.net";	// "local.dobordx.site88.net"
		webpatch = "/new/TCPEngine";
		userdata=NULL;
		forcebind=0;
		sid = ((unsigned)rand())+100;
		raw = false;
	}
	void Free(){
		stop();
		callback=NULL;
		if(net_activ){delete net_activ;net_activ=NULL;}
		passwd.clear();
		webserver.clear();
		webpatch.clear();
		userdata=NULL;
	}
public:
	void start();	// создание сокетов
	void stop();	// удаление сокетов
	Socket *getClientBySock(SOCKET sock);
public:
	void accept_all();		// принять входящих ( редко )

	void send_one(const std::string &message, Socket* client);	// отправка данных клиенту
	void send_all(const std::string &message);					// отправка данных всем клиентам

	void recv_one(Socket* client);								// при наличии данных, получение их от клиента
	void recv_all();											// при наличии данных, получение их от всех клиентов

	void kick_one(Socket* client);								// отключить клиента
	void kick_all();											// отключить всех клиентов

	void update_lan();	// отвечает всем клиентам на запросы поиска сервера
	void update_net();	// обновляет (sid,passw,port,time) на webserver(active.php) для внешнего (ip)

	Socket*	operator[](unsigned num){return clients[num];}
	unsigned	count(){return clients.size();}
 	operator bool(){return runned;}
public:
	Socket					*listener;		// TCP-сокет для приёма входящих подключений
	Socket					*detector;		// UDP-сокет для обнаружения себя клиентами
	std::vector< Socket* >	clients;		// список клиентов
	ServerCallback			*callback;		// обработчик событий сервера
	bool					runned;			// состояние "работает"
	unsigned				port;			// порт для приёма входящих подключений
	std::string				passwd;			// название информационного-протокола(должен состоять из [a-zA-Z_0-9]), для интернет-подключений
	std::string				webserver;		// хост регистрационного сервера, для интернет-подключений
	std::string				webpatch;		// путь на хосте к каталогу со скриптами, для интернет-подключений
	void					*userdata;
	bool					forcebind;		// в случае занятого порта: использовать случайных порт
	unsigned				sid;			// иденитификатор
	bool					raw;			// используются сырые (не упакованные) данные для обмена информацией
private:
	fd_set					fdsClients;		// вспомогательная структура с массивом сокетов клиентов
	Socket					*net_activ;		// вспомогательный TCP-сокет для поддержания приёма входящих интернет-подключений
	SOCKET					highclient;
};

class ClientCallback
{
public:
	/************************************************************************/
	/* запрещено вызывать: connect_begin(),recv_from_server()               */
	/************************************************************************/
	virtual void OnRecvPack(std::string &data){}	// приём данных от сервера
	virtual void OnDisconnect(){}					// отключение от сервера
};

struct GCServer{
	unsigned	sid;		// идентиф.
	Socket		s;			// сокет
	struct State{
		bool			local	:1;	// в локальной сети
		bool			net		:1;	// в сети интернет
		unsigned char	res0	:6;
		unsigned char	res1;
		unsigned short	res2;
	}state;
	enum Place{
		// AND		if(state & mask)
		AND_U,		// undefined (никто)
		AND_L,		// установлен local
		AND_N,		// установлен net
		AND_LN,		// только те у кого установлены(L,N)
		// OR		if(state | mask)
		OR_U=0x100,	// те у кого что-нибудь установлено
		OR_L,		// все
		OR_N,		// все
		OR_LN,		// все
		// XOR		if(state ^ mask)
		XOR_U=0x200,// те у кого что-нибудь установлено
		XOR_L,		// только те у кого не (L,!N)
		XOR_N,		// только те у кого не (!L,N)
		XOR_LN,		// только те у кого не (L,N)
		// EQUAL	if(!(state ^ mask))
		EQ_U=0x300,	// только те у кого (!L,!N)
		EQ_L,		// только те у кого (L,!N)
		EQ_N,		// только те у кого (!L,N)
		EQ_LN		// только те у кого (L,N)
	};

	GCServer(){Init();}
	~GCServer(){Free();}
	void Init(){
		sid=0;
		state.local=0;
		state.net=0;
		state.res0=0;
		state.res1=0;
		state.res2=0;
	}
	void Free(){
		sid=0;
		state.local=0;
		state.net=0;
	}
};

class GatewayClient
{
public:
	GatewayClient(){Init();}
	~GatewayClient(){Free();}
	void Init(){
		callback=NULL;
		runned=0;
		scanning_lan=0;
		scanning_net=0;
		port=0;
		server=NULL;
		sender=NULL;
		net_scann=NULL;
		webserver = "dobordx.site88.net";	//"local.dobordx.site88.net"
		webpatch = "/new/TCPEngine";
		userdata=NULL;
	}
	void Free(){
		stop();
		callback=NULL;
		passwd.clear();
		webserver.clear();
		webpatch.clear();
		userdata=NULL;
	}
public:
	void start();			// создание сокетов
	void stop();			// удаление сокетов
	void clear_servers(unsigned who = GCServer::OR_LN);	// очистка серверов

public:// if runned
	
	void scan_lan_begin();	
	void scan_lan_result();	// if scanning
	void scan_lan_end();

	void scan_net_begin();	
	bool scan_net_result();	// if scanning, возвращает готовность результата
	void scan_net_end();

	void select(int num);	// из servers, servers[num], вызывает connect_end
	void connect_begin();	// client.sock set !SOCKET_ERROR
	bool connect_result();
	void connect_end();		// client.sock set SOCKET_ERROR

	void send_to_server(const std::string &message);
	void recv_from_server();

	bool connecting(){ return runned && server && !server->s.connected && (server->s.sock!=SOCKET_ERROR);}
	bool connected(){ return runned && server && server->s.connected; }

	GCServer* operator[](unsigned num){return servers[num];}
	unsigned	count(){return servers.size();}
	operator bool(){return runned;}
public:
	GCServer				*server;			// активный сервер
	Socket					*sender;			// UDP-сокет для широковещательного опроса серверов при их поиске
	std::vector<GCServer*>	servers;			// найденые серверы
	ClientCallback			*callback;			// обработчик событий клиента 
	bool					runned;				// состояние "работает"
	bool					scanning_lan;		// состояние "сканирование серверов в локальной сети"
	bool					scanning_net;		// состояние "сканирование серверов в сети интернет"
	unsigned				port;				// порт для поиска серверов
	std::string				passwd;				// название информационного-протокола(должен состоять из [a-zA-Z_0-9]), для интернет-подключений
	std::string				webserver;			// хост регистрационного сервера, для интернет-подключений
	std::string				webpatch;			// путь на хосте к каталогу со скриптами, для интернет-подключений
	void					*userdata;
private:
	Socket					*net_scann;			// вспомогательный TCP-сокет, для интернет-подключений
};

#endif
