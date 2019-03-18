#include "Maze.h"
#include <iostream>
#include <cstdlib>

int main()
{
	const int ROW_NUM = 3;
	const int COL_NUM = 4;
	Maze maze(ROW_NUM, COL_NUM);
	for (int i = 0; i < ROW_NUM; i++) {
		for (int j = 0; j < COL_NUM; j++) {
			maze(i, j) = rand() % 2;
		}
	}
	maze.setEntry(COL_NUM - 2);
	maze.setExit(COL_NUM - 1);
	maze.printCurrentState();
}
