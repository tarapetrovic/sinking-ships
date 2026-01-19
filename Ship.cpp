#include "Ship.h"

Ship::Ship(int size, char type) : size(size), type(type), hits(0) {}

void Ship::hit(){
	hits++;
}

bool Ship::isSunk(){
	return hits >= size;
}

int Ship::getSize(){
	return size;
}

char Ship::getType(){
	return type;
}




