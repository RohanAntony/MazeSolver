#ifndef MAZESOLVER_MAZE_HEADER
#define MAZESOLVER_MAZE_HEADER

#include <iostream>

using std::cout;
using std::endl;

class Maze {
	int** maze;
	int rows, cols;

	int* getMazeStart() {
		for (int i = 0; i < cols; i++) {
			if (maze[0][i] == -3)
				return &maze[0][i];
		}
	}

	int* getMazeEnd() {
		for (int i = 0; i < cols; i++) {
			if (maze[rows - 1][i] == -3)
				return &maze[0][i];
		}
	}

public:
	Maze(int rows, int cols) :
		rows(rows),
		cols(cols),
		maze(NULL)
	{
		maze = new int*[rows];
		for (int i = 0; i < rows; i++) {
			maze[i] = new int[cols];
		}
	}

	int operator()(int row, int col) const{
		if (row < 0 || row >= rows)
			return -1; //return a wall
		else if (col < 0 || col >= cols)
			return -1;
		return maze[row][col];
	}

	int& operator()(int row, int col) {
		return maze[row][col];
	}

	void printCurrentState() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << maze[i][j] << "\t";
			}
			cout << endl;
		}

	}

	~Maze() {
		for(int i=0; i < rows; i++)
			delete[] maze[i];
		delete[] maze;
	}
};

#endif
