#include "MainWindow.h"
#include "Menu.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    Menu* menu = new Menu(this);
    this->setCentralWidget(menu);
    this->setWindowTitle("Poulpes de l'espace: La dernière ligne de défense");
    this->resize(1300, 740);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction* actionHelp = new QAction(tr("&About"), this);
    connect(actionHelp, SIGNAL(triggered()), this, SLOT(slot_aboutMenu()));
    helpMenu->addAction(actionHelp);
}

MainWindow::~MainWindow(){

}

void MainWindow::slot_aboutMenu(){
    QMessageBox msgBox;
    msgBox.setText("<strong>Poulpes de l'espace: La dernière ligne de défense</strong><br><br>"
                   "Version 1.0<br><br>"
                   "A game by BreizhHardware and Amalizzy<br><br>"
                   "2024<br><br>"
                   "This game is a tower defense game where you have to defend your base from the incoming waves of enemies.<br><br>"
                   "This game was made for the C++ course at the ISEN Nantes.<br><br>"
                   "The ships design is mainly inspired by the game Star Citizen.<br><br>"
                   "The game is open source and can be found on GitHub at the following link:<br>"
                   "<a href='https://github.com/BreizhHardware/Poulpes-de-l-Espace-La-derniere-ligne-de-Defense'>https://github.com/BreizhHardware/Poulpes-de-l-Espace-La-derniere-ligne-de-Defense</a><br><br>"
                   "Enjoy the game!<br><br>"
                   "Star Citizen is a game by Cloud Imperium Games.<br>"
                   "This game is not affiliated with Star Citizen or Cloud Imperium Games.");
    // This is needed to interpret the text as HTML
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setModal(true);
    msgBox.exec();
}