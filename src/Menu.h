//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MENU_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MENU_H
#include "Game.h"
#include "Rules.h"
#include "Leaderboard.h"
#include "MainWindow.h"
#include "Gameover.h"
#include <QVBoxLayout>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QLabel>

class Game;

class MainWindow;

class Menu : public QWidget {
    Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);

public slots:
    void showMenu();

private slots:
    void onPlayButtonClicked();
    void onRulesButtonClicked();
    void onLeaderboardButtonClicked();
    void onQuitButtonClicked();

private:
    QLabel *title;
    QPushButton *playButton;
    QPushButton *rulesButton;
    QPushButton *leaderboardButton;
    QPushButton *quitButton;
    QGraphicsView *view;
    Game *game;
    void removeButtons();
    void handleGameOver();

};

#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MENU_H
