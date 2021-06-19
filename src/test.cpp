//#include"../include/empathicengine.h"
//#include"../include/byteconverter.h"
//#include<sstream>
#include"../include/server.h"
#include"../include/dbmysql.h"
#include "../3rdlib/libzmq-master/include/zmq.h"
#include<string>
#include<iostream>
#include<assert.h>
//#pragma comment(lib, "libzmq-v142-mt-gd-4_3_5.lib")
using namespace std;

int main()
{
	void* context = zmq_ctx_new();
	void* responder = zmq_socket(context, ZMQ_REP);
	int rc=zmq_bind(responder, "tcp://*:5555");
	assert(rc == 0);
	while (1)
	{
		char buffer[10];
		zmq_recv(responder, buffer, 10, 0);
		cout << "Received hello";
		Sleep(1);
		zmq_send(responder, "world", 5, 0);
	}

	/*
	* db management should be done in a standalone thread
	
	*/

	/*dbmysql *msql= new dbmysql();
	bool res = false;
	res= msql->mconnectdb("127.0.0.1", 3308, "root", "cz612727@", "belief");*/

	int index = 0;

	Server* severinstance = new Server();


	//severinstance->mstartlistenthread();
	//empathicengine* epeg = new empathicengine();
	//epeg->mserversocket = new server();

	//epeg->mserversocket->mstartlistenthread();

	while (true)///<can avoid memory leak in created thread \
						caused by main thread termination
	{

	}
	system("pause");
	return 0;

}









