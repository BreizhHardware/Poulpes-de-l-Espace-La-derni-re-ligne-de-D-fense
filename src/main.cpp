#include <QApplication>
#include <QObject>
#include "MainWindow.h"
#include "Menu.h"
#include "Rules.h"


int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return application.exec();
}
