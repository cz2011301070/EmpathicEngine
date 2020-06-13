#include <iostream>
#include <WS2tcpip.h>
#include <map>
#pragma comment(lib, "ws2_32.lib")

char buf[MAXBUFFERSIZE];

using namespace std;
void initializeSocket(){
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
SOCKET socketListen(){
	//Create a scoket
	SOCKET listening = socket(AF_INET, SOCK_STREAM,0);
	if (listening ==INVALID_SOCKET)
	{
		cerr<<"Can't create a socket! Quitting"<<endl;
		return;
	}
	
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

	bind(listening,(sockaddr *)&hint, sizeof(hint));
	//Tell winsock the sockt is for listening
	listen(listening, SOMAXCONN);
}
SOCKET clientManager(){
	//Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);
	SOCKET clientSocket = accept(listening,(sockaddr *)&client,&clientSize);
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
void dataSend(){
	send(clientSocket,buf,bytesReceived+1,0);//why plus 1
	//Echo message back to client
}
void dataRecv(){
	while (true)
	{
		ZeroMemory(buf,MAXBUFFERSIZE);//4k,a preferred value in windows socket
		//wait for client to send data
		int bytesReceived = recv(clientSocket,buf,4096,0);
		if (bytesReceived == SOCKET_ERROR)
		{
			cerr<<"Error in recv() quitting"<<endl;
			break;
		}
		if (bytesReceived == 0)
		{
			cout<<"Client disconnected"<<endl;
			break;
		}
	}
	
}

void main(){
	initializeSocket();

	socketListen();

	//while loop:accept and echo message back to client

	//close listening socket
	closesocket(listening);
	//close the client socket
	closesocket(clientSocket);
	//cleanup winscok
	WSACleanup();

}




