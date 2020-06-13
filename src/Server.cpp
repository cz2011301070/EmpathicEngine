#include "../Include/Server.h"
/**
*@ brief WINSOCK Initialization
*/
inline void Server::mInitializeSocket(void)
{
	//Initialize winsock
	WSADATA wsData;// a struct
	WORD ver=MAKEWORD(2,2);//version of winsock

	int wsOk = WSAStartup(ver,&wsData);///< start winsock,tell windows which winsock version will be used
	///< wsData is a struc pointer which stores value returned from winsock related dlls

	if (wsOk !=0)
	{
		cerr<< "Can't Initialize winsock£¡ Quitting"<<endl;
		return;
	}
	
}

/**
* @brief Constructor of Server, Create a server socket
*/
Server::Server()
{
	mInitializeSocket();
	//Create a scoket
	mSocketListen = socket(AF_INET, SOCK_STREAM,0);
	if (mSocketListen ==INVALID_SOCKET)
	{
		cerr<<"Can't create a socket! Quitting"<<endl;
		return;
	}
}

/**
* @brief Copy cot of Server
*/
Server::Server(const Server& other)
{
	mInitializeSocket();
	//Create a scoket
	mSocketListen = other.mSocketListen;
	if (mSocketListen ==INVALID_SOCKET)
	{
		cerr<<"Can't create a socket! Quitting"<<endl;
		return;
	}
}

bool Server::mIsListenState()
{
	//Bind the socket to an ip address and port
	sockaddr_in hint;
	hint.sin_family =AF_INET;
	/**
	/* htonl()--host to network long
	/* ntonl()--network to host long
	/* htons()--host to network short
	/* ntohs()--network to host short
	/*
	*/
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;//Could also use inet_pton

	bind(mSocketListen,(sockaddr *)&hint, sizeof(hint));
	//Tell winsock the sockt is for listening
	if(listen(mSocketListen, SOMAXCONN) == 0)/**< return 0 or -1*/
	{
		return true;
	}else
	{
		return false;
	}
}

bool Server::mStartListenThread()
{
	//Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);
	SOCKET clientSocket = accept(mSocketListen,(sockaddr *)&client,&clientSize);
	if (clientSocket == INVALID_SOCKET)
	{
		cerr<<"clientSocket is invalid, quitting"<<endl;
		return;
	}
	char host[NI_MAXHOST];//clients remote name
	char service[NI_MAXSERV];//service(i.e. port) the client is connect on
	ZeroMemory(host, NI_MAXHOST);//same as memset(host,0,NI_MAXHOST)
	ZeroMemory(service,NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client,sizeof(client),host,NI_MAXHOST,service,NI_MAXSERV,0)==0)
	{
		cout<<host<<" connected on port "<<service<<endl;
	}else{
		inet_ntop(AF_INET,&client.sin_addr, host,NI_MAXHOST);//network ip to dotted decimal notation
		cout<<host<<"connected on port "<<
			ntohs(client.sin_port)<<endl;
	}
}

/**
* @brief clear client list
*/
bool Server::mClearClient()
{
	mClientList.clear();
	if (mClientList.empty())
	{
		return true;
	}else
	{
		return false;
	}
	
}

/**
* @brief clean all sockets in the system
*/
void Server::mCleanSocket()
{
	if (mClearClient())
	{	
		closesocket(mSocketListen);
	}
	WSACleanup();
}

/**
* @brief send data to clients
*/
void Server::mDataSend(char *mBuffer4Send)
{


}




