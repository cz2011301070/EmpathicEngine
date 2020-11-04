#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;
enum AuthorityType 
{
	READ_ONLY,
	WRITE_ONLY,
	READ_AND_WRITE
};
enum SplitType
{
	Space,
	Pound,
	Enter
};

class Filebase 
{
public:
	Filebase() { };
	virtual ~Filebase() {};

	virtual void mRead(const char* filePath, SplitType splitType)=0;
	virtual size_t mParse(SplitType splitType, string line)= 0;
	//virtual void mWrite(char* filePath, std::string fileContent);
	map<string,string> mFileContents;
	
};

class XmlFile :public Filebase
{

};

class JsonFile :public Filebase 
{

};

class INIFile :public Filebase 
{
public:
	INIFile() {};
	~INIFile() {};

	void mRead(const char* filePath, SplitType splitType);
	size_t mParse(SplitType splitType, string line);
};









