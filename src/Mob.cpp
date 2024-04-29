//
// Created by breizhhardware on 26/04/24.
//

#include "Mob.h"

Mob::Mob(int health, int shield, int damage, float regenerationRate, int speed, std::string avatarPath, int x, int y){
    this->health = health;
    this->shield = shield;
    this->damage = damage;
    this->regenerationRate = regenerationRate;
    this->speed = speed;
    this->avatarPath = avatarPath;
    this->x = x;
    this->y = y;
}

int Mob::getHealth() {
    return health;
}

int Mob::getShield() {
    return shield;
}

int Mob::getDamage() {
    return damage;
}

float Mob::getRegenerationRate() {
    return regenerationRate;
}

int Mob::getSpeed() {
    return speed;
}

int Mob::getX() {
    return x;
}

int Mob::getY() {
    return y;
}