#pragma once

#include <WS2tcpip.h>
#include "../Include/Dict4Trans.h"
#pragma comment(lib, "ws2_32.lib")



class Client
{
public:
	Client(const char* clientIp,const SOCKET& clientSocket);
	Client();
	virtual ~Client();
	void mInitialization(void);
	
	void send(char *buf);
	char *recv();
private:
	char mBuffer4Send[MAXBUFFERSIZE];
	char mBuffer4Recv[MAXBUFFERSIZE];
	SOCKET mClientSocket;
	ClientType mClientType;
	const char* mClientIp;
};

class UWPHololensClient:public Client
{

};
class AndroidPhoneClient:public Client
{

};
class WindowsCameraClient:public Client
{

};

class WindowsHTCClient:public Client
{

};
class WindowsPCClient:public Client
{

};

class WindowsProjectorClient:public Client
{

};










