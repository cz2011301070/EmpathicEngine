#include"../Include/EmpathicEngine.h"

int main()
{
	EmpathicEngine* Epeg = new EmpathicEngine();
	Epeg->mServerSocket = new Server();

	Epeg->mServerSocket->mStartListenThread();

	while (true)///<can avoid memory leak in created thread \
						caused by main thread termination
	{
	}
	return 0;

}


