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
#define REPLAY 'r'


Coordinates readNextMove() {
	int x,y;

	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;

	Coordinates coord(x,y);

	return coord;
}

void printSpaces(int spaces = 5) {
	for (int i = 0; i < spaces; i++) {
		cout << " ";
	}
}

int readParameter(string message, int low, int high) {
	int parameter;
	do {
		printSpaces();
		cout << message;
		cin >> parameter;
	} while (parameter < low || parameter > high);

	return parameter;
}

GameParameters readGameParameters() {
	GameParameters gp;

	string rowsMessage = "Enter number of rows [1-50]: ";
	gp.rows = readParameter(rowsMessage,1,50);

	string columnsMessage = "Enter number of columns [1-50]: ";
	gp.columns = readParameter(columnsMessage,1,50);

	string difficultyMessage = "Enter difficulty level [1-99]: ";
	gp.difficulty = readParameter(difficultyMessage, 1, 99);

	return gp;
}

char readCommand() {
	char command;

	do {
		cout << endl << endl;
		printSpaces();
		cout << "Play again (r) / Quit (q): ";
		cin >> command;
		cout << endl << endl;
	} while (command != QUIT && command != REPLAY);

	return command;
}


void colourText(int code) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, code);
}

void playGame() {
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

	} while (!minesweeper->finished());

	cout << endl << endl;
	printSpaces();
	if (minesweeper->winner()) {
		colourText(14);
		cout << "CONGRATULATIONS, YOU WON !!!" << endl;
		colourText(15);
	}
	else {
		colourText(12);
		cout << "GAME OVER !!!" << endl;
		colourText(15);
	}

	minesweeper->~Minesweeper();
}

int main() {

	do {
		playGame();
	} while (readCommand() != QUIT);

	return 0;
}