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

	
	SOCKET mClientSocket;
private:

	
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










