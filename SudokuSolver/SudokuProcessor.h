#pragma once
#include "sudokuIO.h"
#include "sudokuBoard.h"
#include "sudokuMiniSquare.h"
#include "sudokuSquare.h"
#include "ColAndRowUtil.h"
#include <algorithm>
#include <ctime>
#include <chrono>

class SudokuProcessor
{
public:
	SudokuProcessor(const char *file, int capItteration);
	~SudokuProcessor();
private:
	SudokuBoard board;
	SudokuMiniSquare minSquare;
	SudokuSquare square;
};

