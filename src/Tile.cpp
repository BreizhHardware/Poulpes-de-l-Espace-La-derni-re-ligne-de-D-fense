//
// Created by breizhhardware on 26/04/24.
//

#include "Tile.h"

Tile::Tile(Tile::Type type, QGraphicsItem *parent) : QGraphicsRectItem(parent), type(type) {
    setType(type);
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
    if(this == nullptr) {
        return false;
    }
    return type == Road || type == Start || type == End;
}

void Tile::setType(Tile::Type type) {
    this->type = type;
    QPixmap pixmap;
    switch (type) {
        case Road:
            pixmap = QPixmap(QString::fromStdString("../ressources/road.png"));
            break;
        case Start:
            pixmap = QPixmap(QString::fromStdString("../ressources/start.png"));
            break;
        case End:
            pixmap = QPixmap(QString::fromStdString("../ressources/end.png"));
            break;
        case Tower:
            pixmap = QPixmap(QString::fromStdString("../ressources/tower.png"));
            break;
        case Other:
            pixmap = QPixmap(QString::fromStdString("../ressources/other.png"));
            break;
    }
    if (pixmap.isNull()) {
        return;
    } else {
        graphics = new QGraphicsPixmapItem();
        QPixmap scaledPixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation); // Scale the pixmap to 50x50 pixels
        graphics->setPixmap(scaledPixmap);
        graphics->setPos(x() * 50, y() * 50);
        graphics->setZValue(1);
    }
}

QGraphicsPixmapItem* Tile::getGraphics() const {
    return graphics;
}