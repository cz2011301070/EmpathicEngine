#pragma once
/*
* @author changzhuang
* @date 2021.01.16
* @version v1.0
* @brief 
			1. Convert int, float,double data to byte array
			2. Convert selfdefined data to byte array
			3. Convert vector, map and list varibles to byte array
			4. Users should define int index=0
			5. Pack and UnPack data size should less than 4096
* 
*/
#include"../Include/Dict4Trans.h"
#include<sstream>//lib for type transformation to string
#include<cstring>
#include<map>
#include<vector>
#include<list>
#include<iostream>
using namespace std;

template<class T>
class ByteConverter
{
public:
	static void mPacking(char* buff, int& index, const T& value);
	static void mUnpacking(const char* buff, int& index,T& value);

};

template<class KT, class T>
class Map2Byte : public ByteConverter<T>
{
public:
	static void mPacking(char* buff, int& index, const map<KT,T>& value);
	static void mUnpacking(const char* buff, int& index, map<KT, T>& value);
	
};

template<class T>
class Vector2Byte : public ByteConverter<T>
{
public:
	static void mPacking(char* buff, int& index, const vector<T> value);
	static void mUnpacking(const char* buff, int& index, vector<T>& value);
};

template<class T>
class List2Byte : public ByteConverter<T>
{
public:
	static void mPacking(char* buff, int& index, const list<T> value);
	static void mUnpacking(const char* buff, int& index, list<T>& value);
};

template<class T>
void ByteConverter<T>::mPacking(char* buff, int& index, const T& value)
{
	if (index > MAXBUFFERSIZE)
	{
		cerr << "ByteConverter<T>::mPacking: Packed data bigger than MAXBUFFERSIZE" << endl;
		exit(1);
	}
	else
	{
		memcpy_s(&(buff[index]), sizeof(T), &value, sizeof(T));
		index += sizeof(T);
	}
	

}

template<class T>
void ByteConverter<T>::mUnpacking(const char* buff, int& index, T& value)
{
	
	if (index >= MAXBUFFERSIZE)
	{
		cerr << "ByteConverter<T>::mUnpacking: Packed data bigger than MAXBUFFERSIZE" << endl;
		exit(1);
	}
	else
	{
		memcpy_s(&value, sizeof(T), &(buff[index]), sizeof(T));
		index += sizeof(T);
	}
	
}

template<class KT, class T>
void Map2Byte<KT,T>::mPacking(char* buff, int& index, const map<KT, T>& value)
{
	if (index > MAXBUFFERSIZE)
	{
		cerr << "Map2Byte<KT,T>::mPacking: Packed data bigger than MAXBUFFERSIZE" << endl;
		exit(1);
	}
	else
	{
		map<KT, T>::const_iterator it = value.begin();
		while (it != value.end())
		{
			memcpy_s(&(buff[index]), sizeof(KT), &(it->first), sizeof(KT));
			index += sizeof(KT);

			memcpy_s(&(buff[index]), sizeof(T), &(it->second), sizeof(T));
			index += sizeof(T);

			it++;
			
		}
		
		
	}
}

template<class KT, class T>
void Map2Byte<KT, T>::mUnpacking(const char* buff, int& index, map<KT, T>& value)
{
	if (index > MAXBUFFERSIZE)
	{
		cerr << "Map2Byte<KT,T>::mPacking: Packed data bigger than MAXBUFFERSIZE" << endl;
		exit(1);
	}
	else
	{
		KT keyTemp;
		T valueTemp;
		memcpy_s(&keyTemp, sizeof(KT), &(buff[index]), sizeof(KT));
		index += sizeof(KT);
		
		memcpy_s(&valueTemp, sizeof(T), &(buff[index]), sizeof(T));
		index += sizeof(T);

		value[keyTemp] = valueTemp;

	}
}

template<class T>
void Vector2Byte<T>::mPacking(char* buff, int& index, const vector<T> value)
{
	if (index > MAXBUFFERSIZE)
	{
		cerr << "Vector2Byte<T>::mPacking: Packed data bigger than MAXBUFFERSIZE" << endl;
		exit(1);
	}
	else
	{
		vector<T>::const_iterator it = value.begin();
		while (it != value.end())
		{
			memcpy_s(&(buff[index]), sizeof(T), &(*it), sizeof(T));
			index += sizeof(T);

			it++;

		}

	}
}

template<class T>
void Vector2Byte<T>::mUnpacking(const char* buff, int& index, vector<T>& value)
{
	if (index > MAXBUFFERSIZE)
	{
		cerr << "Vector2Byte<T>::mUnpacking: Packed data bigger than MAXBUFFERSIZE" << endl;
		exit(1);
	}
	else
	{
		T valueTemp;
		
		memcpy_s(&valueTemp, sizeof(T), &(buff[index]), sizeof(T));
		index += sizeof(T);

		value.push_back(valueTemp);

	}
}

template<class T>
void List2Byte<T>::mPacking(char* buff, int& index, const list<T> value)
{
	if (index > MAXBUFFERSIZE)
	{
		cerr << "List2Byte<T>::mPacking: Packed data bigger than MAXBUFFERSIZE" << endl;
		exit(1);
	}
	else
	{
		list<T>::const_iterator it = value.begin();
		while (it != value.end())
		{
			memcpy_s(&(buff[index]), sizeof(T), &(*it), sizeof(T));
			index += sizeof(T);

			it++;

		}

	}
}

template<class T>
void List2Byte<T>::mUnpacking(const char* buff, int& index, list<T>& value)
{
	if (index > MAXBUFFERSIZE)
	{
		cerr << "List2Byte<T>::mUnpacking: Packed data bigger than MAXBUFFERSIZE" << endl;
		exit(1);
	}
	else
	{
		T valueTemp;

		memcpy_s(&valueTemp, sizeof(T), &(buff[index]), sizeof(T));
		index += sizeof(T);

		value.push_back(valueTemp);

	}
}





