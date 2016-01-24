#include "sudokuMiniSquare.h"



SudokuMiniSquare::SudokuMiniSquare(){
	
}

void SudokuMiniSquare::insertSquare(SudokuSquare & square)
{
	if (setSquare.size() < 9) {
		setSquare.push_back(square);
	}
}



SudokuMiniSquare::~SudokuMiniSquare(){

}
