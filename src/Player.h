//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PLAYER_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PLAYER_H
#include "Mob.h"
#include "Tile.h"
#include <QGraphicsEllipseItem>
#include <QBrush>

class Player : public Mob
{
public:
    Player(int health, int shield, int damage, float regenerationRate, int speed, std::string avatarPath, int x, int y);
    void setPosition(Tile* tile);
    void setPosition(int x, int y);
    void getPlayerPosition();
    int getX();
    int getY();
    QGraphicsEllipseItem* getGraphics();

private:
    QGraphicsEllipseItem* graphics;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PLAYER_H
