#include"../Include/EmpathicEngine.h"

int main()
{
	EmpathicEngine* Epeg = new EmpathicEngine();
	Epeg->mServerSocket = new Server();

	Epeg->mServerSocket->mStartListenThread();

	while (true)
	{
	}
	return 0;

}


