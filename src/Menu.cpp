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
    game = nullptr;
    auto* layout = new QVBoxLayout(this);
    view = new QGraphicsView(this);

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

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void Menu::removeButtons() {
    playButton->hide();
    rulesButton->hide();
    leaderboardButton->hide();
    quitButton->hide();
}

void Menu::onPlayButtonClicked() {
    // Remove buttons
    removeButtons();
    // Set the view size
    view->setFixedSize(1280, 720);
    view->show();
    // Create a new game
    game = new Game();
    game->start();

    // Show the game
    view->setScene(&game->gameMap);
    view->setFocus(); // Set focus to the QGraphicsView
}

void Menu::onRulesButtonClicked() {
    removeButtons();
    auto* rules = new Rules();
    view->setFixedSize(1280, 720);
    view->show();
    view->setScene(rules);
    QObject::connect(rules, &Rules::returnToMenuSignal, this, &Menu::showMenu);
}

void Menu::onLeaderboardButtonClicked() {
    auto* leaderboard = new Leaderboard();
    leaderboard->show();
}

void Menu::onQuitButtonClicked() {
    QApplication::quit();
}

void Menu::showMenu() {
    view->hide();
    this->setVisible(true);
    this->raise();
    playButton->show();
    rulesButton->show();
    leaderboardButton->show();
    quitButton->show();
}