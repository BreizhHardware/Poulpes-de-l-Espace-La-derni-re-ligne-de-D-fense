//
// Created by breizhhardware on 29/04/24.
//

#include "Gameover.h"

Gameover::Gameover(Game* game, QWidget *parent) : QWidget(parent), game(game) {
    this->setStyleSheet("background-color: #071A22; color: #9EB1BD;");
    restartButton = new QPushButton("Restart", this);
    quitButton = new QPushButton("Quit", this);

    restartButton->setStyleSheet("background-color: #0A385A; color: #9EB1BD; font-size: 40px; font-weight: bold;");
    quitButton->setStyleSheet("background-color: #0A385A; color: #9EB1BD; font-size: 40px; font-weight: bold;");

    connect(restartButton, &QPushButton::clicked, this, &Gameover::onRestartButtonClicked);
    connect(quitButton, &QPushButton::clicked, this, &Gameover::onQuitButtonClicked);

    restartButton->setFixedHeight(53);
    quitButton->setFixedHeight(53);

    auto *buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(restartButton);
    buttonLayout->addSpacing(53);
    buttonLayout->addWidget(quitButton);

    auto* mainLayout = new QGridLayout(this);
    mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 0, 0);
    mainLayout->addLayout(buttonLayout, 1, 1);
    mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 2, 2);
    setLayout(mainLayout);
}

void Gameover::onRestartButtonClicked() {
    game->resetGame();
    emit restartGameSignal();
    this->close();
}

void Gameover::onQuitButtonClicked() {
    QApplication::quit();
}