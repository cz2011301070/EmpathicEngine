#include"../Include/ByteConverter.h"

//template <class T>
//void ByteConverter<T>::mPacking(char* buff, int& index, const T value)
//{
//	char* buffer = new char();
//	stringstream temp;
//	temp << value;
//	temp >> buffer;
//
//	memcpy_s(buff, index+sizeof(value), buffer, sizeof(value));
//
//	delete buffer;
//	buffer = NULL;
//
//}
//template <class T>
//void ByteConverter<T>::mUnpacking(char* buff, int& index, T& value)
//{
//	char* buffer = new char();
//	memcpy_s(buffer, sizeof(index), buff, index + sizeof(index));
//
//}
