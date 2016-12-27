#include"Minesweeper.h"
#include <cstdlib>

Minesweeper::Minesweeper(GameParameters& gp) {
	rows = gp.rows;
	columns = gp.columns;
	//difficulty = gp.difficulty; // fac public enum
	difficulty = Easy;
	
	board = allocateMatrix(rows, columns);
	visible = allocateMatrix(rows, columns);
	gameOver = false;
	cursorRow = 0;
	cursorColumn = 0;
	initBoard();
	score = 0;
}

string Minesweeper::pad(int info, int row, int column) {
	return pad(to_string(info),row,column);
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
			cout << pad("#",row,column);
		}
		else if (board[row][column] == Free) {
			cout << pad(" ",row,column);
		}
		else {
			cout << pad(board[row][column], row, column);
		}
	}
	else {
		cout << pad("-", row, column);
	}
}

void Minesweeper::printHorizontalBorder(){
	cout << " ";
	for (int i = 0; i < (columns * 3) + 2; ++i) {
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
	//cout << endl;

	printHorizontalBorder();
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

void Minesweeper::placeMineCounters() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (board[i][j] == Free) { 
				board[i][j] = countMines(i, j);
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
			if (board[x][y] == Mine) {
				count++;
			}
		}
	}

	return count;
}

void Minesweeper::initBoard() {
	placeMines();
	placeMineCounters();
}

void Minesweeper::startGame() {
	clearConsoleFrame();
	//builtBoard(board, rows, columns);
	updateConsoleFrame();
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

int Minesweeper::getScore() {
	return score;
}

bool Minesweeper::isGameOver(){
	return gameOver;
}

Minesweeper::~Minesweeper() {
	deallocateMatrix(board, rows, columns);
	deallocateMatrix(visible, rows, columns);
}

void Minesweeper::clearConsoleFrame() {
	system("cls");
}

void Minesweeper::updateConsoleFrame() {
	clearConsoleFrame();
	printBoard();
}

bool Minesweeper::placeMine() {
	int v = rand() % 100;
	return (v < difficulty);
}