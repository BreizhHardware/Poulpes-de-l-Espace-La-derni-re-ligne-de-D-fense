//
// Created by breizhhardware on 26/04/24.
//

#include "Game.h"
#include <QGraphicsView>
#include <iostream>

Game::Game(){
    userGold = 0;
    waveNumber = 0;
}

void Game::start() {
    // Create the map
    gameMap.generateMap(25, 14);
    std::cout << "Map generated" << std::endl;

    // Set the user gold
    userGold = 100;
    std::cout << "User gold set" << std::endl;

    // Set the wave number
    waveNumber = 1;
    std::cout << "Wave number set" << std::endl;

    // Start the game timer
    gameTimer.start(1000);
    std::cout << "Game timer started" << std::endl;
}

void Game::show() {
    // Show the map
    gameMap.show();
    std::cout << "Map shown" << std::endl;

    auto* view = new QGraphicsView(&gameMap);
    view->show();
}