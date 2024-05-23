//
// Created by breizhhardware on 29/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAMEOVER_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAMEOVER_H
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QGridLayout>
#include <QSpacerItem>
#include "../Game/Game.h"

class Game;

class Gameover : public QWidget {
    Q_OBJECT
public:
    explicit Gameover(Game* game, QWidget *parent = nullptr);

private slots:
    void onRestartButtonClicked();
    static void onQuitButtonClicked();

private:
    Game* game;
    QPushButton* restartButton;
    QPushButton* quitButton;

signals:
    void restartGameSignal();
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAMEOVER_H
