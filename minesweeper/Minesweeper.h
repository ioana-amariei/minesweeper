#include"GameParameters.h"
#include"Coordinates.h"
#include"TerminalColoring.h"
#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

class Minesweeper {

public:

	explicit Minesweeper(GameParameters&);

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

	TerminalColoring* terminal;

	int cursorRow;
	int cursorColumn;
	int dx[8] = { -1,-1,0,1,1,1,0,-1 };
	int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
	bool gameOver;

	static string MINE;
	static string FLAG;
	static string HIDDEN_CELL;
	static string FREE_CELL;

	int** allocateMatrix(int, int);

	void deallocateMatrix(int** mat, int, int);

	string pad(int, int, int);

	string pad(string, int, int);

	bool isMine(int, int);

	bool isFree(int, int);

	bool isFlagged(int, int);

	bool isVisible(int, int);

	void printMine(int, int);

	void printFlag(int, int);

	void printFreeCell(int, int);

	void printMinesNumber(int, int);

	void print(string, int);

	void printBoardCell(int, int);

	void printHorizontalBorder();

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

};