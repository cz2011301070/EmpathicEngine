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

/**
@brief message code

*/

#define HEART_BEAT 0001

//#define CONNECTION 
//#define EVENT

#define SHAER_HAND 1000
#define SHAER_HEAD 1001
#define SHAER_EYE 1002
#define SHAER_VOICE 1003





