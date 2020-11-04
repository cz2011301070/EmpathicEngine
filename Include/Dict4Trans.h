#pragma once
/**
@brief Maximum size of buffer, message type etc..

*/
#define MAXBUFFERSIZE 4096
static char buffer[MAXBUFFERSIZE];


enum ClientType{
	AndroidPhone,
	UWPHololens,
	WindowsCamera,
	WindowsHTC,
	WindowsPC,
	WindowsProjector
};
enum DataSourceType{
	XML,
	Json,
	DataBase
};





