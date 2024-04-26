//
// Created by breizhhardware on 26/04/24.
//

#include "Enemy.h"

Enemy::Enemy(int health, int shield, int damage, float regenerationRate, int speed, std::string avatarPath, int x, int y, int coinDrop, int weight)
        : Mob(health, shield, damage, regenerationRate, speed, avatarPath, x, y) {
    this->coinDrop = coinDrop;
    this->weight = weight;
}