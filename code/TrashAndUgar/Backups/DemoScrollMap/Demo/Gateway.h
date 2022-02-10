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
class Socket // �����
{
public:
	SOCKET			sock;		// �����
	sockaddr_in		sock_addr;	// ������ ������
	std::string		ibuffer;	// ������ ������� ������
	std::string		rbuffer;	// ��������������� ��� ����������� ������������� (������ ��� ������ �� ������)
	bool			connected;	// ��������� "���������� �����������", ��� TCP-�������
	void			*userdata;
	int				reserved;	// ������ ������������� � ������
	std::string		name(){		// ��������� ������������� ������ ������ ip:port
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
	/*  ����������� source �������� ��������� � ��������                    */
	/************************************************************************/
	inline void		pack(std::string &dest, const std::string &source);
	/************************************************************************/
	/*  ������������� �� �������� ������ ������ dest                       */
	/************************************************************************/
	inline int		unpack(std::string &dest);
	/************************************************************************/
	/*  ���������� ������������� ������ �� TCP( ������������ �������� )     */
	/************************************************************************/
	inline int		send_raw(std::string &source);
	/************************************************************************/
	/*  ���������� ����������� ������ �� TCP                                */
	/************************************************************************/
	inline int		send(const std::string &source);
	/************************************************************************/
	/*  ���������� ������������� ������ �� UDP( ������������ �������� )     */
	/************************************************************************/
	inline int		sendto_raw(std::string &source, const sockaddr_in &to);
	/************************************************************************/
	/*  ���������� ����������� ������ �� UDP                                */
	/************************************************************************/
	inline int		sendto(const std::string &source, const sockaddr_in &to);
	/************************************************************************/
	/*  ��������� ��������� � ��������                                      */
	/************************************************************************/
	inline int		header_read();
	/************************************************************************/
	/*  �������� � ������ ��������� � ��������                              */
	/************************************************************************/
	inline void		header_write(int hdr);
	/************************************************************************/
	/*  �������� ������������� ������ �� TCP                                */
	/************************************************************************/
	inline int		recv_raw();
	/************************************************************************/
	/*  �������� ������������� ������ �� UDP                                */
	/************************************************************************/
	inline int		recvfrom_raw(sockaddr_in &from);
	/************************************************************************/
	/*  ������������� ip � ������ ������                                    */
	/************************************************************************/
	int				setaddr(const std::string &addr);
	/************************************************************************/
	/*  ������������� ������������� �����                                   */
	/************************************************************************/
	int				setnoblock(bool on);
};

class ServerCallback
{
public:
	/****************************************************************************************************/
	/* ��������� ��������: Free,Stop,recv_one(client),recv_all(),kick_one(client),kick_all()            */
	/****************************************************************************************************/
	virtual void OnRecvPack(Socket *client,std::string &data){}	// ���� ������ �� �������
	virtual void OnAddClient(Socket *client){}					// ����������� ������ �������
	/****************************************************************************************************/
	/* ��������� ��������: ��																			*/
	/****************************************************************************************************/
	virtual void OnDeleteClient(Socket *client){} 				// ���������� �������
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
	void start();	// �������� �������
	void stop();	// �������� �������
	Socket *getClientBySock(SOCKET sock);
public:
	void accept_all();		// ������� �������� ( ����� )

	void send_one(const std::string &message, Socket* client);	// �������� ������ �������
	void send_all(const std::string &message);					// �������� ������ ���� ��������

	void recv_one(Socket* client);								// ��� ������� ������, ��������� �� �� �������
	void recv_all();											// ��� ������� ������, ��������� �� �� ���� ��������

	void kick_one(Socket* client);								// ��������� �������
	void kick_all();											// ��������� ���� ��������

	void update_lan();	// �������� ���� �������� �� ������� ������ �������
	void update_net();	// ��������� (sid,passw,port,time) �� webserver(active.php) ��� �������� (ip)

