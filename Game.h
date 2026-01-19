#pragma once
#include "Board.h"
#include "Cruiser.h"
#include "Submarine.h"
#include <string>
class Game{

    Board playerBoard;
    Board computerBoard;

    Cruiser playerCruiser;
    Submarine playerSubmarine;

    Cruiser computerCruiser;
    Submarine computerSubmarine;

    static pair<int, int> parseCoordinates(string input);
    vector <pair<int, int>> readCoordinates(int count);

    void placePlayerShips();
    void placeComputerShips();

    void playerShoot();
    void computerShoot();

    bool isGameOver();

public:
    Game();
    void run();

};

