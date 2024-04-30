//
// Created by breizhhardware on 26/04/24.
//

#include "Mob.h"

Mob::Mob(int health, int shield, int damage, int regenerationRate, int speed, std::string avatarPath, int x, int y) {
    this->health = health;
    this->shield = shield;
    this->damage = damage;
    this->regenerationRate = regenerationRate;
    this->speed = speed;
    this->avatarPath = avatarPath;
    this->x = x;
    this->y = y;
}

int Mob::getHealth() const {
    return health;
}

int Mob::getShield() const {
    return shield;
}

int Mob::getDamage() const {
    return damage;
}

int Mob::getRegenerationRate() const {
    return regenerationRate;
}

int Mob::getSpeed() const {
    return speed;
}

int Mob::getX() const {
    return x;
}

int Mob::getY() const {
    return y;
}