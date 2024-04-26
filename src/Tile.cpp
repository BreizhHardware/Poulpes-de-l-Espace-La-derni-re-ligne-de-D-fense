//
// Created by breizhhardware on 26/04/24.
//

#include "Tile.h"
#include <QBrush>

Tile::Tile(Tile::Type type, QGraphicsItem *parent) : QGraphicsRectItem(parent), type(type) {
    switch (type) {
        case Road:
            setBrush(QBrush(Qt::gray));
            break;
        case Start:
            setBrush(QBrush(Qt::green));
            break;
        case End:
            setBrush(QBrush(Qt::red));
            break;
        case Tower:
            setBrush(QBrush(Qt::blue));
            break;
        case Other:
            setBrush(QBrush(Qt::yellow));
            break;
    }
}

Tile::Type Tile::getType() const {
    return type;
}