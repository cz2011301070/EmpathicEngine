#pragma once
#undef UNICODE
#define _AFXDLL
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <Afxwin.h>
#include <WS2tcpip.h>
#include <list>
#include "Client.h"
#include"FileProcess.h"
#pragma comment(lib, "ws2_32.lib")
using namespace std;

class Server
{
public:

	list<const Client*> mClientlist;

	Server();
	Server(const Server& other);
	~Server();
	
	u_short mGetPort();
	
	void mCleanSocket(void);/**< clean all sockets in the system */
	

	void mStartListenThread(void);

	void mDataSend(char *buffer, SOCKET client);
	void mBroadcast(char *buffer);

	void mAddClient(const Client* client);
	void mRemoveClient(const Client);

	SOCKET& mGetSocketListen();
	
protected:
	
private:
	static UINT mServerThread(LPVOID pParam);
	static UINT mClientThread(LPVOID pParam);
	
	bool mClearClient(void);
	void mInitializeSocket(void);
	bool mIsListenState(void);
	SOCKET mSocketListen;//()const;
	
	u_short mServerPort;

	
};





