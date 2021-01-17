#pragma once

#include <WS2tcpip.h>
#include "../Include/Dict4Trans.h"
#pragma comment(lib, "ws2_32.lib")
#include<iostream>


class Client
{
public:
	Client(const char* clientIp,const SOCKET& clientSocket);
	Client(char* &&clientIp, SOCKET&& clientSocket);
	Client();
	Client& operator = (const Client& client);
	Client& operator = (Client&& client);
	~Client();

	
	
	void mSend(const char* buff) const;
	void mRecv(char& buff);

	//void testR()&& { std::cout << "rvalue func" << std::endl; }
	//void testL()& { std::cout << "lvalue func" << std::endl; }
	
	SOCKET mClientSocket;
private:

	const char* mClientIp;
};











