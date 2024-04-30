//
// Created by breizhhardware on 26/04/24.
//

#include "Enemy.h"
#include <QDebug>

Enemy::Enemy(int health, int shield, int damage, int regenerationRate, int speed, std::string avatarPath,
             int x, int y, int coinDrop, int weight, Map& gameMap, int id, Game& game)
        : Mob(health, shield, damage, regenerationRate, speed, avatarPath, x, y),
            gameMap(gameMap), game(game), initialShield(shield) {
    this->coinDrop = coinDrop;
    this->weight = weight;
    this->id = id;
    moveTimer = new QTimer();
    QPixmap pixmap(QString::fromStdString(avatarPath));
    if (pixmap.isNull()) {
    } else {
        graphics = new QGraphicsPixmapItem();
        QPixmap scaledPixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation); // Scale the pixmap to 50x50 pixels
        graphics->setPixmap(scaledPixmap);
        graphics->setPos(x * 50, y * 50);
        graphics->setZValue(1); // Set the Z-value to 1 to draw the enemy on top of the map tiles
    }
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(onMoveTimerTimeout()));
    moveTimer->start(1000 / speed);

    healthText = new QGraphicsTextItem(QString::number(health), graphics);
    healthText->setDefaultTextColor(Qt::red);
    healthText->setPos(graphics->boundingRect().width()/2 - healthText->boundingRect().width()/2, -healthText->boundingRect().height());

    shieldText = new QGraphicsTextItem(QString::number(shield), graphics);
    shieldText->setDefaultTextColor(Qt::blue);
    shieldText->setPos(graphics->boundingRect().width()/2 - shieldText->boundingRect().width()/2, -shieldText->boundingRect().height() - healthText->boundingRect().height());

    shieldRegenTimer = new QTimer();
    connect(shieldRegenTimer, &QTimer::timeout, this, &Enemy::regenerateShield);
    shieldRegenTimer->start(1000);
}

int Enemy::getWeight() {
    return weight;
}

int Enemy::getCoinDrop() {
    return coinDrop;
}

QGraphicsPixmapItem* Enemy::getGraphics() {
    return graphics;
}

Tile* Enemy::getNextPathTile() {
    // Check all the tiles around the enemy and return the one who is a path tile
    Tile* nextTile = nullptr;
    if (gameMap.getTile(x + 1, y)->isPath()) {
        nextTile = gameMap.getTile(x + 1, y);
    } else if (gameMap.getTile(x, y - 1)->isPath()) {
        nextTile = gameMap.getTile(x, y - 1);
    }
    return nextTile;
}

Tile* Enemy::getCurrentTile() {
    return gameMap.getTile(x, y);
}

void Enemy::moveEnemy() {
    // Move the enemy to the next path tile
    nextStep = getNextPathTile();
    if (nextStep != nullptr) {
        x = nextStep->gridX();
        y = nextStep->gridY();
        graphics->setPos(x * 50, y * 50);
        if (getCurrentTile() == gameMap.getEndTile()) {
            game.player->takeDamage(getDamage());
            game.removeEnemy(this);
        }
    }
}

void Enemy::onMoveTimerTimeout() {
    moveEnemy();
}

void Enemy::regenerateShield() {
    if (shield < initialShield) {
        shield += regenerationRate;
        if (shield > initialShield) {
            shield = initialShield;
        }
        shieldText->setPlainText(QString::number(shield));
    }
}

void Enemy::takeDamage(int damage) {
    if (shield > 0) {
        shield -= damage;
        if (shield < 0) {
            health += shield;
            shield = 0;
        }
        shieldText->setPlainText(QString::number(shield));
    } else {
        health -= damage;
    }
    healthText->setPlainText(QString::number(health));
    if (health <= 0) {
        game.removeEnemy(this);
    }
}