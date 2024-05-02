//
// Created by breizhhardware on 26/04/24.
//

#include "Map.h"
#include <QRandomGenerator>

Map::Map(QObject *parent) : QGraphicsScene(parent) {
}

void Map::generateMap(const int width, const int height) {
    tiles = QVector<QVector<Tile*>>(height, QVector<Tile*>(width));
    int x = 0, y = height - 1;
    // Length of the path
    int length = 0;
    // Randomize path length within a range
    int minLength = 20;
    int maxLength = 50;
    int pathLength = QRandomGenerator::global()->bounded(minLength, maxLength + 1);

    // Create a new Start tile
    Tile* startTile = new Tile(Tile::Start);
    startTile->setRect(x * 50, y * 50, 50, 50);
    startTile->getGraphics()->setPos(x * 50, y * 50);
    tiles[y][x] = startTile;
    addItem(startTile->getGraphics());
    length++;

    while (length < pathLength){
        // Randomly choose direction (horizontal or vertical)
        int direction = QRandomGenerator::global()->bounded(2);
        if (direction == 0) {
            // Move horizontally
            if (x < width - 1) {
                x++;
            }
        } else {
            // Move vertically
            if (y > 0) {
                y--;
            }
        }

        // Create a new Road tile
        Tile* tile = new Tile(Tile::Road);
        tile->setRect(x * 50, y * 50, 50, 50);
        tile->getGraphics()->setPos(x * 50, y * 50);
        tiles[y][x] = tile;
        addItem(tile->getGraphics());
        length++;
    }

    // Create a new End tile
    Tile* endTile = new Tile(Tile::End);
    endTile->setRect(x * 50, y * 50, 50, 50);
    endTile->getGraphics()->setPos(x * 50, y * 50);
    tiles[y][x] = endTile;
    addItem(endTile->getGraphics());

    // Fill the rest of the map with Other tiles
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (tiles[i][j] == nullptr){
                Tile* tile = new Tile(Tile::Other);
                tile->setRect(j * 50, i * 50, 50, 50);
                tile->getGraphics()->setPos(j * 50, i * 50);
                tiles[i][j] = tile;
                addItem(tile->getGraphics());
            }
        }
    }

    this->width = width;
    this->height = height;
}

Tile* Map::getEndTile() {
    for (int i = 0; i < tiles.size(); i++){
        for (int j = 0; j < tiles[i].size(); j++){
            if (tiles[i][j]->getType() == Tile::End){
                return tiles[i][j];
            }
        }
    }
    return nullptr;
}

Tile* Map::getStartTile() {
    for (int i = 0; i < tiles.size(); i++){
        for (int j = 0; j < tiles[i].size(); j++){
            if (tiles[i][j]->getType() == Tile::Start){
                return tiles[i][j];
            }
        }
    }
    return nullptr;
}

int Map::getWidth() {
    return width;
}

int Map::getHeight() {
    return height;
}

Tile* Map::getTile(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height){
        return tiles[y][x];
    }
    return nullptr;
}

QVector<QVector<Tile*>> Map::getTiles() {
    return tiles;
}