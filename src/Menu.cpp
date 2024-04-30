//
// Created by breizhhardware on 26/04/24.
//

#include "Menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent) {
    game = nullptr;
    auto* layout = new QVBoxLayout(this);
    view = new QGraphicsView(this);

    playButton = new QPushButton("Play", this);
    connect(playButton, &QPushButton::clicked, this, &Menu::onPlayButtonClicked);
    layout->addWidget(playButton);

    rulesButton = new QPushButton("Rules", this);
    connect(rulesButton, &QPushButton::clicked, this, &Menu::onRulesButtonClicked);
    layout->addWidget(rulesButton);

    leaderboardButton = new QPushButton("Leaderboard", this);
    connect(leaderboardButton, &QPushButton::clicked, this, &Menu::onLeaderboardButtonClicked);
    layout->addWidget(leaderboardButton);

    quitButton = new QPushButton("Quit", this);
    connect(quitButton, &QPushButton::clicked, this, &Menu::onQuitButtonClicked);
    layout->addWidget(quitButton);

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void Menu::removeButtons() {
    playButton->hide();
    rulesButton->hide();
    leaderboardButton->hide();
    quitButton->hide();
}

void Menu::onPlayButtonClicked() {
    // Remove buttons
    removeButtons();
    // Set the view size
    view->setFixedSize(1280, 720);
    view->show();
    // Create a new game
    game = new Game(this);
    game->start();

    // Show the game
    view->setScene(&game->gameMap);
    view->setFocus(); // Set focus to the QGraphicsView

    // Get a pointer to the MainWindow
    auto* mainWindow = qobject_cast<MainWindow*>(this->parentWidget());

    // Set the Game object as the central widget of the MainWindow
    if (mainWindow) {
        mainWindow->setCentralWidget(game);
        QTimer::singleShot(0, game, SLOT(setFocus()));
    }
}

void Menu::onRulesButtonClicked() {
    removeButtons();
    auto* rules = new Rules();
    view->setFixedSize(1280, 720);
    view->show();
    view->setScene(rules);
    QObject::connect(rules, &Rules::returnToMenuSignal, this, &Menu::showMenu);
}

void Menu::onLeaderboardButtonClicked() {
    removeButtons();
    auto* leaderboard = new Leaderboard();
    view->setFixedSize(1280, 720);
    view->show();
    view->setScene(leaderboard);
    QObject::connect(leaderboard, &Leaderboard::returnToMenuSignal, this, &Menu::showMenu);
}

void Menu::onQuitButtonClicked() {
    QApplication::quit();
}

void Menu::showMenu() {
    if(view){
        view->hide();
    }
    this->setVisible(true);
    if(this != nullptr) {
        qDebug() << this;
        this->raise();
    }
    playButton->show();
    rulesButton->show();
    leaderboardButton->show();
    quitButton->show();
}

void Menu::showMenuAfterGame() {
    // Hide the game view
    if(view){
        view->hide();
    }
    /*

    // Make the menu visible
    if(this != nullptr) {
        this->setVisible(true);
    }
    */

    // Show the menu buttons
    playButton->show();
    rulesButton->show();
    leaderboardButton->show();
    quitButton->show();
}

void Menu::showGameOver() {
    handleGameOver();
    qDebug() << "Game Over signal received in Menu::showGameOver()";
    // Return to the menu
    showMenu();
}

void Menu::handleGameOver(){
    game->deleteLater();
}
