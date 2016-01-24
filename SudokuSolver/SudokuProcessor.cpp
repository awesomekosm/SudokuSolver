#include "SudokuProcessor.h"


bool isSolved(std::vector<int> &rawBoard) {
	for (auto i : rawBoard) {
		if (i == 0) {
			return false;
		}
	}
	return true;
}
std::vector<SudokuSquare> loadSquares(std::vector<int> &initSudoku) {
	std::vector<SudokuSquare> finalSquares;
	for (int i = 0; i < initSudoku.size(); i++) {
		SudokuSquare square;
		square.insert(initSudoku.at(i));
		finalSquares.push_back(square);
	}
	return finalSquares;
}
void initSquares(std::vector<SudokuMiniSquare> &finalMiniSquares, std::vector<SudokuSquare> &squares) {
	
}

std::vector<SudokuMiniSquare> loadMiniSquares(std::vector<SudokuSquare> &squares) {
	std::vector<SudokuMiniSquare> finalMiniSquares;
	for (int i = 0; i < 9; i++) {
		SudokuMiniSquare miniSqare;
		finalMiniSquares.push_back(miniSqare);
	}

	std::vector<int> itter = { 0,1,2,9,10,11,18,19,20 };
	std::vector<int> itter1 = { 27,28,29,36,37,38,45,46,47 };
	std::vector<int> itter2 = { 54,55,56,63,64,65,72,73,74 };
	for (int i = 0; i < 9;i++) {
		for (int x = 0;x < 9; x++) {
			finalMiniSquares.at(i).getSquare().push_back(squares.at(itter.at(x)));
		}
		for (int z = 0; z < 9; z++) {
			itter.at(z) += 3;
		}
		if (((i + 1) % 3) == 0) {
			itter = itter1;
		}
		if (((i + 1) % 6) == 0) {
			itter = itter2;
		}
	}

	return finalMiniSquares;
}
SudokuBoard loadBoard(std::vector<SudokuMiniSquare> &miniSquares) {
	SudokuBoard finalBoard;
	for (auto i : miniSquares) {
		finalBoard.getBoard().push_back(i);
	}
	return finalBoard;
}
inline void removeExtraZeroes(std::vector<int> &values) {
	std::vector<int> temp;
	for (auto i : values) {
		if (i != 0) {
			temp.push_back(i);
		}
	}
	values = temp;
}
void removeValueFromEmptySquareThatExistsInMiniSquare(std::vector<int> &temp, SudokuBoard &board, int x, int y) {
	std::vector<int> *possibleValues = &board.getBoard().at(x).getSquare().at(y).getPossibleValues();
	for (int i = 0; i < temp.size();i++) {
		for (int z = 0; z < (*possibleValues).size(); z++) {
			if (temp.at(i) == (*possibleValues).at(z)) {
				(*possibleValues).at(z) = 0;
				removeExtraZeroes(*possibleValues);
			}
			
		}
	}
}
//get back a value that doesn't have a duplicate
int getNoneRepeatingValue(std::vector<int> &comboVector) {
	std::sort(comboVector.begin(), comboVector.end());
	for (int i = 0; i < comboVector.size()-1; i++) {
		if (comboVector.at(i) == comboVector.at(i+1)) {
			do {
				i++;
			} while (i < (comboVector.size()-1) && comboVector.at(i) == comboVector.at(i+1)); //increment i while numbers are not unique
		}
		else {
			return comboVector.at(i); //unique somewhere
		}
	}
	if (comboVector.at(comboVector.size() - 1) != comboVector.at(comboVector.size() - 2)) {
		return (comboVector.at(comboVector.size()-1)); //last unique
	}
	
	return 0; //no nonrepeating
}
void setAValueForASquareWithUnique(SudokuBoard &board,int x, int unique) {
	std::vector<SudokuSquare> *ptrSquares = &board.getBoard().at(x).getSquare();
	for (int i = 0; i < (*ptrSquares).size(); i ++) {
		if ((*ptrSquares).at(i).getValue() == NULL) {
			if (std::find((*ptrSquares).at(i).getPossibleValues().begin(), (*ptrSquares).at(i).getPossibleValues().end(), unique) != (*ptrSquares).at(i).getPossibleValues().end()) {
				(*ptrSquares).at(i).getValue() = unique; //I had this == and spent about an hour debugging why it wasn't setting the value... INSANE
				(*ptrSquares).at(i).getPossibleValues().clear();
			}
		}
	}
}

