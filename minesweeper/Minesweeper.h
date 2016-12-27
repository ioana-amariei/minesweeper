#include"GameParameters.h"
#include"Coordinates.h"
#include"GameBoard.h"
#include<iostream>

using namespace std;


class Minesweeper {
public:

	Minesweeper(GameParameters&);

	void startGame();

	void nextMove(Coordinates);

	int getScore();

	bool gameOver();

	~Minesweeper();

private:
	int rows;
	int columns;
	char difficulty;
	int** board;
	int score;

	enum CellState { Mine = -1, Free = 0};

	void updateConsoleFrame();

	void initBoard();
	void clearConsoleFrame();

	int** allocateMatrix(int rows, int columns) {
		int** mat = new int*[rows];
		for (int i = 0; i < rows; i++) {
			mat[i] = new int[columns]();
		}

		return mat;
	}

	void deallocateMatrix(int **mat, int rows, int columns) {
		for (int i = 0; i < rows; i++) {
			delete[] mat[i];
		}

		delete[] mat;
	}

	void printBoard(int** mat, int rows, int columns) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << mat[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

};