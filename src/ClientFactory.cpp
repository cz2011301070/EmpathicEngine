#include "../Include/ClientFactory.h"

ClientFactory::ClientFactory(){}
ClientFactory::~ClientFactory(){}

class UWPHololensClientFactory:public ClientFactory{
public:
	Client *mCreateClient(){
		return new UWPHololensClient();
	}
};

class AndroidPhoneClientFactory:public ClientFactory{
public:
	Client *mCreateClient(){
		return new AndroidPhoneClient();
	}
};

class WindowsCameraClientFactory:public ClientFactory{
public:
	Client* mCreateClient(){
		return new WindowsCameraClient();
	}
};

class WindowsHTCClientFactory:public ClientFactory{
public:
	Client* mCreateClient(){
		return new WindowsHTCClient();
	}
};
class WindowsPCClientFactory:public ClientFactory{
public:
	Client* mCreateClient(){
		return new WindowsPCClient();
	}
};

class WindowsProjectorClientFactory:public ClientFactory{
public:
	Client* mCreateClient(){
		return new WindowsProjectorClient();
	}
};


