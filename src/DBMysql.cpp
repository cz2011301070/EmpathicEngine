#include "../Include/DBMysql.h"

DBMysql::DBMysql()
{
	mMysql= new MYSQL;
	mMysql= nullptr;

	mfd= new MYSQL_FIELD;
	mfd= nullptr;

	ZeroMemory(mfield,sizeof(mfield));

	mRes= new MYSQL_RES;
	mRes= nullptr;

	ZeroMemory(mQuery,sizeof(mQuery));
}

bool DBMysql::mConnectDB()
{

	return true;
}

bool DBMysql::mQueryDB()
{

	return true;
}








