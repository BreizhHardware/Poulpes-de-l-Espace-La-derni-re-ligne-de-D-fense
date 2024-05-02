//
// Created by BreizhHardware on 30/04/2024.
//

#ifndef TOWER_H
#define TOWER_H
#include <QObject>
#include <QPointF>
#include <QVector>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Enemy.h"
#include "Game.h"
#include "Projectile.h"

class Enemy;

class Game;

class Tower : public QObject
{
    QOBJECT_H
protected:
    int damage;
    double fireRate;
    int range;
    int level;
    int cost;
    QPointF position;
    std::string avatarPath;
    QGraphicsPixmapItem* graphics{};
    QTimer* fireTimer;
    int damageUpgrades = 0;
    int fireRateUpgrades = 0;

public:
    Tower(int damage, double fireRate, int range, int level, int cost, QPointF position, std::string avatarPath, Game& game);
    virtual ~Tower() = default;
    QGraphicsPixmapItem* getGraphics();
    void fireAtClosest(Enemy* target = nullptr) const;
    Enemy* getClosestEnemyInRange(const QVector<Enemy*>& enemies);
    Game& game;
    void upgradeDamage();
    void upgradeFireRate();
    int getDamageUpgrades() const;
    int getFireRateUpgrades() const;

public slots:
    void fire();
};

class LaserTower : public Tower {
public:
    explicit LaserTower(QPointF position, Game& game);
};

class BalisticTower : public Tower {
public:
    explicit BalisticTower(QPointF position, Game& game);
};

class DistorionTower : public Tower {
public:
    explicit DistorionTower(QPointF position, Game& game);
};



#endif //TOWER_H
