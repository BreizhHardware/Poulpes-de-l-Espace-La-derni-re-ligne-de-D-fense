//
// Created by breizhhardware on 26/04/24.
//

#include "Leaderboard.h"
#include <QVBoxLayout>
#include <QSqlDatabase>

Leaderboard::Leaderboard(QWidget *parent) : QGraphicsScene(parent) {
    QGraphicsTextItem* leaderboardLabel = new QGraphicsTextItem("Leaderboard");
    leaderboardLabel->setPlainText("Leaderboard");
    addItem(leaderboardLabel);
    // Add the table
    leaderboardTable = new QTableView();
    QGraphicsProxyWidget* proxy = this->addWidget(leaderboardTable);
    proxy->setPos(0, leaderboardLabel->boundingRect().height());
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("leaderboard.db");
    if (!db.open()) {
        qDebug() << "Error: unable to open database";
    }

    leaderboardModel = new QSqlTableModel(this, db);
    leaderboardModel->setTable("leaderboard");
    // Sort by number of waves completed in descending order
    leaderboardModel->setSort(1, Qt::DescendingOrder);
    leaderboardModel->select();

    leaderboardTable->setModel(leaderboardModel);
    // Add the return to menu button
    auto* returnButton = new QPushButton("Return to menu");
    QGraphicsProxyWidget* returnProxy = this->addWidget(returnButton);
    returnProxy->setPos(0, leaderboardLabel->boundingRect().height() + leaderboardTable->height());
    // Connect the return to menu button to the returnToMenu slot
    connect(returnButton, &QPushButton::clicked, this, &Leaderboard::returnToMenu);
}

void Leaderboard::returnToMenu() {
    emit returnToMenuSignal();
}