#pragma once

#include <WS2tcpip.h>
#include "../Include/Dict4Trans.h"
#pragma comment(lib, "ws2_32.lib")
#include<iostream>


class Client
{
public:
	Client(const sockaddr_in clientIp, const char* port, \
		const char* clientHostName,const SOCKET& clientSocket);
	Client(Client&& client);
	Client(const Client& client);
	Client();
	Client& operator = (const Client& client);
	Client& operator = (Client&& client);
	~Client();

	const char* Get_mPort(void) { return mPort; }
	const char* Get_mClientHostName(void) { return mClientHostName; }
	
	//void mSend(const char* buff) const;
	//void mRecv(char& buff);

	//void testR()&& { std::cout << "rvalue func" << std::endl; }
	//void testL()& { std::cout << "lvalue func" << std::endl; }
	
	SOCKET mClientSocket;
	
private:
	sockaddr_in mClientIp;
	char mPort[NI_MAXSERV];
	char mClientHostName[NI_MAXHOST];
	//char* mClientIp;
};











