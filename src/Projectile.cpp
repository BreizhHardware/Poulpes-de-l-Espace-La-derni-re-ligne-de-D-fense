//
// Created by breizhhardware on 02/05/24.
//

#include "Projectile.h"

Projectile::Projectile(QPointF start, QPointF end) : start(start * 50), end(end * 50) {
    setRect(0, 0, 5, 5);
    setBrush(Qt::red);
    setPos(start *50 );
    setZValue(3);

    // Create a timer to move the projectile every 50ms
    QTimer* timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Projectile::move);
    timer->start(50);
}

void Projectile::move() {
    // Check if the projectile has reached an enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        Enemy *enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if (enemy) {
            // Update the end position to the current position of the enemy
            end = enemy->getPosition() * 50;

            // Remove the projectile
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    // Move the projectile towards the end point
    QLineF line(pos(), end);
    if (line.length() > 5) {
        line.setLength(line.length() - 5);
        setPos(line.p2());
    } else {
        // If the projectile has reached the end point, delete it
        scene()->removeItem(this);
        delete this;
    }
}