#include"GameParameters.h"
#include"Coordinates.h"

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

	void updateConsoleFrame();

	int** allocateMatrix(int rows, int columns) {
		int** mat = new int*[rows];
		for (int i = 0; i < rows; i++) {
			mat[i] = new int[columns];
		}

		return mat;
	}

	void deallocateMatrix(int **mat, int rows, int columns) {
		for (int i = 0; i < rows; i++) {
			delete[] mat[i];
		}

		delete[] mat;
	}
};