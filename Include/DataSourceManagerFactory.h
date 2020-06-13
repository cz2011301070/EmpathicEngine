#pragma once
#include "AbstractFactory.h"

class DataSourceManagerFactory: AbstractFactory{
public:
	DataSourceManagerFactory();
	~DataSourceManagerFactory();

	DataSourceManager* mCreateDataSourceManager();
};










