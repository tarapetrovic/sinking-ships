#include "Cell.h"

Cell::Cell(): ship(nullptr), shot(false){}

bool Cell::isShot(){
    return shot;
}

bool Cell::isEmpty(){
    return (ship == nullptr);
}

bool Cell::isMissed()
{
    return missed;
}

void Cell::placeShipInCell(Ship* s){
    this->ship = s;
}

void Cell::beShot(){
    if (!shot && !missed) {
        if (ship) {
            shot = true;
            ship->hit();
        }
        else missed = true;
    }
}

Ship* Cell::getShip(){
    return ship;
}
