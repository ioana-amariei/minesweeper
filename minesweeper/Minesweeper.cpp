#include"Minesweeper.h"
#include <stdlib.h>

Minesweeper::Minesweeper(GameParameters& gp) {
	rows = gp.rows;
	columns = gp.columns;
	difficulty = gp.difficulty;
	
	board = allocateMatrix(rows, columns);

	initBoard();
	score = 0;
}

void Minesweeper::initBoard() {
	//logica de initializare a jocului
	// minele, spatiile libere
	// numarul de mine adiacente unei celule
	// trebuie calculate/intiializate toate
}

void Minesweeper::startGame() {
	clearConsoleFrame();
	//builtBoard(board, rows, columns);
	updateConsoleFrame();
}

void Minesweeper::nextMove(Coordinates c) {
	board[c.x][c.y] = 444;
	updateConsoleFrame();
}

int Minesweeper::getScore() {
	return score;
}

bool Minesweeper::gameOver(){
	return false;
}

Minesweeper::~Minesweeper() {
	deallocateMatrix(board, rows, columns);
}

void Minesweeper::clearConsoleFrame() {
	system("cls");
}
void Minesweeper::updateConsoleFrame() {
	clearConsoleFrame();
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}