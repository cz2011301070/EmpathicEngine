#include "../Include/Client.h"

Client::Client()
{
	mInitialization();
}
/**
*@ brief Copy constructor of Client
*/
Client::Client(const char* clientIp,const SOCKET& clientSocket)
{
	mClientIp = clientIp;
	mClientSocket = clientSocket;
	mInitialization();
}

inline void Client::mInitialization(void)
{
	ZeroMemory(mBuffer4Send, NI_MAXHOST);//same as memset(host,0,NI_MAXHOST)
	ZeroMemory(mBuffer4Recv,NI_MAXSERV);
}

Client::~Client()
{
	delete mClientIp;
	mClientIp = nullptr;
}









