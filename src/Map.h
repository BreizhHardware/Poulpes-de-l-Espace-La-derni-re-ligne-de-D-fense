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
    Tile* getEndTile();
    Tile* getStartTile();
    QGraphicsScene scene;
    int getWidth();
    int getHeight();
    Tile* getTile(int x, int y);
    QVector<QVector<Tile*>> getTiles();

private:
    QVector<QVector<Tile*>> tiles;
    int width;
    int height;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MAP_H