void lookForEmptySlots(SudokuBoard &board) {
	std::vector<int> temp;

	for (int x = 0; x < board.getBoard().size();x++) {
		for (int y = 0; y < board.getBoard().at(x).getSquare().size(); y++) { //adds all the values that exist in the square
			if (board.getBoard().at(x).getSquare().at(y).getValue() != NULL) { //has a value
				temp.push_back(board.getBoard().at(x).getSquare().at(y).getValue()); //value exists add it to temp vector to remove from empty spot
			}
		}
		for (int y = 0; y < board.getBoard().at(x).getSquare().size(); y++) { //removes invalid values from individual 9 mini squares
			if (board.getBoard().at(x).getSquare().at(y).getValue() == NULL) { //has no value
				removeValueFromEmptySquareThatExistsInMiniSquare(temp, board, x, y);
			}
		}
		temp.clear();
	}
}

std::vector<SudokuSquare> getRow(std::vector<SudokuSquare> *boardSquares, int rowNumber) {
	int adder = 9 * rowNumber;
	std::vector<int> itter = { 0,1,2,3,4,5,6,7,8 };
	std::vector<SudokuSquare> finalRow;
	SudokuSquare tempSqare;
	//set itterator array
	for (int i = 0; i < 9;i++) {
		itter.at(i) = itter.at(i) + adder;
	}
	for (auto i:itter) {
		tempSqare = (*boardSquares).at(i);
		finalRow.push_back(tempSqare);
	}

	return finalRow;
}
std::vector<SudokuSquare> getColumn(std::vector<SudokuSquare> *boardSquares, int colNumber) {
	std::vector<int> itter = { 0,9,18,27,36,45,54,63,72 };
	std::vector<SudokuSquare> finalCol;
	SudokuSquare tempSqare;
	//set itterator array
	for (int i = 0; i < 9;i++) {
		itter.at(i) = itter.at(i) + colNumber;
	}
	for (auto i : itter) {
		tempSqare = (*boardSquares).at(i);
		finalCol.push_back(tempSqare);
	}
	return finalCol;
}

void checkValidSquare(SudokuBoard &board) {

	for (int x = 0; x < board.getBoard().size();x++) {
		for (int y = 0; y < board.getBoard().at(x).getSquare().size(); y++) {
			if (board.getBoard().at(x).getSquare().at(y).getValue() == NULL && board.getBoard().at(x).getSquare().at(y).getPossibleValues().size()==1) {
				board.getBoard().at(x).getSquare().at(y).getValue() = board.getBoard().at(x).getSquare().at(y).getPossibleValues().at(0);
			}
		}
	}
}
void removePossibleValuesIfPresentInRowOrColumn(std::vector<int> &temporaryRowOrColumn, std::vector<int> &possibleValues) {
	for (int i = 0; i < temporaryRowOrColumn.size();i++) {
		for (int z = 0; z < possibleValues.size(); z++) {
			if (temporaryRowOrColumn.at(i) == possibleValues.at(z)) {
				possibleValues.at(z) = 0;
				removeExtraZeroes(possibleValues);
			}

		}
	}
}
void lookForColumnRowEmptySlots(SudokuBoard &board) {
	std::vector<SudokuSquare> *boardSquares = board.getSquareArrayOfBoard();
	std::vector<int> temporaryRow;
	std::vector<int> temporaryColumn;
	int tempRowColValue;
	for (int x = 0; x < board.getBoard().size();x++) {
		for (int y = 0; y < board.getBoard().at(x).getSquare().size(); y++) {
			if (board.getBoard().at(x).getSquare().at(y).getValue() == NULL) {
				//composeRowValue && get a row
				for (auto i : getRow(boardSquares, ColAndRowUtil::composeRowValue(x, y))) {
					//pushValues into temporaryRow of values that exist
					if (i.getValue() != NULL) {
						temporaryRow.push_back(i.getValue());
					}
				}
				//remove values in board.getBoard().at(x).getSquare().at(y).getPossibleValues() that are present in temporaryRow
				//removeExtraZeroes(*possibleValues);
				removePossibleValuesIfPresentInRowOrColumn(temporaryRow, board.getBoard().at(x).getSquare().at(y).getPossibleValues());
				temporaryRow.clear();

				//composeColumnValue && get column
				for (auto i : getColumn(boardSquares, ColAndRowUtil::composeColumnValue(x, y))) {
					//pushValues into temporaryColumn of values that exist
					if (i.getValue() != NULL) {
						temporaryColumn.push_back(i.getValue());
					}
				}
				//remove values in board.getBoard().at(x).getSquare().at(y).getPossibleValues() that are present in temporaryColumn
				//removeExtraZeroes(*possibleValues);
				removePossibleValuesIfPresentInRowOrColumn(temporaryColumn, board.getBoard().at(x).getSquare().at(y).getPossibleValues());
				temporaryColumn.clear();
			}
		}
	}
}


