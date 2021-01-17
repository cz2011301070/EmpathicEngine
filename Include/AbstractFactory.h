#pragma once
#include "Client.h"
#include "DataSourceManager.h"

template<class AbstractProduct>
class AbstractFactory
{
public:
	AbstractFactory();
	virtual ~AbstractFactory();
	virtual AbstractProduct* mCreateproduct() = 0;

};

template<class AbstractProduct, class ConcreteProduct>
class ConcreteFactory : public AbstractFactory<AbstractProduct> {
public:
	ConcreteFactory();
	~ConcreteFactory();

	ConcreteProduct* mCreateproduct() { return new ConcreteProduct(); }

};




