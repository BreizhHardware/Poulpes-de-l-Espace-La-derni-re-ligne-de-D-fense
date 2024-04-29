//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MOB_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MOB_H
#include <string>

class Mob {
protected:
    int health;
    int shield;
    int damage;
    float regenerationRate;
    int speed;
    std::string avatarPath;
    int x;
    int y;

public:
    Mob(int health, int shield, int damage, float regenerationRate, int speed, std::string avatarPath, int x, int y);
    int getHealth();
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MOB_H
