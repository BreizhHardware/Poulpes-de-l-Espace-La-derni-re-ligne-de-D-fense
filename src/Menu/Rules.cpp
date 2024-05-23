//
// Created by breizhhardware on 26/04/24.
//

#include "Rules.h"

Rules::Rules(QObject* parent) : QGraphicsScene(parent) {
    auto* rulesText = new QGraphicsTextItem();
    auto* title = new QGraphicsTextItem();
    title->setPlainText("Poulpes de l'espace: La dernière ligne de défense");
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    rulesText->setFont(font);
    rulesText->setDefaultTextColor(QColor(158, 177, 189));
    rulesText->setPlainText("Rules are simple:\n"
                            "   - Objective: Defend your base from waves of incoming enemies.\n"
                            "   - Controls:\n"
                            "       - Camera Movement: Use the arrow keys to move the camera.\n"
                            "       - Player Movement: Use the ZQSD keys to move your player.\n"
                            "   - Gameplay Mechanics:\n"
                            "       - Placing Towers: Click the left mouse button to place a tower on the map.\n"
                            "       - Upgrading Towers: Click the left mouse button on an existing tower to upgrade it.\n"
                            "   - Combat:\n"
                            "       - If enemies touch the player, they are killed. The player takes damage but\n"
                            "       earns money.\n"
                            "       - If enemies reach the end of the path, the player takes damage but does not\n"
                            "       earn money.\n"
                            "   - Goal: Survive as many waves as possible and protect your base.\n"
                            "Good luck, and have fun defending!");
    title->setFont(font);
    title->setDefaultTextColor(QColor(0, 231, 255));
    title->setPos(0, -50);
    rulesText->setPos(0, 20);
    addItem(title);
    addItem(rulesText);
    // Add the return to menu button
    auto* returnButton = new QPushButton("Return to menu");
    returnButton->setStyleSheet("background-color: #0A385A; color: #9EB1BD; font-size: 40px; font-weight: bold;");
    QGraphicsProxyWidget* proxy = this->addWidget(returnButton);
    proxy->setPos(0, rulesText->boundingRect().height() + 50);
    // Connect the return to menu button to the returnToMenu slot
    connect(returnButton, &QPushButton::clicked, this, &Rules::returnToMenu);
}

void Rules::returnToMenu() {
    emit returnToMenuSignal();
}

