#pragma once
#include "ReadFile.h"
#include <vector>

class SudokuIO
{
public:
	SudokuIO();

	void printSudokuState(std::vector<int> &v);
	void exportSudoku(char *fileName, std::vector<int> &v);
	std::vector<int> newSudokuReadIn(const char *file);

	~SudokuIO();
};

