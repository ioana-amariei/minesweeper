#include"GameParameters.h"
#include"Coordinates.h"
#include<iostream>
#include<string>
#include"termcolor.hpp"

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
	int difficulty;

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

	void printColored(string text, ostream& (*color)(ostream&));

	bool isMine(int, int);

	bool isFree(int, int);

	bool isFlagged(int, int);

	void printMine(int, int);

	void printFlag(int, int);

	void printBoardCell(int, int);

	void printHorizontalBorder();

	string pad(int, int, int);

	string pad(string, int, int);

	void printSpaces(int);

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

	int countFreeCells();

	void deallocateMatrix(int** mat, int, int);

};