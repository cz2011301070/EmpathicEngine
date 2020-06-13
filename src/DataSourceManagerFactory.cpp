#include "../Include/DataSourceManagerFactory.h"

DataSourceManagerFactory::DataSourceManagerFactory(){}
DataSourceManagerFactory::~DataSourceManagerFactory(){}

class XMLMangerFactory:DataSourceManagerFactory{
public:
	XMLManger* mCreateDataSourceManager(){
		return new XMLManger();
	}
};
class DataBaseManagerFactory:DataSourceManagerFactory{
public:
	DataBaseManager* mCreateDataSourceManager(){
		return new DataBaseManager();
	}
};

class JsonManagerFactory:DataSourceManagerFactory{
public:
	JsonManager* mCreateDataSourceManager(){
		return new JsonManager();
	}
};






