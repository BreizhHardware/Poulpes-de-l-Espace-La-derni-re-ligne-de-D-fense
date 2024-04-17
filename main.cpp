#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QApplication::setApplicationName("Poules de l'espace: La dernière ligne de défense");
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
