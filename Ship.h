#pragma once
class Ship{
protected:
	int size;
	char type;
	int hits;

	Ship(int size, char type);

public:
	void hit();
	bool isSunk();

	int getSize();
	char getType();

};

