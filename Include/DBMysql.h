#pragma once
#include <mysql.h>

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