	Socket*	operator[](unsigned num){return clients[num];}
	unsigned	count(){return clients.size();}
 	operator bool(){return runned;}
public:
	Socket					*listener;		// TCP-����� ��� ����� �������� �����������
	Socket					*detector;		// UDP-����� ��� ����������� ���� ���������
	std::vector< Socket* >	clients;		// ������ ��������
	ServerCallback			*callback;		// ���������� ������� �������
	bool					runned;			// ��������� "��������"
	unsigned				port;			// ���� ��� ����� �������� �����������
	std::string				passwd;			// �������� ���������������-���������(������ �������� �� [a-zA-Z_0-9]), ��� ��������-�����������
	std::string				webserver;		// ���� ���������������� �������, ��� ��������-�����������
	std::string				webpatch;		// ���� �� ����� � �������� �� ���������, ��� ��������-�����������
	void					*userdata;
	bool					forcebind;		// � ������ �������� �����: ������������ ��������� ����
	unsigned				sid;			// ��������������
	bool					raw;			// ������������ ����� (�� �����������) ������ ��� ������ �����������
private:
	fd_set					fdsClients;		// ��������������� ��������� � �������� ������� ��������
	Socket					*net_activ;		// ��������������� TCP-����� ��� ����������� ����� �������� ��������-�����������
	SOCKET					highclient;
};

class ClientCallback
{
public:
	/************************************************************************/
	/* ��������� ��������: connect_begin(),recv_from_server()               */
	/************************************************************************/
	virtual void OnRecvPack(std::string &data){}	// ���� ������ �� �������
	virtual void OnDisconnect(){}					// ���������� �� �������
};

struct GCServer{
	unsigned	sid;		// �������.
	Socket		s;			// �����
	struct State{
		bool			local	:1;	// � ��������� ����
		bool			net		:1;	// � ���� ��������
		unsigned char	res0	:6;
		unsigned char	res1;
		unsigned short	res2;
	}state;
	enum Place{
		// AND		if(state & mask)
		AND_U,		// undefined (�����)
		AND_L,		// ���������� local
		AND_N,		// ���������� net
		AND_LN,		// ������ �� � ���� �����������(L,N)
		// OR		if(state | mask)
		OR_U=0x100,	// �� � ���� ���-������ �����������
		OR_L,		// ���
		OR_N,		// ���
		OR_LN,		// ���
		// XOR		if(state ^ mask)
		XOR_U=0x200,// �� � ���� ���-������ �����������
		XOR_L,		// ������ �� � ���� �� (L,!N)
		XOR_N,		// ������ �� � ���� �� (!L,N)
		XOR_LN,		// ������ �� � ���� �� (L,N)
		// EQUAL	if(!(state ^ mask))
		EQ_U=0x300,	// ������ �� � ���� (!L,!N)
		EQ_L,		// ������ �� � ���� (L,!N)
		EQ_N,		// ������ �� � ���� (!L,N)
		EQ_LN		// ������ �� � ���� (L,N)
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
	void start();			// �������� �������
	void stop();			// �������� �������
	void clear_servers(unsigned who = GCServer::OR_LN);	// ������� ��������

public:// if runned
	
	void scan_lan_begin();	
	void scan_lan_result();	// if scanning
	void scan_lan_end();

	void scan_net_begin();	
	bool scan_net_result();	// if scanning, ���������� ���������� ����������
	void scan_net_end();

	void select(int num);	// �� servers, servers[num], �������� connect_end
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
	GCServer				*server;			// �������� ������
	Socket					*sender;			// UDP-����� ��� ������������������ ������ �������� ��� �� ������
	std::vector<GCServer*>	servers;			// �������� �������
	ClientCallback			*callback;			// ���������� ������� ������� 
	bool					runned;				// ��������� "��������"
	bool					scanning_lan;		// ��������� "������������ �������� � ��������� ����"
	bool					scanning_net;		// ��������� "������������ �������� � ���� ��������"
	unsigned				port;				// ���� ��� ������ ��������
	std::string				passwd;				// �������� ���������������-���������(������ �������� �� [a-zA-Z_0-9]), ��� ��������-�����������
	std::string				webserver;			// ���� ���������������� �������, ��� ��������-�����������
	std::string				webpatch;			// ���� �� ����� � �������� �� ���������, ��� ��������-�����������
	void					*userdata;
private:
	Socket					*net_scann;			// ��������������� TCP-�����, ��� ��������-�����������
};

#endif
