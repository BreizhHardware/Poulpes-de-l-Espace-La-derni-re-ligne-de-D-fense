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

class Player;

class Game : public QGraphicsView
{
public:
    Game();
    void start();
    Map gameMap;
    void updateDisplay();
    void spawnEnemies(int waveNumber);
    int userGold;
    std::vector<Enemy*> currentEnemies;

private:
    QTimer gameTimer;
    int waveNumber;
    Player* player;
    QGraphicsTextItem* healthDisplay;
    QGraphicsTextItem* goldDisplay;
    QGraphicsTextItem* waveDisplay;

protected:
    void keyPressEvent(QKeyEvent* event) override;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAME_H
