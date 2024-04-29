//
// Created by breizhhardware on 26/04/24.
//

#include "Game.h"
#include <QGraphicsView>
#include <iostream>
#include <QDebug>

Game::Game(){
    // Set the user gold and wave number to 0
    userGold = 0;
    waveNumber = 0;

    // Set the FocusPolicy to StrongFocus to allow the QGraphicsView to receive key events
    this->setFocusPolicy(Qt::StrongFocus);

    // Create the player object
    player = new Player(100, 0, 10, 10, 1, "../ressources/player.png", 0, 0, gameMap);

    // Create the text items for the health, gold and wave number
    healthDisplay = new QGraphicsTextItem();
    goldDisplay = new QGraphicsTextItem();
    waveDisplay = new QGraphicsTextItem();

    // Set the Z-value of the text items to 2 to draw them on top of the player
    healthDisplay->setZValue(2);
    goldDisplay->setZValue(2);
    waveDisplay->setZValue(2);

    // Set the default text color to red
    healthDisplay->setDefaultTextColor(Qt::red);
    goldDisplay->setDefaultTextColor(Qt::red);
    waveDisplay->setDefaultTextColor(Qt::red);

    // Add all the items to the scene
    gameMap.addItem(healthDisplay);
    gameMap.addItem(goldDisplay);
    gameMap.addItem(waveDisplay);
    gameMap.addItem(player->getGraphics());

    // Set the position of the text items
    healthDisplay->setPos(0, 0);
    goldDisplay->setPos(0, 20);
    waveDisplay->setPos(0, 40);

    // Set the scene of the QGraphicsView to the gameMap
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

    // Connect the game timer to the updateDisplay slot
    connect(&gameTimer, &QTimer::timeout, this, &Game::updateDisplay);

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

void Game::updateDisplay() {
    healthDisplay->setPlainText("Health: " + QString::number(player->getHealth()));
    goldDisplay->setPlainText("Gold: " + QString::number(userGold));
    waveDisplay->setPlainText("Wave: " + QString::number(waveNumber));
}