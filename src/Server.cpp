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
	//Get Port number from the Setup.ini file
	Filebase* filePtr = new INIFile();
	string port;
	filePtr->mRead("E:/4.Coding/EmpathicEngineProj/EmpathicEngine/Setup.ini", SplitType::Space);
	if (filePtr->mFileContents.count("port"))
	{
		port = filePtr->mFileContents["port"];
		mServerPort = atoi((char*)port.c_str());
		
	}
	else
	{
		cerr << "mInitializeSocket::mSetupFileContents is Empaty !!" << endl;
		exit(0);
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
	hint.sin_port = htons(mServerPort);
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


/**
* @brief Client thread for send to or receive from each client.
*/
UINT Server::mClientThread(LPVOID pParam)
{
	Client* pThis= (Client*) pParam;
	if(pThis)
	{
		cout << "Client thread has been started" << endl;
		while (true)
		{
			int RecvLen = recv(pThis->mClientSocket, buffer, sizeof(buffer), 0);
			if (RecvLen == SOCKET_ERROR)
			{
				cout << "Server::mClientThread failed to recv data!" << WSAGetLastError() << endl;
			}
			else
			{
				cout << "Server::mClientThread successfully received " << RecvLen << " bytes" << endl;
			}
		}
	}
	
	
	
	
	return 0;
}


UINT Server::mServerThread(LPVOID pParam)
{
	Server* pThis = (Server*) pParam;
	while (true)
	{
		//Wait for a connection
		sockaddr_in clientaddr_in;
		int clientSize = sizeof(clientaddr_in);
		SOCKET clientSocket = accept(pThis->mGetSocketListen(),(sockaddr *)&clientaddr_in,&clientSize);
		if (clientSocket == INVALID_SOCKET)
		{
			cerr<<"clientSocket is invalid, quitting"<<endl;
			return -1;
		}else
		{
			char host[NI_MAXHOST];//clients remote name
			char service[NI_MAXSERV];//service(i.e. port) the client is connect on
			ZeroMemory(host, NI_MAXHOST);//same as memset(host,0,NI_MAXHOST)
			ZeroMemory(service,NI_MAXSERV);
						
			if (getnameinfo((sockaddr*)&clientaddr_in,sizeof(clientaddr_in),host,NI_MAXHOST,service,NI_MAXSERV,0)==0)
			{
				cout<<host<<" connected on port "<<service<<endl;
			}else{
				inet_ntop(AF_INET,&clientaddr_in.sin_addr, host,NI_MAXHOST);//network ip to dotted decimal notation
				cout<<host<<"connected on port "<<
					ntohs(clientaddr_in.sin_port)<<endl;
			}

			Client* client= new Client(host,clientSocket);
			AfxBeginThread(mClientThread,(LPVOID)client);///<begin Client thread in server thread when \
														a valid client connected
		}
	}
	
	return 0;
}


void Server::mStartListenThread(void)
{
	if(mIsListenState())
	{
		AfxBeginThread(mServerThread,this);
	}else
	{
		cerr<<"listen state error, quitting"<<endl;
		return;
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
		
	}
	closesocket(mSocketListen);
	WSACleanup();
}




/**
* @brief send data to clients
*/
void Server::mDataSend(char *buffer, SOCKET client)
{
	int sendLen = send(client, buffer, sizeof(*buffer),0);
	if (sendLen == SOCKET_ERROR) {
		cout << "Server::mDataSend failed to send data!" << WSAGetLastError() << endl;
	}
	else
	{
		cout << "Server::mDataSend successfully sent " << sendLen << " bytes"<<endl;
	}
}

/**
* @brief Deconstruction of Server
*/

Server::~Server()
{
	mCleanSocket();

}

SOCKET& Server::mGetSocketListen()
{
	return mSocketListen;
}