void removeNoneUniqueNumbersFromZeroSquares(SudokuBoard &board) {
	std::vector<int> comboVector;
	for (int x = 0; x < board.getBoard().size(); x++) {
		/*idea - look for empty spots, check remaining numbers. store that spot in a temporary vector and compare it with every other empty slot's vector in a mini square.
		if a the current slot has a number that is not present in any other empty slots, that must be the number for this empty slot.
		TIME FOR A COMBO VECTOR CAN THIS GET ANY MORE COMPLICATED, I AM SURE THERE IS AN EASIER WAY... KAPPA!*/
		for (int y = 0; y < board.getBoard().at(x).getSquare().size(); y++) {
			//taking all the squares that are 0 with possible values, 0 value of the array will be the first value compared against all the other values
			if (board.getBoard().at(x).getSquare().at(y).getValue() == NULL) {
				//add each 0 slot possible values into a single array to find unique
				for (auto i : board.getBoard().at(x).getSquare().at(y).getPossibleValues()) {
					comboVector.push_back(i);
				}
			}
		}
		if (comboVector.size() > 1) { //check valid square will make sure to set the square with a value if it is the last slot that needs to be filled in a 3x3
			int theUNIQUE = getNoneRepeatingValue(comboVector);
			if (theUNIQUE != 0) {
				setAValueForASquareWithUnique(board, x, theUNIQUE);
			}
			comboVector.clear();
		}
	}
}

typedef std::chrono::high_resolution_clock Clock;
SudokuProcessor::SudokuProcessor(const char *file, int capItteration)
{
	SudokuIO sudokuRaw;
	std::vector<int> vec = sudokuRaw.newSudokuReadIn(file);
	std::vector<SudokuSquare> squares = loadSquares(vec);
	std::vector<SudokuMiniSquare> miniSquares = loadMiniSquares(squares);
	SudokuBoard board = loadBoard(miniSquares);
	
	int tries = 0;
	auto s = Clock::now();
	while (!isSolved(*(board.getRawBoard()))) {
		tries++;
		lookForEmptySlots(board); // first check from each empty spot and figure out which numbers cannot exist in a miniSquare 3*3
		lookForColumnRowEmptySlots(board);//check rows and columns for 0 values further reducing number of possible numbers that go into those 0 slots
		removeNoneUniqueNumbersFromZeroSquares(board); //I spent days playing sudoku until I noticed, thanks "2" you really stood out as A UNIQUE out of a sea of scum possible values.
		checkValidSquare(board);//sets values where 0's possible values are size of 1, no other number can go in except for .at(0)
		
		/*std::cout << "\n-----";
		board.printBoard();        was used for debug... can see itterational changes
		std::cout << "\n";*/
		if (tries == capItteration) {
			break;
		}
	}
	auto e = Clock::now();
	unsigned long difference = std::chrono::nanoseconds(e - s).count();

	sudokuRaw.printSudokuState(*(board.getRawBoard()));
	std::cout << tries << " itterations in " <<difference << " Nanoseconds or " << difference/1000000 <<" Milliseconds\n";
}

SudokuProcessor::~SudokuProcessor()
{
}