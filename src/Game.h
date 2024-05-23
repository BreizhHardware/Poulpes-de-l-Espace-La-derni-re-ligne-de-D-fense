//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAME_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAME_H
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QThread>
#include <QVector>
#include <QSqlQuery>
#include <QProcessEnvironment>
#include <QMenu>
#include <QSoundEffect>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
#include "Gameover.h"
#include "Tower.h"
#include "Projectile.h"

class Player;

class Enemy;

class Menu;

class Tower;

class Map;

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(Menu* menu);
    void start();
    Map* gameMap;
    void updateDisplay() const;
    void spawnEnemies(int waveNumber);
    int userGold;
    QVector<Enemy*> currentEnemies;
    void checkEnemyNumber();
    void removeEnemy(Enemy* enemy);
    Player* player;
    void gameOver();
    void resetGame();
    void placeTower(QMouseEvent* event);
    void endRound();
    void clearTowers();
    void upgradeTower(Tower* tower, QMouseEvent* event);
    void placeTower(int gridX, int gridY, QMouseEvent* event);
    void handleTileClick(int gridX, int gridY, QMouseEvent* event);
    void playDeathSound();
    void playWarpSound();

private:
    QTimer gameTimer;
    int waveNumber;
    QGraphicsTextItem* healthDisplay;
    QGraphicsTextItem* goldDisplay;
    QGraphicsTextItem* waveDisplay;
    QTimer enemyCheckTimer;
    int totalWeight;
    int targetWeight;
    int x;
    int y;
    Menu* menu;
    QVector<Tower*> towers;
    bool isWaveSpawning;
    QMenu towerMenu;
    QSoundEffect gameOverSound;
    QSoundEffect deathSound;
    QSoundEffect warpSound;

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAME_H
