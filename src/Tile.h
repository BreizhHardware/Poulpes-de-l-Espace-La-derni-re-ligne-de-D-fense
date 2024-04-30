//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_TILE_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_TILE_H
#include <QGraphicsRectItem>

class Tile : public QGraphicsRectItem
{
public:
    enum Type { Road, Start, End, Tower, Other };
    Tile(Type type, QGraphicsItem* parent = nullptr);
    Type getType() const;
    int gridX();
    int gridY();
    bool isPath();
    void setType(Type type);

private:
    Type type;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_TILE_H
