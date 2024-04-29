//
// Created by breizhhardware on 26/04/24.
//

#include "Game.h"
#include <QGraphicsView>
#include <iostream>
#include <QDebug>

Game::Game(){
    userGold = 0;
    waveNumber = 0;
    this->setFocusPolicy(Qt::StrongFocus);
    player = new Player(100, 0, 10, 10, 1, "../ressources/player.png", 0, 0, gameMap);
    gameMap.addItem(player->getGraphics());
    this->setScene(&gameMap);
}

void Game::start() {
    // Create the map
    gameMap.generateMap(25, 14);

    // Set the user gold
    userGold = 100;

    // Set the wave number
    waveNumber = 1;

    // Set the player position to the end tile
    Tile* endTile = gameMap.getEndTile();
    player->setPosition(endTile);

    // Start the game timer
    gameTimer.start(1000);

    // Set focus to the QGraphicsView
    this->setFocus();
}

void Game::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Left:
            player->setPosition(player->getX() - 1, player->getY());
            break;
        case Qt::Key_Right:
            player->setPosition(player->getX() + 1, player->getY());
            break;
        case Qt::Key_Up:
            player->setPosition(player->getX(), player->getY() - 1);
            break;
        case Qt::Key_Down:
            player->setPosition(player->getX(), player->getY() + 1);
            break;
        default:
            QGraphicsView::keyPressEvent(event);
    }
}