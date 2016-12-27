#ifndef GAMEBOARD_H
#define GAMEBOARD_H

void builtCorners(int** mat, int rows, int columns);

void builtUpMargin(int** mat, int columns);

void builtDownMargin(int** mat, int rows, int columns);

void builtLeftMargin(int** mat, int rows);

void builtRightMargin(int** mat, int rows, int columns);

void builtCenter(int** mat, int rows, int columns);

void builtBoard(int** mat, int& rows, int& columns);

#endif // !GAMEBOARD_H