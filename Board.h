#pragma once
#include "Cell.h"
#include "Ship.h"
#include <vector>
using namespace std;
class Board{
	static const int rows = 4;
	static const int cols = 4;

	Cell grid[rows][cols];


public:
	Board();

	bool placeShip(vector<pair<int, int>> &cells, Ship* ship);

	bool placeRandomShip(Ship* ship);

	void shoot(int row, int column);

	void printPlayerBoard();
	void printComputerBoard();

	int getRows();
	int getCols();
};

