#pragma once
#include <iostream>
#include <WS2tcpip.h>
#include <list>
#include "Client.h"
#pragma comment(lib, "ws2_32.lib")
using namespace std;

class Server
{
public:
	char mBuffer4Send[MAXBUFFERSIZE];
	char mBuffer4Recv[MAXBUFFERSIZE];

	list<Client*> mClientList;

	Server();
	Server(const Server& other);
	
	
	
	void mCleanSocket(void);/**< clean all sockets in the system */
	bool mClearClient(void);
	
	bool mStartListenThread();


	void mDataSend(char *mBuffer4Send);
	char* mDataRecv(void);

	void mAddClient(const Client &client);
	void mRemoveClient(const Client);
	
protected:
	
private:
	void mInitializeSocket(void);
	bool mIsListenState(void);
	SOCKET mSocketListen;//()const;

};





