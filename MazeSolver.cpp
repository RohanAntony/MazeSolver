#include "Maze.h"
#include <iostream>
#include <cstdlib>

#define ROW_NUM 10
#define COL_NUM 10

int main()
{
	Maze maze(ROW_NUM, COL_NUM);

	int sampleMaze[ROW_NUM][COL_NUM] = {
		{-1, -1, -1, -1, -3, -1, -1, -1, -1, -1},
		{-1, -2, -2, -2, -2, -2, -2, -2, -2, -1},
		{-1, -1, -1, -1, -1, -1, -2, -1, -2, -1},
		{-1, -2, -2, -2, -1, -2, -2, -1, -2, -1},
		{-1, -2, -1, -2, -1, -2, -1, -1, -2, -1},
		{-1, -2, -2, -2, -2, -2, -1, -2, -2, -1},
		{-1, -1, -1, -1, -1, -2, -1, -1, -1, -1},
		{-1, -2, -1, -2, -1, -2, -1, -1, -2, -1},
		{-1, -2, -2, -2, -2, -2, -2, -2, -2, -1},
		{-1, -1, -1, -1, -1, -1, -1, -4, -1, -1}
	};

	//Add entry into maze
	for (int i = 0; i < ROW_NUM; i++) {
		for (int j = 0; j < COL_NUM; j++) {
			maze(i, j) = sampleMaze[i][j];
		}
	}

	maze.printCurrentState();
	maze.findShortestPath();
	maze.printCurrentState();
}
