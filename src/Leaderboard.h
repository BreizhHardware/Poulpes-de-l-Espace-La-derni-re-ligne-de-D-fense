//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_LEADERBOARD_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_LEADERBOARD_H
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsProxyWidget>
#include <QTableView>
#include <QtSql/QSqlTableModel>

class Leaderboard : public QGraphicsScene
{
    Q_OBJECT
public:
    Leaderboard(QWidget* parent = nullptr);

private:
    QTableView* leaderboardTable;
    QSqlTableModel* leaderboardModel;

private slots:
    void returnToMenu();

signals:
    void returnToMenuSignal();
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_LEADERBOARD_H
