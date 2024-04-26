#include "MainWindow.h"
#include "Menu.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    Menu* menu = new Menu(this);
    this->setCentralWidget(menu);
    this->setWindowTitle("Poulpes de l'espace: La dernière ligne de défense");
    this->resize(1280, 720);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction* actionHelp = new QAction(tr("&About"), this);
    connect(actionHelp, SIGNAL(triggered()), this, SLOT(slot_aboutMenu()));
    helpMenu->addAction(actionHelp);
}

MainWindow::~MainWindow(){

}

void MainWindow::slot_aboutMenu(){
    QMessageBox msgBox;
    msgBox.setText("A small QT/C++ projet...");
    msgBox.setModal(true); // on souhaite que la fenetre soit modale i.e qu'on ne puisse plus cliquer ailleurs
    msgBox.exec();
}