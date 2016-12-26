#include"Minesweeper.h"
#include"Coordinates.h"

Coordinates readNextMove() {
	int x = 1, y = 3;
	// citesc de la consola urm celula ce trebuie descoperita ...
	Coordinates coord(x,y);

	return coord;
}

GameParameters readGameParameters() {
	GameParameters gp;
	/*
	.........
	*/
	return gp;
}

int main() {
	GameParameters gp = readGameParameters();
	Minesweeper* minesweeper = new Minesweeper(gp);

	minesweeper->startGame();

	do {
		Coordinates c = readNextMove();
		minesweeper->nextMove(c);
	} while (!minesweeper->gameOver());


	return 0;
}