//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Mob.h"
#include "Map.h"

class Enemy : public Mob
{
    Q_OBJECT
public:
    Enemy(int health, int shield, int damage, float regenerationRate, int speed, std::string avatarPath, int x, int y, int coinDrop, int weight, Map& gameMap);
    int getWeight();
    int getCoinDrop();
    QGraphicsPixmapItem* getGraphics();
    void moveEnemy();
    Tile* getNextPathTile();

private slots:
    void onMoveTimerTimeout();

private:
    int coinDrop;
    int weight;
    Map& gameMap;
    QGraphicsPixmapItem* graphics;
    QTimer* moveTimer;
    Tile* nextStep;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
