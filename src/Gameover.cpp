//
// Created by breizhhardware on 29/04/24.
//

#include "Gameover.h"

Gameover::Gameover(QWidget *parent) : QGraphicsScene(parent) {
    gameOverLabel = new QGraphicsTextItem("Game Over");
    gameOverLabel->setPos(640, 360);
    gameOverLabel->setDefaultTextColor(Qt::red);
    addItem(gameOverLabel);

    auto* layout = new QVBoxLayout();
    auto* restartButton = new QPushButton("Restart", parent);
    connect(restartButton, &QPushButton::clicked, this, &Gameover::restartGame);
    layout->addWidget(restartButton);

    auto* returnButton = new QPushButton("Return to menu", parent);
    connect(returnButton, &QPushButton::clicked, this, &Gameover::returnToMenu);
    layout->addWidget(returnButton);

    auto* widget = new QWidget();
    widget->setLayout(layout);

    auto* proxy = addWidget(widget);
    proxy->setPos(640, 400);
}

void Gameover::restartGame() {
    emit restartGameSignal();
}

void Gameover::returnToMenu() {
    emit returnToMenuSignal();
}