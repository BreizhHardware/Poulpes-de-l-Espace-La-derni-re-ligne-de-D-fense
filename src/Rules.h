//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_RULES_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_RULES_H
#include <QWidget>
#include <QLabel>

class Rules : public QWidget
{
Q_OBJECT
public:
    Rules(QWidget* parent = nullptr);

private:
    QLabel* rulesLabel;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_RULES_H
