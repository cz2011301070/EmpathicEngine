#pragma once
#undef UNICODE
#define _AFXDLL
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <Afxwin.h>
#include <WS2tcpip.h>
#include <list>
#include "Client.h"
#pragma comment(lib, "ws2_32.lib")
using namespace std;

class Server
{
public:




	list<Client*> mClientList;

	Server();
	Server(const Server& other);
	~Server();
	
	
	void mCleanSocket(void);/**< clean all sockets in the system */
	bool mClearClient(void);

	void mStartListenThread(void);


	void mDataSend(char *mBuffer4Send);
	char* mDataRecv(void);

	void mAddClient(const Client &client);
	void mRemoveClient(const Client);

	SOCKET& mGetSocketListen();
protected:
	
private:
	static UINT mServerThread(LPVOID pParam);
	static UINT mClientThread(LPVOID pParam);
	void mInitializeSocket(void);
	bool mIsListenState(void);
	SOCKET mSocketListen;//()const;

};





