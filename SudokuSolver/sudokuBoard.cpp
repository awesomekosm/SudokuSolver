#include "sudokuBoard.h"



SudokuBoard::SudokuBoard()
{
}



std::vector<int> *SudokuBoard::getRawBoard()
{
	rawBoardState = new std::vector<int>();
	std::vector<SudokuSquare> *tempBoard = getSquareArrayOfBoard();
	for (auto x : (*tempBoard)) {
		if (x.getValue() == NULL) {
			(*rawBoardState).push_back(0);
		}
		else {
			(*rawBoardState).push_back(x.getValue());
		}
	}
	return rawBoardState;
}
//complete https://en.wikipedia.org/wiki/Jugaad 
std::vector<SudokuSquare> *SudokuBoard::getSquareArrayOfBoard() {
	squareBoard = new std::vector<SudokuSquare>();
	int counter = 0;
	//top 3 mini blocks
	while (counter <= 6) {
		for (int i = 0; i < 3; i++) {
			for (int x = counter; x < (counter+3); x++) {
				(*squareBoard).push_back(board.at(i).getSquare().at(x));
			}
		}
		counter += 3;
	}
	counter = 0;
	while (counter <= 6) {
		for (int i = 3; i < 6; i++) {
			for (int x = counter; x < (counter + 3); x++) {
				(*squareBoard).push_back(board.at(i).getSquare().at(x));
			}
		}
		counter += 3;
	}
	counter = 0;
	while (counter <= 6) {
		for (int i = 6; i < 9; i++) {
			for (int x = counter; x < (counter + 3); x++) {
				(*squareBoard).push_back(board.at(i).getSquare().at(x));
			}
		}
		counter += 3;
	}
	return squareBoard;
}

void SudokuBoard::printBoard(){
	for (auto i : board) {
		i.print();
		std::cout << " | ";
	}
}

SudokuBoard::~SudokuBoard()
{
	delete rawBoardState;
	delete squareBoard;
}
