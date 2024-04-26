//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAME_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAME_H
#include <QTimer>
#include "Map.h"

class Game
{
public:
    Game();
    void start();
    void show();

private:
    int userGold;
    QTimer gameTimer;
    Map gameMap;
    int waveNumber;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAME_H
