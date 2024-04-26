//
// Created by breizhhardware on 26/04/24.
//

#include "Rules.h"
#include <QVBoxLayout>
#include <QLayout>
#include <iostream>

Rules::Rules(QObject* parent) : QGraphicsScene(parent) {
    auto* rulesText = new QGraphicsTextItem();
    rulesText->setPlainText("Rules are simple:\n - You have to defend your base from the incoming waves of enemies.\n - You can place towers on the map to help you defend.\n - You can also move your personnal ship to help defend using the arrow key.\n - Good luck!");
    addItem(rulesText);
    // Add the return to menu button
    auto* returnButton = new QPushButton("Return to menu");
    QGraphicsProxyWidget* proxy = this->addWidget(returnButton);
    proxy->setPos(0, rulesText->boundingRect().height());
    // Connect the return to menu button to the returnToMenu slot
    connect(returnButton, &QPushButton::clicked, this, &Rules::returnToMenu);
}

void Rules::returnToMenu() {
    emit returnToMenuSignal();
}

