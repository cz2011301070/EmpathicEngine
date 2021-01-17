#include "../Include/Client.h"

Client::Client()
{
	mClientIp = NULL;
}
/**
*@ brief Copy constructor of Client
*/
Client::Client(const char* clientIp,const SOCKET& clientSocket)
{
	mClientIp = clientIp;
	mClientSocket = clientSocket;
}



Client::~Client()
{
	delete mClientIp;
	mClientIp = nullptr;
}



