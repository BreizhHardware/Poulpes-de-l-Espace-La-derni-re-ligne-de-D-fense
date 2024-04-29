//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_RULES_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_RULES_H
#include <QWidget>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>

class Rules : public QGraphicsScene
{
Q_OBJECT
public:
    Rules(QObject* parent = nullptr);

private:
    QGraphicsTextItem* rulesLabel;

private slots:
    void returnToMenu();

signals:
    void returnToMenuSignal();
};

#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_RULES_H
