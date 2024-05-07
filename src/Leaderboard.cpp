//
// Created by breizhhardware on 26/04/24.
//

#include "Leaderboard.h"
#include <QVBoxLayout>
#include <QSqlDatabase>

Leaderboard::Leaderboard(QWidget *parent) : QGraphicsScene(parent) {
    auto* title = new QGraphicsTextItem();
    title->setPlainText("Poulpes de l'espace: La dernière ligne de défense");
    QGraphicsTextItem* leaderboardLabel = new QGraphicsTextItem("Leaderboard");
    leaderboardLabel->setPlainText("Leaderboard");
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    leaderboardLabel->setFont(font);
    leaderboardLabel->setDefaultTextColor(QColor(158, 177, 189));
    title->setFont(font);
    title->setDefaultTextColor(QColor(0, 231, 255));
    title->setPos(0, -50);
    leaderboardLabel->setPos(0, 20);
    addItem(title);
    addItem(leaderboardLabel);
    // Add the table
    leaderboardTable = new QTableView();
    leaderboardTable->setStyleSheet("QTableView {"
                                "border: 1px solid #0A5688;" // Couleur des bordures
                                "color: #9EB1BD;" // Couleur du texte
                                "background-color: #071A22;" // Couleur de fond
                                "}"
                                "QHeaderView::section {"
                                "background-color: #071A22;" // Couleur de fond des en-têtes
                                "color: #9EB1BD;" // Couleur du texte des en-têtes
                                "border: 1px solid #0A5688;" // Couleur des bordures des en-têtes
                                "}");
    // Access the corner widget
    QWidget* cornerWidget = leaderboardTable->findChild<QWidget*>("qt_scrollarea_corner");
    if (cornerWidget) {
        // Apply the stylesheet to the corner widget
        cornerWidget->setStyleSheet("background-color: #071A22;"); // Set the color to match your table's background color
    }
    QGraphicsProxyWidget* proxy = this->addWidget(leaderboardTable);
    proxy->setPos(0, leaderboardLabel->boundingRect().height() + 50);
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
    returnButton->setStyleSheet("background-color: #0A385A; color: #9EB1BD; font-size: 40px; font-weight: bold;");
    QGraphicsProxyWidget* returnProxy = this->addWidget(returnButton);
    returnProxy->setPos(0, leaderboardLabel->boundingRect().height() + leaderboardTable->height() + 150);
    // Connect the return to menu button to the returnToMenu slot
    connect(returnButton, &QPushButton::clicked, this, &Leaderboard::returnToMenu);
}

void Leaderboard::returnToMenu() {
    emit returnToMenuSignal();
}