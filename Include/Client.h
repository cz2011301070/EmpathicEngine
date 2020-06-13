#pragma once

#include <WS2tcpip.h>
#include "../Include/Dict4Trans.h"
#pragma comment(lib, "ws2_32.lib")



class Client
{
public:
	Client();
	virtual ~Client();

	void send(char *buf);
	char *recv();
private:
	SOCKET* mClientSocket;
	ClientType mClientType;
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










