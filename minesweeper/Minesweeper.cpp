#include"Minesweeper.h"
#include <cstdlib>

// Initializing static variables
string Minesweeper::FLAG = "@";
string Minesweeper::MINE = "#";
string Minesweeper::HIDDEN_CELL = "-";
string Minesweeper::FREE_CELL = " ";

Minesweeper::Minesweeper(GameParameters& gp) {
	rows = gp.rows;
	columns = gp.columns;
	difficulty = gp.difficulty;

	board = allocateMatrix(rows, columns);
	visible = allocateMatrix(rows, columns);
	flagged = allocateMatrix(rows, columns);

	terminal = new TerminalColoring();

	cursorRow = 0;
	cursorColumn = 0;
	gameOver = false;

	initBoard();
}

Minesweeper::~Minesweeper() {
	deallocateMatrix(board, rows, columns);
	deallocateMatrix(visible, rows, columns);
	deallocateMatrix(flagged, rows, columns);
}

int** Minesweeper::allocateMatrix(int rows, int columns) {
	int** mat = new int*[rows];
	for (int i = 0; i < rows; i++) {
		mat[i] = new int[columns]();
	}

	return mat;
}

void Minesweeper::deallocateMatrix(int **mat, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		delete[] mat[i];
	}

	delete[] mat;
}


// Logic for printing console game board
string Minesweeper::pad(string info, int row, int column) {
	string leftPad = " ";
	string rightPad = " ";

	if (cursorRow == row && cursorColumn == column) {
		leftPad = "<";
		rightPad = ">";
	}

	return leftPad + info + rightPad;
}

string Minesweeper::pad(int info, int row, int column) {
	return pad(to_string(info), row, column);
}

bool Minesweeper::isMine(int row, int column) {
	return (board[row][column] == Mine);
}

bool Minesweeper::isFree(int row, int column) {
	return (board[row][column] == Free);
}

bool Minesweeper::isFlagged(int row, int column) {
	return (flagged[row][column] == 1);
}

bool Minesweeper::isVisible(int row, int column) {
	return visible[row][column] == 1;
}

void Minesweeper::printMine(int row, int column) {
	string element = pad(MINE, row, column);
	print(element, terminal->RED);
}

void Minesweeper::printFlag(int row, int column) {
	string element = pad(FLAG, row, column);
	print(element, terminal->GREEN);
}

void Minesweeper::printFreeCell(int row, int column) {
	string element = pad(FREE_CELL, row, column);
	cout << element;
}

void Minesweeper::printMinesNumber(int row, int column) {
	string element = pad(board[row][column], row, column);
	print(element, terminal->BLUE);
}

void Minesweeper::print(string element, int colour) {
	terminal->printColored(element, colour);
}

void Minesweeper::printBoardCell(int row, int column) {
	if (isVisible(row, column)) {
		if (isMine(row, column)) {
			printMine(row, column);
		}
		else if (isFree(row, column)) {
			printFreeCell(row, column);
		}
		else {
			printMinesNumber(row, column);
		}
	}
	else if (isFlagged(row,column)) {
		if (isGameOver() && isMine(row, column)) {
			printMine(row, column);
		}
		else {
			printFlag(row, column);
		}
	}
	else {
		// either the game is over or the player has won
		if (isGameOver() && isMine(row, column)) {
			printMine(row, column);
		}
		else {
			cout << pad(HIDDEN_CELL, row, column);
		}
	}
}

void Minesweeper::printSpaces(int spaces = 5) {
	for (int i = 0; i < spaces; i++) {
		cout << " ";
	}
}

void Minesweeper::printHorizontalBorder() {
	printSpaces();
	for (int i = 0; i < (columns * 3) + 2; i++) {
		cout << "-";
	}
	cout << '\n';
}

void Minesweeper::printBoard() {
	cout << '\n';
	printHorizontalBorder();

	for (int i = 0; i < rows; i++) {
		printSpaces(4);
		cout << "|" << " ";
		for (int j = 0; j < columns; j++) {
			printBoardCell(i, j);

		}
		cout << " " << "|";
		cout << '\n';
	}

	printHorizontalBorder();
	printBoardInfo();
}

