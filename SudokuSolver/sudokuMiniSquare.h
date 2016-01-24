#pragma once
#include "sudokuSquare.h"

class SudokuMiniSquare
{
public:
	SudokuMiniSquare();
	void insertSquare(SudokuSquare &square);
	
	inline std::vector<SudokuSquare> &getSquare() {
		return setSquare;
	}
	
	inline void print() {
		for (auto i : setSquare) {
			i.printSquare();
			std::cout << ' ';
		}
	}

	~SudokuMiniSquare();
private:
	std::vector<SudokuSquare> setSquare;
};
