#pragma once
#include<iostream>

enum AuthorityType {
	READ_ONLY,
	WRITE_ONLY,
	READ_AND_WRITE
};



class Filebase {
public:
	Filebase() { mAuthorityType = READ_ONLY; };
	virtual ~Filebase();

	virtual void mOpen();
	virtual void mClose();

private:
	AuthorityType mAuthorityType;
};

class XmlFile :private Filebase {

};

class JsonFile :private Filebase {

};

class INIFile :private Filebase {
public:
	INIFile();
	~INIFile();

	//mReadFile();


};









