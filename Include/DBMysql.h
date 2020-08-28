#pragma once
#include <mysql.h>

#ifdef _DEBUG
#pragma comment(lib, "libmysqld.lib")
#else
#pragma comment(lib, "libmysql.lib")
#endif

#pragma comment(lib, "mysqlclient.lib")
#pragma comment(lib, "mysqlserver.lib")
#pragma comment(lib, "mysqlservices.lib")


class DBMysql
{
public:
	DBMysql();
	~DBMysql();
	/**connnetion*/
	bool mConnectDB();
	/**query*/
	bool mQueryDB();

	/**add*/


	/**delete*/

	/**revise*/


	/**close connection*/

private:	
	MYSQL* mMysql;
	MYSQL_FIELD* mfd;
	char mfield[32][32];
	MYSQL_RES* mRes;
	MYSQL_ROW mColumn;
	char mQuery[150];

};














