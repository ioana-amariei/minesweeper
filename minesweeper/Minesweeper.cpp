#include"Minesweeper.h"

Minesweeper::Minesweeper(GameParameters& gp) {
	rows = gp.rows;
	columns = gp.columns;
	difficulty = gp.difficulty;

	board = allocateMatrix(rows, columns);
	score = 0;
}

void Minesweeper::startGame() {
}

void Minesweeper::nextMove(Coordinates c) {

}

int Minesweeper::getScore() {

}

bool Minesweeper::gameOver(){

}

Minesweeper::~Minesweeper() {
	deallocateMatrix(board, rows, columns);
}

void Minesweeper::updateConsoleFrame() {

}