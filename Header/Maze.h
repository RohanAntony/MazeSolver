#ifndef MAZESOLVER_MAZE_HEADER
#define MAZESOLVER_MAZE_HEADER

#include <iostream>
#include <queue>
#include <utility>

using std::cout;
using std::endl;
using std::pair;

typedef pair<int, int> Location;

class Maze {
	int** maze;
	int rows, cols;

	Location getMazeStart() {
		for (int i = 0; i < cols; i++) {
			if (maze[0][i] == -3)
				return Location(0, i);
		}
		return Location(-1, -1);
	}

	Location getMazeEnd() {
		for (int i = 0; i < cols; i++) {
			if (maze[rows - 1][i] == -3)
				return Location(rows - 1, i);
		}
		return Location(-1, -1);
	}

	int getMaxOfVals(int a, int b, int c, int d) {
		int max = INT_MAX;
		if (a < 0 && b < 0 && c < 0 && d < 0)
			return 0;
		else {
			if (a >= 0 && a < max)
				max = a;
			if (b >= 0 && b < max)
				max = b;
			if (c >= 0 && c < max)
				max = c;
			if (d >= 0 && d < max)
				max = d;			
		}		
		return max + 1;
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

	int& operator()(int row, int col) {
		int temp = -1;
		if (row < 0 || row >= rows)
			return temp; //return a wall
		else if (col < 0 || col >= cols)
			return temp;
		return maze[row][col];
	}

	void printCurrentState() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (maze[i][j] == -1)
					cout << "XXX";
				else if (maze[i][j] == -2)
					cout << "   ";
				else if (maze[i][j] < 0)
					cout << "< >";
				else if(maze[i][j] < 10)
					cout << " " << maze[i][j] << " ";
				else 
					cout << maze[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	void findShortestPath() {
		Location start = getMazeStart(), end = getMazeEnd();
		std::queue<Location> points;
		points.push(start);
		while (points.size() != 0) {
			Location current = points.front();
			points.pop();
			int x = current.first, y = current.second;
			int leftVal = (*this)(x - 1, y),
				bottomVal = (*this)(x, y + 1),
				rightVal = (*this)(x + 1, y),
				topVal = (*this)(x, y - 1);
			int distance = getMaxOfVals(leftVal, bottomVal, rightVal, topVal);
			(*this)(x, y) = distance;
			//printCurrentState();
			if (leftVal <= -2)
				points.push(Location(x - 1, y));
			if (bottomVal <= -2)
				points.push(Location(x, y + 1));
			if (rightVal <= -2)
				points.push(Location(x + 1, y));
			if (topVal <= -2)
				points.push(Location(x, y - 1));
		}
	}

	~Maze() {
		for(int i=0; i < rows; i++)
			delete[] maze[i];
		delete[] maze;
	}
};

#endif
