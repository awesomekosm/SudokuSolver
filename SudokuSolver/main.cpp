#include "SudokuProcessor.h"
#include <string>



int main() {
	
	char input;
	bool running = true;
	unsigned int capItteration;
	std::string fileName;
	while (running == true) {
		std::cout << "Press 1  to run default Sudoku Puzzle ""sudoku.txt"" \n";
		std::cout << "Press 2  to run Sudoku Puzzle with your custom .txt input \n";
		std::cout << "Press q  to Exit\n";
		std::cout << "Your selection: ";
		std::cin >> input;
		if (input == '1') {
			std::cout << "Enter Itteration Cap, How many times do you want sudoku algorithm to run?\n(30) is default, type \"0\" to default\n";
			std::cin >> capItteration;
			if (capItteration != 30) {
				SudokuProcessor sudokuProcessor("sudoku.txt", capItteration);
			} else {
				SudokuProcessor sudokuProcessor("sudoku.txt", 30);
			}
		}
		if (input == '2') {
			std::cout << "Enter your Sudoku Puzzle .txt \n";
			std::cin >> fileName;
			std::cout << "Enter Itteration Cap, How many times do you want sudoku algorithm to run?\n(30) is default, type \"0\" to default\n";
			std::cin >> capItteration;
			if (capItteration == NULL) {
				SudokuProcessor sudokuProcessor(fileName.c_str(), 30);
			} else {
				SudokuProcessor sudokuProcessor(fileName.c_str(), capItteration);
			}
		}
		if (input == 'q') {
			running = false;
			return 0;
		}
	}


	system("pause");
}

