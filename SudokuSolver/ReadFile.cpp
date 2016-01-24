#include "ReadFile.h"


std::vector<int> ReadFile::readFile(const char * fileName)
{
	std::vector<int> readInNumbers;
	std::string str;
	std::ifstream file(fileName);

	while (!file.eof()) {
		std::getline(file,str);
		for (auto i:str) {
			if (i != 44) {
				readInNumbers.push_back(std::atoi(&i));
			}
		}
	}
	file.close();
	return readInNumbers;
}
