//
// Created by breizhhardware on 26/04/24.
//

#include "Player.h"
#include <iostream>

Player::Player(int health, int shield, int damage, float regenerationRate, int speed, std::string avatarPath, int x, int y)
        : Mob(health, shield, damage, regenerationRate, speed, avatarPath, x, y) {
    this->x = x;
    this->y = y;
    graphics = new QGraphicsEllipseItem(x, y, 10, 10);
    graphics->setBrush(QBrush(Qt::blue));
}
void Player::setPosition(Tile* tile) {
    this->x = tile->gridX();
    this->y = tile->gridY();
    graphics->setRect(x * 50, y * 50, 50, 50);
}

void Player::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
    graphics->setRect(x * 50, y * 50, 50, 50);
}

void Player::getPlayerPosition() {
    std::cout << "Player position: x: " << x << " y: " << y << std::endl;
}

QGraphicsEllipseItem* Player::getGraphics() {
    return graphics;
}

int Player::getX() {
    return x;
}

int Player::getY() {
    return y;
}