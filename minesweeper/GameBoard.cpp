#include"GameBoard.h"

void builtCorners(int** mat, int rows, int columns) {
	mat[0][0] = ' * ';
	mat[0][columns - 1] = ' * ';
	mat[rows - 1][0] = ' * ';
	mat[rows - 1][columns - 1] = ' * ';
}

void builtUpMargin(int** mat, int columns) {
	for (int j = 1; j < columns - 1; j++) {
		mat[0][j] = ' - ';
	}
}

void builtDownMargin(int** mat, int rows, int columns) {
	for (int j = 1; j < columns - 1; j++) {
		mat[rows - 1][j] = ' - ';
	}
}

void builtLeftMargin(int** mat, int rows) {
	for (int i = 1; i < rows - 1; i++) {
		mat[i][0] = ' | ';
	}
}

void builtRightMargin(int** mat, int rows, int columns) {
	for (int i = 1; i < rows - 1; i++) {
		mat[i][columns - 1] = ' | ';
	}
}

void builtCenter(int** mat, int rows, int columns) {
	for (int i = 1; i < rows - 1; i++) {
		for (int j = 1; j < columns - 1; j++) {
			if (j % 2 != 0) {
				mat[i][j] = ' ~ ';
			}
			else {
				mat[i][j] = ' | ';
			}
		}
	}
}

void builtBoard(int** mat, int& rows, int& columns) {
	int boardRows = (rows % 2 == 0) ? 2 * rows : 2 * rows + 1;
	int boardCols = (columns % 2 == 0) ? 2 * columns : 2 * columns + 1;

	rows = boardRows;
	columns = boardCols;

	builtCorners(mat, rows, columns);
	builtUpMargin(mat, columns);
	builtDownMargin(mat, rows, columns);
	builtLeftMargin(mat, rows);
	builtRightMargin(mat, rows, columns);
	builtCenter(mat, rows, columns);

}