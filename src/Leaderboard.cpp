//
// Created by breizhhardware on 26/04/24.
//

#include "Leaderboard.h"
#include <QVBoxLayout>
#include <QSqlDatabase>

Leaderboard::Leaderboard(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    leaderboardTable = new QTableView(this);
    layout->addWidget(leaderboardTable);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("leaderboard.db");

    if (!db.open()) {
        qDebug() << "Error: unable to open database";
    }

    leaderboardModel = new QSqlTableModel(this, db);
    leaderboardModel->setTable("leaderboard");
    // Sort by number of waves completed in descending order
    leaderboardModel->setSort(2, Qt::DescendingOrder);
    leaderboardModel->select();

    leaderboardTable->setModel(leaderboardModel);
}