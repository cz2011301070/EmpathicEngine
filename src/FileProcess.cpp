#include "../Include/FileProcess.h"


void INIFile::mRead(const char* filePath, SplitType splitType)
{
	if (filePath) {
		ifstream infile(filePath);
		string contents, mapKey, mapValue;
		size_t index;
		if (infile.is_open()) {
			while (std::getline(infile, contents))
			{
				if (!contents.empty()) 
				{
					index= mParse(splitType,contents);
					mapKey = contents.substr(0, index);
					mapValue = contents.substr(index+1, contents.length());
					mFileContents[mapKey]= mapValue;
				}
				
			}
		}
	}
	else {
		std::cerr << "Invalid filepath of file" << std::endl;
		return;
	}
}

size_t INIFile::mParse(SplitType splitType, string line)
{
	size_t index;
	switch (splitType)
	{
	case Space:
		index= line.find_first_of(' ');
		break;
	case Pound:
		index= line.find_first_of('#');
		break;
	case Enter:
		index= line.find_first_of('\0');
		break;
	default:
		break;
	}
	return index;
}

