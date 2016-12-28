#include"Minesweeper.h"
#include <cstdlib>

Minesweeper::Minesweeper(GameParameters& gp) {
	rows = gp.rows;
	columns = gp.columns;
	difficulty = Easy;

	board = allocateMatrix(rows, columns);
	visible = allocateMatrix(rows, columns);
	flagged = allocateMatrix(rows, columns);
	
	cursorRow = 0;
	cursorColumn = 0;
	initBoard();
	score = 0;

	gameOver = false;
}

int** Minesweeper::allocateMatrix(int rows, int columns) {
	int** mat = new int*[rows];
	for (int i = 0; i < rows; i++) {
		mat[i] = new int[columns]();
	}

	return mat;
}

/* ----------------------------------------------- */

string Minesweeper::pad(int info, int row, int column) {
	return pad(to_string(info), row, column);
}

string Minesweeper::pad(string info, int row, int column) {
	string leftPad = " ";
	string rightPad = " ";

	if (cursorRow == row && cursorColumn == column) {
		leftPad = "<";
		rightPad = ">";
	}

	return leftPad + info + rightPad;
}

void Minesweeper::printBoardCell(int row, int column) {
	if (visible[row][column] == 1) {
		if (board[row][column] == Mine) {
			cout << pad("#", row, column);
		}
		else if (board[row][column] == Free) {
			cout << pad(" ", row, column);
		}
		else {
			cout << pad(board[row][column], row, column);
		}
	}
	else if (flagged[row][column] == 1) {
		if (isGameOver() && board[row][column] == Mine) {
			cout << pad("#", row, column);
		}
		else {
			cout << pad("?", row, column);
		}
	}
	else {
		if (isGameOver() && board[row][column] == Mine) {
			cout << pad("#", row, column);
		}
		else {
			cout << pad("-", row, column);
		}
	}
}

void Minesweeper::printHorizontalBorder() {
	cout << " ";
	for (int i = 0; i < (columns * 3) + 2; i++) {
		cout << "-";
	}
	cout << endl;
}

void Minesweeper::printBoard() {
	printHorizontalBorder();

	for (int i = 0; i < rows; i++) {
		cout << "|" << " ";
		for (int j = 0; j < columns; j++) {
			printBoardCell(i, j);
		}
		cout << " " << "|";
		cout << endl;
	}

	printHorizontalBorder();
}

void Minesweeper::clearConsoleFrame() {
	system("cls");
}

void Minesweeper::updateConsoleFrame() {
	clearConsoleFrame();
	printBoard();
}

void Minesweeper::startGame() {
	clearConsoleFrame();
	updateConsoleFrame();
}

/* ----------------------------------------------- */

bool Minesweeper::placeMine() {
	int v = rand() % 100;
	return (v < difficulty);
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

int Minesweeper::countMines(int row, int column) {
	int count = 0;

	for (int i = 0; i < 8; i++) {
		int x = row + dx[i];
		int y = column + dy[i];

		if (inBoard(x, y)) {
			if (board[x][y] == Mine) {
				count++;
			}
		}
	}

	return count;
}

void Minesweeper::placeMineCounters() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (board[i][j] == Free) { 
				board[i][j] = countMines(i, j);
			}
		}
	}
}

void Minesweeper::initBoard() {
	placeMines();
	placeMineCounters();
}


/* ----------------------------------------------- */

bool Minesweeper::inBoard(int row, int column) {
	return (row < rows && row >= 0 && column < columns && column >= 0);
}

void Minesweeper::expandSelection(int row, int column) {
	visible[row][column] = 1;

	if (board[row][column] == Free) {
		for (int i = 0; i < 8; i++) {
			int x = row + dx[i];
			int y = column + dy[i];
	
			if (inBoard(x, y)) {
				if (board[x][y] != Mine && visible[x][y] == 0) {
					expandSelection(x, y);
				}
			}
		}
	}
}

void Minesweeper::nextMove(Coordinates c) {
	expandSelection(c.x, c.y);

	if (board[c.x][c.y] == Mine) {
		gameOver = true;
	}

	updateConsoleFrame();
}

void Minesweeper::nextMove() {
	Coordinates c(cursorRow, cursorColumn);
	nextMove(c);
}

/* ----------------------------------------------- */

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
	if (flagged[cursorRow][cursorColumn] == 1) {
		flagged[cursorRow][cursorColumn] = 0;
	}
	else {
		flagged[cursorRow][cursorColumn] = 1;
	}
	
	updateConsoleFrame();
}

/* ----------------------------------------------- */

int Minesweeper::getScore() {
	return score;
}

/* ----------------------------------------------- */

bool Minesweeper::isGameOver(){
	return gameOver;
}

/* ----------------------------------------------- */

void Minesweeper::deallocateMatrix(int **mat, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		delete[] mat[i];
	}

	delete[] mat;
}

Minesweeper::~Minesweeper() {
	deallocateMatrix(board, rows, columns);
	deallocateMatrix(visible, rows, columns);
	deallocateMatrix(flagged, rows, columns);
}
