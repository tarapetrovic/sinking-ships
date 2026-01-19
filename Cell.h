#pragma once
#include "Ship.h"
class Cell{
private:
	Ship* ship;
	bool shot = false;
	bool missed = false;

public:
	Cell();

	bool isShot();
	bool isEmpty();
	bool isMissed();

	void placeShipInCell(Ship* ship);

	void beShot();

	Ship* getShip();
};


