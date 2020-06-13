#pragma once
#include "AbstractFactory.h"

class ClientFactory:AbstractFactory{
public:
	ClientFactory();
	virtual ~ClientFactory();

	virtual Client* mCreateClient()=0;

};

