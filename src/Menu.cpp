//
// Created by breizhhardware on 26/04/24.
//

#include "Menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent) {
    game = nullptr;
    auto* layout = new QVBoxLayout(this);
    view = new QGraphicsView(this);

    title = new QLabel("Poulpes de l'espace: La dernière ligne de défense");
    title->setStyleSheet("color: #00E7FF; font-size: 40px; font-weight: bold; text-align: center;");
    layout->addWidget(title);
    layout->setAlignment(title, Qt::AlignCenter);
    layout->addSpacing(53);

    playButton = new QPushButton("Jouer", this);
    playButton->setStyleSheet("background-color: #0A385A; color: #9EB1BD; font-size: 40px; font-weight: bold;");
    connect(playButton, &QPushButton::clicked, this, &Menu::onPlayButtonClicked);
    layout->addWidget(playButton);
    layout->addSpacing(53);

    rulesButton = new QPushButton("Règles", this);
    rulesButton->setStyleSheet("background-color: #0A385A; color: #9EB1BD; font-size: 40px; font-weight: bold;");
    connect(rulesButton, &QPushButton::clicked, this, &Menu::onRulesButtonClicked);
    layout->addWidget(rulesButton);
    layout->addSpacing(53);

    leaderboardButton = new QPushButton("Classement", this);
    leaderboardButton->setStyleSheet("background-color: #0A385A; color: #9EB1BD; font-size: 40px; font-weight: bold;");
    connect(leaderboardButton, &QPushButton::clicked, this, &Menu::onLeaderboardButtonClicked);
    layout->addWidget(leaderboardButton);
    layout->addSpacing(53);

    quitButton = new QPushButton("Quitter", this);
    quitButton->setStyleSheet("background-color: #0A385A; color: #9EB1BD; font-size: 40px; font-weight: bold;");
    connect(quitButton, &QPushButton::clicked, this, &Menu::onQuitButtonClicked);
    layout->addWidget(quitButton);
    layout->addSpacing(106);


    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void Menu::removeButtons() {
    title->hide();
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
    view->setScene(game->gameMap);
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
        this->raise();
    }
    title->show();
    playButton->show();
    rulesButton->show();
    leaderboardButton->show();
    quitButton->show();
}

void Menu::handleGameOver(){
    game->deleteLater();
}
