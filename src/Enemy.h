//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Mob.h"
#include "Map.h"
#include "Game.h"

class Game;

class Enemy : public Mob
{
    Q_OBJECT
public:
    Enemy(int health, int shield, int damage, int regenerationRate, int speed, std::string avatarPath,
          int x, int y, int coinDrop, int weight, Map& gameMap, int id, Game& game);
    int getWeight();
    int getCoinDrop();
    QGraphicsPixmapItem* getGraphics();
    void moveEnemy();
    Tile* getNextPathTile();
    Tile* getCurrentTile();
    void takeDamage(int damage);
    void dropGold();

private slots:
    void onMoveTimerTimeout();

private:
    int coinDrop;
    int weight;
    Map& gameMap;
    QGraphicsPixmapItem* graphics;
    QTimer* moveTimer;
    Tile* nextStep;
    int id;
    Game& game;
    QGraphicsTextItem* healthText;
    QGraphicsTextItem* shieldText;
    QTimer* shieldRegenTimer;
    int initialShield;

public slots:
    void regenerateShield();
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
