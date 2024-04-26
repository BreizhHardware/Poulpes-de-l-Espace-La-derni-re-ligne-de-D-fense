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
