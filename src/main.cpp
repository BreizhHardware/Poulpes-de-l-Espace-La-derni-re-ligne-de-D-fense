#include <QApplication>
#include <QFontDatabase>
#include "MainWindow.h"
#include <QFile>
#include <QDebug>


int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    int fontId = QFontDatabase::addApplicationFont(":/ressources/Other/Orbitron-VariableFont_wght.ttf");
    if (fontId != -1) {
        QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont font(fontFamily);
        // Set the default font for the application
        application.setFont(font);
    }
    else {
        qWarning("Failed to load font");
    }
    MainWindow mainWindow;
    mainWindow.show();
    return application.exec();
}
