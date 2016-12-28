#include"Minesweeper.h"
#include"Coordinates.h"
#include<conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACE 32
#define FLAG 'f'
#define QUIT 'q'


Coordinates readNextMove() {
	int x,y;

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

void waitForQuiting() {
	int command;
	do {
		command = _getch();
	} while (command != QUIT);
}


int main() {
	GameParameters gp = readGameParameters();
	Minesweeper* minesweeper = new Minesweeper(gp);

	minesweeper->startGame();

	do {
		int command = _getch();

		if (command == KEY_UP) {
			minesweeper->up();
		}
		else if (command == KEY_RIGHT) {
			minesweeper->right();
		}
		else if (command == KEY_DOWN) {
			minesweeper->down();
		}
		else if (command == KEY_LEFT) {
			minesweeper->left();
		}
		else if (command == SPACE) {
			minesweeper->nextMove();
		}
		else if (command == FLAG) {
			minesweeper->flag();
		}
		else {
			continue;
		}
	} while (!minesweeper->isGameOver());

	waitForQuiting();

	return 0;
}