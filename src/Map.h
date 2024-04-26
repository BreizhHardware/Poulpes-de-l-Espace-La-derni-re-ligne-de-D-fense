//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MAP_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MAP_H
#include "Tile.h"
#include <QGraphicsScene>

class Map : public QGraphicsScene
{
public:
    Map(QObject* parent = nullptr);

    void generateMap(int width, int height);

    void show();

    Tile* getEndTile();
    Tile* getStartTile();


private:
    QVector<QVector<Tile*>> tiles;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MAP_H
