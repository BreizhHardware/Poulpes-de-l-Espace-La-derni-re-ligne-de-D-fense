//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MOB_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MOB_H
#include <string>
#include <QObject>

class Mob : public QObject
{
    Q_OBJECT
protected:
    int health;
    int shield;
    int damage;
    int regenerationRate;
    int speed;
    std::string avatarPath;
    int x;
    int y;

public:
    Mob(int health, int shield, int damage, int regenerationRate, int speed, std::string avatarPath, int x, int y);
    int getHealth();
    int getShield();
    int getDamage();
    float getRegenerationRate();
    int getSpeed();
    int getX();
    int getY();
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MOB_H
