//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_TILE_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_TILE_H
#include <QPushButton>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Tile : public QPushButton
{
    Q_OBJECT
public:
    enum Type { Road, Start, End, Tower, Other, Null };
    Tile(Type type, QWidget* parent = nullptr);
    Type getType() const;
    int gridX();
    int gridY();
    bool isPath();
    void setType(Type type);
    QGraphicsPixmapItem* getGraphics() const;
    void mousePressEvent(QMouseEvent* event) override;

private:
    Type type;
    QGraphicsPixmapItem* graphics;

signals:
    void tileClicked(int gridX, int gridY, QMouseEvent* event);
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_TILE_H
