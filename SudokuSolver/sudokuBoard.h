#pragma once
#include "sudokuMiniSquare.h"
class SudokuBoard
{
public:
	SudokuBoard();
	
	inline std::vector<SudokuMiniSquare> &getBoard() {
		return board;
	}
	std::vector<int> *getRawBoard();
	std::vector<SudokuSquare> *getSquareArrayOfBoard();
	void printBoard();
	~SudokuBoard();	
private:
	std::vector<SudokuMiniSquare> board;
	std::vector<SudokuSquare> *squareBoard;
	std::vector<int> *rawBoardState;
};

