#include"Minesweeper.h"

Minesweeper::Minesweeper(GameParameters& gp) {
	rows = gp.rows;
	columns = gp.columns;
	difficulty = gp.difficulty;

	board = allocateMatrix(rows, columns);
	score = 0;
}

void Minesweeper::startGame() {
	cout << "Start!" << endl;
}

void Minesweeper::nextMove(Coordinates c) {
	cout << "next" << endl;
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

void Minesweeper::updateConsoleFrame() {

}