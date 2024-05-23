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
#include <QGraphicsItem>
#include "../Mob/Enemy.h"

class Projectile;

class Enemy;

class Game;

class Tower : public QObject, public QGraphicsItem
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
    QGraphicsPixmapItem* graphics;
    QTimer* fireTimer;
    int damageUpgrades = 0;
    int fireRateUpgrades = 0;

public:
    Tower(int damage, double fireRate, int range, int level, int cost, QPointF position, std::string avatarPath, Game& game);
    ~Tower() override = default;
    QGraphicsPixmapItem* getGraphics();
    void fireAtClosest(Enemy* target = nullptr) const;
    Enemy* getClosestEnemyInRange(const QVector<Enemy*>& enemies);
    Game& game;
    void upgradeDamage();
    void upgradeFireRate();
    [[nodiscard]] int getDamageUpgrades() const;
    [[nodiscard]] int getFireRateUpgrades() const;
    QVector<Projectile*> projectiles;
    QGraphicsEllipseItem* rangeIndicator = nullptr;
    QGraphicsEllipseItem* getRangeIndicator();

public slots:
    void fire();
};

class LaserTower : public Tower {
public:
    explicit LaserTower(QPointF position, Game& game);
    QRectF boundingRect() const override {
        // Return the bounding rectangle of the tower
        return QRectF(0, 0, 50, 50);
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        // Draw the tower
        painter->drawPixmap(0, 0, 50, 50, QPixmap(QString::fromStdString(avatarPath)));
    }
};

class BalisticTower : public Tower {
public:
    explicit BalisticTower(QPointF position, Game& game);
    QRectF boundingRect() const override {
        // Return the bounding rectangle of the tower
        return QRectF(0, 0, 50, 50);
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        // Draw the tower
        painter->drawPixmap(0, 0, 50, 50, QPixmap(QString::fromStdString(avatarPath)));
    }
};

class DistorionTower : public Tower {
public:
    explicit DistorionTower(QPointF position, Game& game);
    QRectF boundingRect() const override {
        // Return the bounding rectangle of the tower
        return QRectF(0, 0, 50, 50);
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        // Draw the tower
        painter->drawPixmap(0, 0, 50, 50, QPixmap(QString::fromStdString(avatarPath)));
    }
};



#endif //TOWER_H
