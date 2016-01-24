#include "sudokuIO.h"



SudokuIO::SudokuIO()
{
}


void SudokuIO::printSudokuState(std::vector<int> &v)
{
	int width = 9;
	for (auto i : v) {
		if(width != 0) {
			char tempDelim;
			if ((width)% 3 == 1) {
				tempDelim = '|';
			}
			else {
				tempDelim = ' ';
			}
			std::cout << i << tempDelim;
		}
		
		else {
			std::cout << '\n';
			for (int i = 0; i < 18;i++) {
				std::cout << "-";
			}	
			width = 9;
			std::cout << '\n';
			std::cout << i << ' ';
		}
		width--;
	}	
	std::cout << '\n';
}

void SudokuIO::exportSudoku(char * fileName, std::vector<int> &v){
	std::ofstream writeTo;
	writeTo.open(fileName);
	for (auto i : v) {
		writeTo << i << ',';
	}
	writeTo.close();
}

std::vector<int> SudokuIO::newSudokuReadIn(const char *file)
{
	ReadFile readFile;
	std::vector<int> rawSudokuFile = readFile.readFile(file);


	return rawSudokuFile;
}



SudokuIO::~SudokuIO()
{
}
