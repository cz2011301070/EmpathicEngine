#include "../Include/DBMysql.h"

DBMysql::DBMysql()
{
	mPort = 0;

	memset(mHostName, 0, 64);
	
	memset(mUserName, 0, 64);
	memset(mPassWord, 0, 64);
	memset(mDataBaseName, 0, 64);
}

bool DBMysql::mConnectDB(const char* hostName, const unsigned int port, \
	const char* userName, const char* passWord, const char* dataBaseName)
{
	memset(mHostName, 0, 64);
	memset(mUserName, 0, 64);
	memset(mPassWord, 0, 64);
	memset(mDataBaseName, 0, 64);

	memcpy(mHostName, hostName, strlen(hostName));
	mPort = port;
	memcpy(mUserName, userName, strlen(userName));
	memcpy(mPassWord, passWord, strlen(passWord));
	memcpy(mDataBaseName, dataBaseName, strlen(dataBaseName));

	

	this->mDbConn = mysql_init(NULL);
	//const char* s = mysql_error(mDbConn);

	mysql_options(this->mDbConn, MYSQL_OPT_CONNECT_TIMEOUT, "30");//seconds
	mysql_options(this->mDbConn, MYSQL_OPT_READ_TIMEOUT, "60");//seconds
	mysql_options(this->mDbConn, MYSQL_OPT_WRITE_TIMEOUT, "60");//seconds
	mysql_options(this->mDbConn, MYSQL_OPT_RECONNECT, "1");//open reconnect function

	try
	{
		if (!mysql_real_connect(this->mDbConn, hostName, userName, passWord, dataBaseName, port, nullptr, 0))
		{
			throw true;
		}
		return true;
	}
	catch (bool err)
	{
		if (err)
		{
			std::cerr << "Failed to connect database!" << std::endl;
			return false;
		}
	}
	
}

bool DBMysql::mQueryDB()
{

	return true;
}

DBMysql::~DBMysql()
{
	mysql_close(mDbConn);
	delete mDbConn;
	mDbConn = nullptr;
}






