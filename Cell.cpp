#include "Cell.h"
#include <iostream>

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

bool Cell::beShot(){
    if (!shot && !missed) {
        if (ship) {
            shot = true;
            ship->hit();
            std::cout << "Hit! \n";
        }
        else {
            missed = true;
            std::cout << "Miss! \n";
        }

        return true;
    }
    else {
        //you already shot this field! //not printing this here bc of computer repetition that shouldnt be seen
        return false;
    }
}

Ship* Cell::getShip(){
    return ship;
}
