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
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
#include "Gameover.h"

class Player;

class Enemy;

class Menu;

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(Menu* menu);
    void start();
    Map gameMap;
    void updateDisplay();
    void spawnEnemies(int waveNumber);
    int userGold;
    std::vector<Enemy*> currentEnemies;
    void checkEnemyNumber();
    void removeEnemy(Enemy* enemy);
    Player* player;
    void gameOver();
    void resetGame();

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

protected:
    void keyPressEvent(QKeyEvent* event) override;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAME_H
