//
// Created by breizhhardware on 26/04/24.
//

#include "Enemy.h"
#include <QDebug>

Enemy::Enemy(int health, int shield, int damage, int regenerationRate, int speed, std::string avatarPath,
             int x, int y, int coinDrop, int weight, Map& gameMap, int id, Game& game)
        : Mob(health, shield, damage, regenerationRate, speed, avatarPath, x, y),
            gameMap(gameMap), game(game), initialShield(shield) {
    initializeEnemy(health, shield, damage, regenerationRate, speed, avatarPath, x, y, coinDrop, weight, id);
}

void Enemy::initializeEnemy(int health, int shield, int damage, int regenerationRate, int speed, std::string avatarPath,
                            int x, int y, int coinDrop, int weight, int id){
    this->health = health;
    this->shield = shield;
    this->initialShield = shield;
    this->damage = damage;
    this->regenerationRate = regenerationRate;
    this->speed = speed;
    this->avatarPath = avatarPath;
    this->x = x;
    this->y = y;
    this->coinDrop = coinDrop;
    this->weight = weight;
    this->id = id;
    moveTimer = new QTimer();
    QPixmap pixmap(QString::fromStdString(avatarPath));
    if (pixmap.isNull()) {
        qDebug() << "Failed to load enemy pixmap" << QString::fromStdString(avatarPath);
    } else {
        graphics = new QGraphicsPixmapItem();
        QPixmap scaledPixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation); // Scale the pixmap to 50x50 pixels
        graphics->setPixmap(scaledPixmap);
        graphics->setPos(x * 50, y * 50);
        graphics->setZValue(2); // Set the Z-value to 2 to draw the enemy on top of the map tiles
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

Enemy::Enemy(Enemy::Type type, Map &gameMap, int id, Game &game)
        : gameMap(gameMap), game(game), type(type),
        Mob(0, 0, 0, 0, 0, "", 0, 0){
    switch (type) {
        case(P52):
            initializeEnemy(100, 0, 10, 0, 5, ":/ressources/p52.png", 0, 0, 10, 1, id);
            break;
        case(Gladius):
            initializeEnemy(200, 50, 20, 0, 4, ":/ressources/gladius.png", 0, 0, 20, 2, id);
            break;
        case(Zeus):
            initializeEnemy(500, 250, 30, 0, 2, ":/ressources/zeus.png", 0, 0, 30, 5, id);
            break;
        case(Corsair):
            initializeEnemy(1000, 500, 40, 0, 2, ":/ressources/corsair.png", 0, 0, 40, 10, id);
            break;
        case(Idris):
            initializeEnemy(2000, 2000, 50, 0, 1, ":/ressources/idris.png", 0, 0, 50, 20, id);
            break;
        default:
            initializeEnemy(100, 0, 10, 0, 5, ":/ressources/p52.png", 0, 0, 10, 1, id);
            break;
    }
}

int Enemy::getWeight() const {
    return weight;
}

int Enemy::getCoinDrop() const {
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
    try {
        // Move the enemy to the next path tile
        nextStep = getNextPathTile();
        if (nextStep != nullptr) {
            x = nextStep->gridX();
            y = nextStep->gridY();
            graphics->setPos(x * 50, y * 50);
            // Check if the enemy is on the end tile and deal damage
            if (getCurrentTile() == gameMap.getEndTile()) {
                game.player->takeDamage(getDamage());
                game.playWarpSound();
                game.removeEnemy(this);
            }
            // Check if the player is on the same tile as the enemy and deal damage
            if (game.player->getX() == x && game.player->getY() == y) {
                game.player->takeDamage(getDamage());
                dropGold();
                game.removeEnemy(this);
            }
        }
    } catch (PlayerDeadException& e) {
        return;
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
        dropGold();

        game.removeEnemy(this);
    }
}

void Enemy::dropGold() {
    game.playDeathSound();
    game.userGold += coinDrop;
    game.updateDisplay();
}

Enemy::Type Enemy::getType() const {
    return type;
}

void Enemy::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
    graphics->setPos(x * 50, y * 50);
}

QPointF Enemy::getPosition() {
    if(this == nullptr) {
        return QPointF(0, 0);
    }
    return QPointF(x, y);
}