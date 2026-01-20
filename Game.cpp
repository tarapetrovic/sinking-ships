#include "Game.h"
#include <iostream>
#include <string>

#include <thread>
#include <chrono>




pair<int, int> Game::parseCoordinates(string input){
    char rowChar = input[0];          // 'A'
    int colNum = input[1] - '1';       // '1' -> 0

    int row = rowChar - 'A';           // 'A' -> 0

    return { row, colNum };
}


vector<pair<int, int>> Game::readCoordinates(int count)
{
    vector <pair<int, int>> cells;
    string input;

    for (int i = 0; i < count; i++) {
        cin >> input;
        cells.push_back(parseCoordinates(input));
    }

    return cells;
}

void Game::placePlayerShips(){

    cout << "Place your Cruiser (3 cells, eg A1 A2 A3) ";  // Player ship placement
    while (true) {
        vector <pair<int, int>> coords = readCoordinates(3);
        if (playerBoard.placeShip(coords, &playerCruiser)) {
            break;
        }
        cout << "Invalid placement, try again \n";
    }

    playerBoard.printPlayerBoard();

    cout << "Place your Submarine (2 cells, eg B1 B2) ";  // Player ship placement
    while (true) {
        vector <pair<int, int>> coords = readCoordinates(2);
        if (playerBoard.placeShip(coords, &playerSubmarine)) {
            break;
        }
        cout << "Invalid placement, try again \n";
    }

    cout << "This is your board: \n";
    playerBoard.printPlayerBoard();
}

void Game::placeComputerShips(){
    computerBoard.placeRandomShip(&computerCruiser);
    computerBoard.placeRandomShip(&computerSubmarine);
}

void Game::playerShoot(){
    string input;
    cout << "This is the Computer's board, you are shooting now \n";
    computerBoard.printComputerBoard();
    cout << "Shoot: (E.g. A3) ";

    while (true) {
        vector<pair<int, int>> coordinates = readCoordinates(1);
        int row = coordinates[0].first;
        int col = coordinates[0].second;

        bool x = computerBoard.shoot(row, col);
        if (x) break;
        else cout << "You already shot this field! Try again (e.g. B4)";

    }
    cout << "Computer's new board: \n";
    computerBoard.printComputerBoard();

}

void Game::computerShoot(){

    using namespace chrono_literals;

    this_thread::sleep_for(1500ms); // pause between player move and computer move
    
    cout << "This is your board, the computer is shooting now \n";
    playerBoard.printPlayerBoard();
    int row;
    int col;
    while (true) {
        row = rand() % computerBoard.getRows();
        col = rand() % computerBoard.getCols();

        bool x = playerBoard.shoot(row, col);
        if (x) break;
    }

    char rowShot = 'A' + row;
    int colShot = col + 1;

    this_thread::sleep_for(1500ms);

    cout << "Computer shot at " << rowShot << colShot << ". Your new board: \n";
    playerBoard.printPlayerBoard();

    this_thread::sleep_for(1500ms);
}

bool Game::isGameOver(){

    if (playerCruiser.isSunk() && playerSubmarine.isSunk()) {
        cout << "Computer wins!";
        return true;
    }
    if (computerCruiser.isSunk() && computerSubmarine.isSunk()) {
        cout << "Player wins!";
        return true;
    }
    return false;
    
}

Game::Game(){}

void Game::run(){
    placePlayerShips();
    placeComputerShips();

    int turn = 1; //Player = 1, Computer = 0

    while (true) {
        if (turn) {
            playerShoot();
            turn = !turn;
        }
        else {
            computerShoot();
            turn = !turn;
        }
        if (isGameOver()) {
            break;
        }
    }

}
