#pragma once
#include <vector>
#include <iostream>

class SudokuSquare
{
public:
	SudokuSquare();
	void insert(int value);
	inline int &getValue() {
		return definedNumber;
	}
	inline std::vector<int> &getPossibleValues() {
		return possibleValues;
	}
	void setValuePointer(int val) {
		*(&definedNumber) = val;
	}
	
	inline void printSquare() {
		if (!possibleValues.empty()) {
			for (auto i : possibleValues) {
				std::cout << i;
			}
		}else {
			std::cout << definedNumber;
		}
	}

	void operator=(const SudokuSquare& a);

	~SudokuSquare();
private:
	std::vector<int> possibleValues;
	int definedNumber;
};







