#include"Minesweeper.h"
#include"Coordinates.h"

Coordinates readNextMove() {
	int x,y;

	// citesc de la consola urm celula ce trebuie descoperita ...
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;

	Coordinates coord(x,y);

	return coord;
}

GameParameters readGameParameters() {
	GameParameters gp;

	cout << "Enter number of rows [10]: ";
	cin >> gp.rows;

	cout << "Enter number of columns [12]: ";
	cin >> gp.columns;

	cout << "Enter difficulty level [E (easy), M (medium), H (hard)]: ";
	cin >> gp.difficulty;

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