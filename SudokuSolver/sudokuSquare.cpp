#include "sudokuSquare.h"



SudokuSquare::SudokuSquare()
{
}


void SudokuSquare::insert(int value){
	if (value != 0) {
		definedNumber = value;
	} else {
		for (int i = 1; i < 10; i++) {
			possibleValues.push_back(i);
		}
	}
		
}

void SudokuSquare::operator=(const SudokuSquare & a){
	if (this != &a) {
		possibleValues = a.possibleValues;
		definedNumber = a.definedNumber;
	}
}

SudokuSquare::~SudokuSquare()
{
}
