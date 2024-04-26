//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
#include "Mob.h"

class Enemy : public Mob
{
public:
    Enemy(int health, int shield, int damage, float regenerationRate, int speed, std::string avatarPath, int x, int y, int coinDrop, int weight);
    int coinDrop;
    int weight;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
