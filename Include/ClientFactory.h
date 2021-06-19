#pragma once
#include "AbstractFactory.h"

class ClientFactory:AbstractFactory<Client>{
public:
	ClientFactory();
	virtual ~ClientFactory();

	virtual Client* mCreateClient()=0;

};

