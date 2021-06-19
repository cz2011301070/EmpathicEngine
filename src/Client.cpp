#include "../Include/Client.h"

Client::Client()
{
	//mClientIp = new sockaddr_in();
	memset(mClientHostName, 0, NI_MAXHOST);
}
/**
*@ brief Parameter constructor of Client
*/
Client::Client(const sockaddr_in clientIp,const char* port,const char* clientHostName,const SOCKET& clientSocket)
{
	mClientIp = clientIp;
	//*mClientHostName = *clientHostName;
	memcpy(mPort, port, strlen(port));

	*(mPort + strlen(port)) = '\0';
	memcpy(mClientHostName, clientHostName, strlen(clientHostName));
	*(mClientHostName + strlen(clientHostName)) = '\0';
	mClientSocket = clientSocket;
}
/**
*@ brief Move constructor
*/
Client::Client(Client&& client)
{
	mClientSocket = client.mClientSocket;
	mClientIp = client.mClientIp;
	//client.mClientIp = NULL;
}
/**
*@ brief Copy Constructor of Client
*/
Client::Client(const Client& client)
{
	mClientSocket = client.mClientSocket;
	mClientIp = client.mClientIp;
}

Client::~Client()
{
	/*delete mClientIp;
	mClientIp = nullptr;*/
}

Client& Client::operator=(const Client& client)
{
	mClientSocket = client.mClientSocket;
	mClientIp = client.mClientIp;
	return *this;
}
Client& Client::operator=(Client&& client)
{
	mClientSocket = client.mClientSocket;
	mClientIp = client.mClientIp;
	//client.mClientIp = nullptr;
	return *this;
}


//void Client::mSend(char* buff)
//{
//
//}

