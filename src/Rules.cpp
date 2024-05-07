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
                            " - You have to defend your base from the incoming waves of enemies.\n"
                            " - You can place towers on the map to help you defend.\n"
                            " - You can also move your personnal ship to help defend using the arrow key.\n"
                            " - Good luck!");
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

