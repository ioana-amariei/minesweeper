#include"GameParameters.h"
#include"Coordinates.h"
#include"GameBoard.h"
#include<iostream>
#include<string>

using namespace std;


class Minesweeper {
public:

	Minesweeper(GameParameters&);

	void startGame();

	void nextMove(Coordinates);

	int getScore();

	void up();
	void right();
	void down();
	void left();
	void flag();
	void nextMove();

	bool isGameOver();

	~Minesweeper();

private:
	enum DifficultyLevel { Easy = 10, Medium = 30, Hard = 50 };

	int rows;
	int columns;
	DifficultyLevel difficulty;
	int** board;
	int score;
	int** visible;
	int** flagged;
	bool gameOver;
	int cursorRow;
	int cursorColumn;
	int dx[8] = { -1,-1,0,1,1,1,0,-1 };
	int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

	enum CellState {Mine = -1, Free = 0};

	void updateConsoleFrame();

	void placeMines();

	void placeMineCounters();

	bool inBoard(int row, int column);

	int countMines(int i, int j);

	void expandSelection(int row, int column);

	void initBoard();

	void clearConsoleFrame();

	bool placeMine();

	void printBoardCell(int row, int column);
	void printHorizontalBorder();
	int** allocateMatrix(int rows, int columns) {
		int** mat = new int*[rows];
		for (int i = 0; i < rows; i++) {
			mat[i] = new int[columns]();
		}

		return mat;
	}
	string pad(int, int, int);
	string pad(string, int, int);


	void deallocateMatrix(int **mat, int rows, int columns) {
		for (int i = 0; i < rows; i++) {
			delete[] mat[i];
		}

		delete[] mat;
	}

	void printBoard();

};