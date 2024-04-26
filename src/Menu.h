//
// Created by breizhhardware on 26/04/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MENU_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MENU_H
#include <QWidget>
#include <QPushButton>

class Menu : public QWidget {
    Q_OBJECT

public:
    Menu(QWidget* parent = nullptr);

private slots:
    void onPlayButtonClicked();
    void onRulesButtonClicked();
    void onLeaderboardButtonClicked();
    void onQuitButtonClicked();

private:
    QPushButton* playButton;
    QPushButton* rulesButton;
    QPushButton* leaderboardButton;
    QPushButton* quitButton;
};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_MENU_H
