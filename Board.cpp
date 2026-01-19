#include "Board.h"
#include <vector>
#include <iostream>

using namespace std;

Board::Board() {}

bool Board::placeShip(vector<pair<int, int>> &cells, Ship* ship){ 

	if (cells.size() != ship->getSize()) return false;

	bool sameRow = true;
	bool sameCol = true;

	for (int i = 1; i < cells.size(); i++) {
		if (cells[i].first != cells[0].first)
			sameRow = false;
		if (cells[i].second != cells[0].second)
			sameCol = false;
	}

	if (!sameRow && !sameCol) //check if diagonal
		return false;

	for (int i = 0; i < cells.size() - 1; i++) { //check if consecutive
		if (sameRow) {
			int curr = cells[i].second;
			int next = cells[i + 1].second;

			if (curr != (next - 1))
				return false;
		}

		if (sameCol) {
			int curr = cells[i].first;
			int next = cells[i + 1].first;

			if (curr != (next - 1))
				return false;
		}
	}

	for (int i = 0; i < cells.size(); i++) { // check if any cell i want is already filled
		int r = cells[i].first;
		int c = cells[i].second;

		if (!grid[r][c].isEmpty())
			return false;
	}

	for (int i = 0; i < cells.size(); i++) {
		int r = cells[i].first;
		int c = cells[i].second;

		grid[r][c].placeShipInCell(ship);
	}
	return true;
}

bool Board::placeRandomShip(Ship* ship){
	int size = ship->getSize();

	while (true) {
		int row = rand() % rows;
		int col = rand() % cols;
		bool horizontal = rand() % 2;

		vector<pair<int, int>> cells;
		cells.push_back({row, col});
		for (int i = 1; i < size; i++) {
			if (horizontal) {
				col++;
				cells.push_back({ row, col });
			}
			else {
				row++;
				cells.push_back({ row, col });
			}
		}

		if (placeShip(cells, ship)) {
			return true;
		}
	}
}

void Board::shoot(int row, int column){
	grid[row][column].beShot();
}





void Board::printPlayerBoard(){

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			Cell& cell = grid[i][j];

			if (cell.isMissed()) {
				cout << "O ";
			}

			else if (cell.isEmpty()) {
				cout << ". ";
			}

			else if (cell.getShip()->isSunk()) {
				cout << "X ";
			}

			else if (cell.isShot()) {
				cout << "H ";
			}

			else if (cell.getShip()->getType() == 'S') {
				cout << "S ";
			}

			else if (cell.getShip()->getType() == 'C') {
				cout << "C ";
			}

			
		}
		cout << "\n";
	}
}

void Board::printComputerBoard(){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			Cell& cell = grid[i][j];

			if (cell.isMissed()) {
				cout << "O ";
			}

			else if (cell.isEmpty()) {
				cout << ". ";
			}

			else if (cell.getShip()->isSunk()) {
				cout << "X ";
			}

			else if (cell.isShot()) {
				cout << "H ";
			}

			else cout << ". ";
		}
		cout << "\n";
	}
}

int Board::getRows(){
	return rows;
}

int Board::getCols(){
	return cols;
}
