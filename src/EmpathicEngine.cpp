
#include"../Include/EmpathicEngine.h"

EmpathicEngine::EmpathicEngine():mServerSocket(nullptr),\
									mDataSourceManager(nullptr)
										//mBitConverter(nullptr),\
											mAbstractFactory(nullptr)
{

}

inline void EmpathicEngine::mInitData(const EmpathicEngine& epEg){
	//mAbstractFactory = new AbstractFactory();
	//*mAbstractFactory = *epEg.mAbstractFactory;

	//mBitConverter = new BitConverter();
	//*mBitConverter = *epEg.mBitConverter;

	mDataSourceManager = new DataSourceManager();
	*mDataSourceManager = *epEg.mDataSourceManager;

	mServerSocket = new Server();
	*mServerSocket = *epEg.mServerSocket;
}




EmpathicEngine::EmpathicEngine(const EmpathicEngine& epEg ){
	mInitData(epEg);
}

EmpathicEngine::~EmpathicEngine(){
	//delete mAbstractFactory;
	//mAbstractFactory= nullptr;//ptr should be pointed to null to \
	//								//avoid being used after being deleted

	//delete mBitConverter;
	//mBitConverter= nullptr;

	delete mDataSourceManager;
	mDataSourceManager= nullptr;

	
	delete mServerSocket;
	mServerSocket= nullptr;
}

EmpathicEngine& EmpathicEngine::operator=(const EmpathicEngine& epEg){
	if (this != &epEg)
	{
		//if (mAbstractFactory)delete mAbstractFactory;
		//if(mBitConverter)delete mBitConverter;
		if(mDataSourceManager)delete mDataSourceManager;
		if(mServerSocket)delete mServerSocket;
		mInitData(epEg);
	}
	return *this;
}