void Minesweeper::printBoardInfo() {
	int green = 10;
	cout << '\n';
	printSpaces(5);
	terminal->printColored("MINESWEEPER INFO", terminal->GREEN);
	cout << '\n' << '\n';
	printSpaces(5);
	cout << "Cursor moves: UP, DOWN, LEFT, RIGHT" << '\n';
	printSpaces(5);
	cout << "Reveal cell: SPACE" << '\n';
	printSpaces(5);
	cout << "Flag cell: f" << '\n';
	printSpaces(5);
	cout << "Percentage of mines: " << difficulty << "%" << '\n';
	printSpaces(5);
	cout << "Remaining cells: " << countFreeCells() << '\n';
}

void Minesweeper::clearConsoleFrame() {
	system("cls");
}

void Minesweeper::updateConsoleFrame() {
	clearConsoleFrame();
	printBoard();
}

void Minesweeper::startGame() {
	updateConsoleFrame();
}


// Logic for random mines placement and game initializing
bool Minesweeper::placeMine() {
	int randomNumber = rand() % 100;
	return (randomNumber < difficulty);
}

void Minesweeper::placeMines() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (placeMine()) {
				board[i][j] = Mine;
			}
			else {
				board[i][j] = Free;
			}
		}
	}
}

bool Minesweeper::inBoard(int row, int column) {
	return (row < rows && row >= 0 && column < columns && column >= 0);
}

int Minesweeper::countMines(int row, int column) {
	int count = 0;

	for (int i = 0; i < 8; i++) {
		int x = row + dx[i];
		int y = column + dy[i];

		if (inBoard(x, y)) {
			if (isMine(x,y)) {
				count++;
			}
		}
	}

	return count;
}

void Minesweeper::placeMineCounters() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (isFree(i,j)) { 
				board[i][j] = countMines(i, j);
			}
		}
	}
}

void Minesweeper::initBoard() {
	placeMines();
	placeMineCounters();
}


// Logic for revealing all adjacent squares
void Minesweeper::expandSelection(int row, int column) {
	visible[row][column] = 1;

	if (isFree(row, column)) {
		for (int i = 0; i < 8; i++) {
			int x = row + dx[i];
			int y = column + dy[i];
	
			if (inBoard(x, y)) {
				if (!isMine(x,y) && visible[x][y] == 0) {
					expandSelection(x, y);
				}
			}
		}
	}
}


// Logic for making next move
void Minesweeper::nextMove(Coordinates c) {
	expandSelection(c.x, c.y);

	if (isMine(c.x,c.y)) {
		gameOver = true;
	}

	updateConsoleFrame();
}

void Minesweeper::nextMove() {
	Coordinates c(cursorRow, cursorColumn);
	nextMove(c);
}


// Logic for cursor moving in game board
void Minesweeper::up() {
	if (cursorRow > 0) {
		cursorRow--;
	}
	updateConsoleFrame();
}

void Minesweeper::right() {
	if (cursorColumn < columns - 1) {
		cursorColumn++;
	}
	updateConsoleFrame();
}
void Minesweeper::down() {
	if (cursorRow < rows - 1) {
		cursorRow++;
	}
	updateConsoleFrame();
}
void Minesweeper::left() {
	if (cursorColumn > 0) {
		cursorColumn--;
	}
	updateConsoleFrame();
}

void Minesweeper::flag() {
	if (isFlagged(cursorRow, cursorColumn)) {
		flagged[cursorRow][cursorColumn] = 0;
	}
	else {
		flagged[cursorRow][cursorColumn] = 1;
	}
	
	updateConsoleFrame();
}


// Logic for ending game
int Minesweeper::countFreeCells() {
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (!isMine(i,j) && !visible[i][j]) {
				count++;
			}
		}
	}
	return count;
}

bool Minesweeper::winner() {
	return (countFreeCells() == 0);
}

bool Minesweeper::isGameOver(){
	return gameOver;
}

bool Minesweeper::finished() {
	return (winner() || isGameOver());
}