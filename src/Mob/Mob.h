//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MOB_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MOB_H
#include <string>
#include <QObject>

class Map;

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
    [[nodiscard]] int getHealth() const;
    [[nodiscard]] int getShield() const;
    [[nodiscard]] int getDamage() const;
    [[nodiscard]] int getRegenerationRate() const;
    [[nodiscard]] int getSpeed() const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MOB_H
