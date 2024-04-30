//
// Created by breizhhardware on 29/04/24.
//

#include "Gameover.h"

Gameover::Gameover(Game* game, QWidget *parent) : QWidget(parent), game(game) {
    restartButton = new QPushButton("Restart", this);
    quitButton = new QPushButton("Quit", this);

    restartButton->setFixedSize(100, 50);
    quitButton->setFixedSize(100, 50);

    connect(restartButton, &QPushButton::clicked, this, &Gameover::onRestartButtonClicked);
    connect(quitButton, &QPushButton::clicked, this, &Gameover::onQuitButtonClicked);

    auto *buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(restartButton);
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