//
// Created by breizhhardware on 26/04/24.
//

#include "Menu.h"
#include "Game.h"
#include "Rules.h"
#include "Leaderboard.h"
#include <QVBoxLayout>
#include <QApplication>
#include <iostream>

Menu::Menu(QWidget *parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);

    playButton = new QPushButton("Play", this);
    connect(playButton, &QPushButton::clicked, this, &Menu::onPlayButtonClicked);
    layout->addWidget(playButton);

    rulesButton = new QPushButton("Rules", this);
    connect(rulesButton, &QPushButton::clicked, this, &Menu::onRulesButtonClicked);
    layout->addWidget(rulesButton);

    leaderboardButton = new QPushButton("Leaderboard", this);
    connect(leaderboardButton, &QPushButton::clicked, this, &Menu::onLeaderboardButtonClicked);
    layout->addWidget(leaderboardButton);

    quitButton = new QPushButton("Quit", this);
    connect(quitButton, &QPushButton::clicked, this, &Menu::onQuitButtonClicked);
    layout->addWidget(quitButton);
}

void Menu::onPlayButtonClicked() {
    // Create a new game
    auto* game = new Game();
    game->start();

    // Hide the menu
    hide();

    // Show the game
    game->show();
}

void Menu::onRulesButtonClicked() {
    auto* rules = new Rules();
    rules->show();
}

void Menu::onLeaderboardButtonClicked() {
    auto* leaderboard = new Leaderboard();
    leaderboard->show();
}

void Menu::onQuitButtonClicked() {
    QApplication::quit();
}

