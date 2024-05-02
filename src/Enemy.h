//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_ENEMY_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPointF>
#include "Mob.h"
#include "Map.h"
#include "Game.h"
#include "PlayerDeadException.h"

class Game;

class Enemy : public Mob
{
    Q_OBJECT
public:
    enum Type { P52, Gladius, Zeus, Corsair, Idris };
    Enemy(int health, int shield, int damage, int regenerationRate, int speed, std::string avatarPath,
          int x, int y, int coinDrop, int weight, Map& gameMap, int id, Game& game);
    Enemy(Type type, Map& gameMap, int id, Game& game);
    [[nodiscard]] int getWeight() const;
    [[nodiscard]] int getCoinDrop() const;
    QGraphicsPixmapItem* getGraphics();
    void moveEnemy();
    Tile* getNextPathTile();
    Tile* getCurrentTile();
    void takeDamage(int damage);
    void dropGold();
    [[nodiscard]] Type getType() const;
    void initializeEnemy(int health, int shield, int damage, int regenerationRate, int speed, std::string avatarPath,
                         int x, int y, int coinDrop, int weight, int id);
    void setPosition(int x, int y);
    QPointF getPosition();

private slots:
    void onMoveTimerTimeout();

private:
    Type type;
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
