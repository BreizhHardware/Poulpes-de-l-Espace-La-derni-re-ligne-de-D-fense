//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PLAYER_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PLAYER_H
#include "Mob.h"
#include "Tile.h"
#include "Map.h"
#include "Enemy.h"
#include "Game.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsPixmapItem>
#include <QBrush>

class Game;

class Enemy;

class Player : public Mob
{
public:
    Player(int health, int shield, int damage, int regenerationRate, int speed, const std::string& avatarPath, int x, int y, Map& gameMap, Game& game);
    void setPosition(Tile* tile);
    void setPosition(int x, int y);
    void getPlayerPosition() const;
    QGraphicsPixmapItem* getGraphics() const;
    void touchEnemy(Enemy* enemy);
    void takeDamage(int damage);
    Game& game;
    void updatePreviousHealth();
    int getPreviousHealth() const;
    void heal(int amount);

private:
    QGraphicsPixmapItem* graphics;
    Map& gameMap;
    int previousHealth;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PLAYER_H
