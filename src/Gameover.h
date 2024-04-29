//
// Created by breizhhardware on 29/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAMEOVER_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAMEOVER_H
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsProxyWidget>

class Gameover : public QGraphicsScene
{
    Q_OBJECT
public:
    Gameover(QWidget* parent = nullptr);

private:
    QGraphicsTextItem* gameOverLabel;

private slots:
    void restartGame();
    void returnToMenu();

signals:
    void restartGameSignal();
    void returnToMenuSignal();

};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_GAMEOVER_H
