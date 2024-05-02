//
// Created by breizhhardware on 02/05/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PROJECTILE_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PROJECTILE_H
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QLineF>
#include <QObject>
#include "Enemy.h"

class Projectile : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Projectile(QPointF start, QPointF end);
    QGraphicsRectItem* getGraphics();

public slots:
    void move();

private:
    QPointF start;
    QPointF end;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PROJECTILE_H