#pragma once
#include <mysql.h>
#include <iostream>


#pragma comment(lib, "libmysql.lib")
#pragma comment(lib, "mysqlclient.lib")
#pragma comment(lib, "mysqlserver.lib")
#pragma comment(lib, "mysqlservices.lib")


class DBMysql
{
public:
	DBMysql();
	~DBMysql();
	/**connnetion*/
	bool mConnectDB(const char*hostName, const unsigned int port, \
		const char*userName, const char* passWord, const char* dataBaseName);
	
	/**query*/
	bool mQueryDB();

	/**add*/


	/**delete*/

	/**revise*/


	/**close connection*/

private:	
	MYSQL* mDbConn = NULL;
	char mHostName[64];
	unsigned int mPort;
	char mUserName[64];
	char mPassWord[64];
	char mDataBaseName[64];


};














