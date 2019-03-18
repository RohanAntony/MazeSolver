#ifndef MAZESOLVER_MAZE_HEADER
#define MAZESOLVER_MAZE_HEADER

#include <iostream>

using std::cout;
using std::endl;

class Maze {
	const int BORDER_VALUE = 1;
	int* maze;
	int rows, cols;
	inline int getRows() {
		return rows + 2;
	}
	inline int getCols() {
		return cols + 2;
	}
	inline int getDataIndex(int r, int c) {
		return (getCols() * (r + 1)) + (c + 1); //+1 is added to c because the first column is the border column
	}
public:
	Maze(int rows, int cols) :
		rows(rows),
		cols(cols),
		maze(NULL)
	{
		int r = getRows(), c = getCols();
		maze = new int[r * c];
		for (int i = 0; i < r; i++) {
			maze[i * c] = BORDER_VALUE;
			maze[i * c + (c - 1)] = BORDER_VALUE;
		}
		for (int i = 1; i < c - 1; i++) {
			maze[i] = BORDER_VALUE;
			maze[c * (r - 1) + i] = BORDER_VALUE;
		}
	}

	void setEntry(int col) {
		maze[col + 1] = 0;
	}

	void setExit(int col) {
		maze[getCols() * (getRows() - 1) + col + 1] = 0;
	}

	int& operator()(int row, int col) {
		return maze[getDataIndex(row, col)];
	}

	void printCurrentState() {
		int r = getRows(), c = getCols();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << maze[ c * i + j ] << " ";
			}
			cout << endl;
		}

	}

	~Maze() {
		delete[] maze;
	}
};

#endif
