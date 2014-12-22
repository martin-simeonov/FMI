#include <iostream>
#define SIZE 8

using namespace std;

bool changeSymbol(char board[][SIZE], int row, int col) {
	if (board[row][col] != '#') {
		board[row][col] = 'X';
		return true;
	}
	return false;
}

void findFigure(char board[][SIZE], char fig, int& row, int& col) {
	row = -1, col = -1;

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] == fig) {
				row = i;
				col = j;
				break;
			}
		}
	}
}

void rookMoves(char board[][SIZE], int row = 0, int col = 0) {
	if (row == 0 && col == 0) {
		findFigure(board, 'R', row, col);
	}
	if (row < 0 || col < 0) {
		cout << "There is no rook" << endl;
		return;
	}

	// Up
	for (int i = row - 1; i >= 0; --i) {
		if (changeSymbol(board, i, col)) break;
	}
	// Down
	for (int i = row + 1; i < SIZE; ++i) {
		if (changeSymbol(board, i, col)) break;
	}
	// Left
	for (int i = col - 1; i >= 0; --i) {
		if (changeSymbol(board, row, i)) break;
	}
	// Right
	for (int i = col + 1; i < SIZE; ++i) {
		if (changeSymbol(board, row, i)) break;
	}
}

void queenMoves(char board[][SIZE]) {
	int row, col;

	findFigure(board, 'Q', row, col);

	if (row < 0 || col < 0) {
		cout << "There is no queen" << endl;
		return;
	}

	rookMoves(board, row, col);

	// Up and left diagonal
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
		if (changeSymbol(board, i, j)) break;
	}
	// Up and right diagonal
	for (int i = row - 1, j = col + 1; i >= 0 && j < SIZE; --i, ++j) {
		if (changeSymbol(board, i, j)) break;
	}
	// Down and left diagonal
	for (int i = row + 1, j = col - 1; i < SIZE && j >= 0; ++i, --j) {
		if (changeSymbol(board, i, j)) break;
	}
	// Down and right diagonal
	for (int i = row + 1, j = col + 1; i < SIZE && j < SIZE; ++i, ++j) {
		if (changeSymbol(board, i, j)) break;
	}
}

void horseMoves(char board[][SIZE]) {
	int row, col;

	findFigure(board, 'K', row, col);

	if (row < 0 || col < 0) {
		cout << "There is no horse" << endl;
		return;
	}

	// Up left
	if (row - 2 >= 0 && col - 2 >= 0) {
		changeSymbol(board, row - 2, col - 1);
		changeSymbol(board, row - 1, col - 2);
	}
	// Up right
	if (row - 2 >= 0 && col + 2 < SIZE) {
		changeSymbol(board, row - 2, col + 1);
		changeSymbol(board, row - 1, col + 2);
	}
	// Down left
	if (row + 2 < SIZE && col - 2 >= 0) {
		changeSymbol(board, row + 2, col - 1);
		changeSymbol(board, row + 1, col - 2);
	}
	// Down right
	if (row + 2 < SIZE && col + 2 < SIZE) {
		changeSymbol(board, row + 2, col + 1);
		changeSymbol(board, row + 1, col + 2);
	}
}

void printBoard(char board[][SIZE]) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	char matrix[SIZE][SIZE];

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout << "enter element " << i + 1 << "," << j + 1 << ": ";
			cin >> matrix[i][j];
		}
	}

	char rookBoard[SIZE][SIZE];
	char horseBoard[SIZE][SIZE];
	char queenBoard[SIZE][SIZE];
	memcpy(&rookBoard, &matrix, sizeof(matrix));
	memcpy(&horseBoard, &matrix, sizeof(matrix));
	memcpy(&queenBoard, &matrix, sizeof(matrix));

	cout << "Elimination by one move of rook:" << endl;
	rookMoves(rookBoard);
	printBoard(rookBoard);

	cout << "Elimination by one move of horse:" << endl;
	horseMoves(horseBoard);
	printBoard(horseBoard);

	cout << "Elimination by one move of queen:" << endl;
	queenMoves(queenBoard);
	printBoard(queenBoard);

	cout << "Elimination by one move of three combined:" << endl;
	rookMoves(matrix);
	horseMoves(matrix);
	queenMoves(matrix);
	printBoard(matrix);

	return 0;
}