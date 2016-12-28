#include"GameParameters.h"
#include"Coordinates.h"
#include<iostream>
#include<string>

using namespace std;

class Minesweeper {

public:

	Minesweeper(GameParameters&);

	void startGame();

	void nextMove(Coordinates);

	void nextMove();

	void up();

	void right();

	void down();

	void left();

	void flag();

	bool finished();

	bool winner();

	bool isGameOver();

	~Minesweeper();

private:

	int rows;
	int columns;

	enum DifficultyLevel { Easy = 10, Medium = 30, Hard = 50 };
	DifficultyLevel difficulty;

	int** board;
	int** visible;
	int** flagged;

	enum CellState { Mine = -1, Free = 0 };

	int cursorRow;
	int cursorColumn;
	int dx[8] = { -1,-1,0,1,1,1,0,-1 };
	int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
	bool gameOver;

	int** allocateMatrix(int, int);

	void printBoardCell(int, int);

	void printHorizontalBorder();

	string pad(int, int, int);

	string pad(string, int, int);

	void printSpaces(int);

	int countFreeCells();

	void printBoardInfo();

	void printBoard();

	void clearConsoleFrame();

	void updateConsoleFrame();

	bool placeMine();

	void placeMines();

	int countMines(int i, int j);

	void placeMineCounters();

	void initBoard();

	bool inBoard(int row, int column);

	void expandSelection(int row, int column);

	void deallocateMatrix(int** mat, int, int);

};