#pragma once
#include "Server.h"
#include "AbstractFactory.h"
#include "ByteConverter.h"
#include "DataSourceManager.h"

class EmpathicEngine
{
public:
	//AbstractFactory *mAbstractFactory;
	//BitConverter *mBitConverter;
	DataSourceManager *mDataSourceManager;
	Server *mServerSocket;

	void mInitData(const EmpathicEngine& epEg);

	
	EmpathicEngine();
	EmpathicEngine(const EmpathicEngine& epEg );
	EmpathicEngine& operator=(const EmpathicEngine& epEg);

	~EmpathicEngine();
};









