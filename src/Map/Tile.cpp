//
// Created by breizhhardware on 26/04/24.
//

#include "Tile.h"

Tile::Tile(Tile::Type type, QWidget *parent) : QPushButton(parent), type(type) {
    setType(type);
}

Tile::Type Tile::getType() const {
    if(this == nullptr) {
        return Null;
    }
    return type;
}

int Tile::gridX() {
    return x() / 50;
}

int Tile::gridY() {
    return y() / 50;
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
            pixmap = QPixmap(QString::fromStdString(":/ressources/Tile/road.png"));
            break;
        case Start:
            pixmap = QPixmap(QString::fromStdString(":/ressources/Tile/start.png"));
            break;
        case End:
            pixmap = QPixmap(QString::fromStdString(":/ressources/Tile/end.png"));
            break;
        case Tower:
            pixmap = QPixmap(QString::fromStdString(":/ressources/Tile/tower.png"));
            break;
        case Other:
            pixmap = QPixmap(QString::fromStdString(":/ressources/Tile/other.png"));
            break;
    }
    if (pixmap.isNull()) {
        return;
    } else {
        QIcon ButtonIcon(pixmap);
        this->setIcon(ButtonIcon);
        this->setIconSize(QSize(50, 50));
        this->setStyleSheet("padding: 0px; border: 0px;");
    }
}

QGraphicsPixmapItem* Tile::getGraphics() const {
    return graphics;
}

void Tile::mousePressEvent(QMouseEvent* event) {
    emit tileClicked(gridX(), gridY(), event);
}

void Tile::setOrientation(Direction previousDirection, Direction nextDirection) {
    QPixmap pixmap = this->icon().pixmap(this->iconSize());
    if ((previousDirection == Down && nextDirection == Right) || (previousDirection == Left && nextDirection == Up)) {
        pixmap = QPixmap(QString::fromStdString(":/ressources/Tile/turn.png"));
        if (previousDirection == Left && nextDirection == Up) {
            pixmap = pixmap.transformed(QTransform().rotate(180));
        }
    }
    else{
        switch (previousDirection) {
            case Up:
            case Down:
                // Rotate 90 degrees
                pixmap = pixmap.transformed(QTransform().rotate(90));
                break;
            case Left:
            case Right:
                // Do nothing
                break;
        }
    }
    // Update the graphics
    if(!pixmap.isNull()) {
        this->setIcon(QIcon(pixmap));
    }
}
