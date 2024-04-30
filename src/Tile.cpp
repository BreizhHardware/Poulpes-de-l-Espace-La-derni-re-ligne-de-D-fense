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

int Tile::gridX() {
    return rect().x() / 50;
}

int Tile::gridY() {
    return rect().y() / 50;
}

bool Tile::isPath() {
    return type == Road || type == Start || type == End;
}

void Tile::setType(Tile::Type type) {
    this->type = type;
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