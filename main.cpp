#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QObject::connect(&w, SIGNAL(closeApp()), &a, SLOT(quit()));

    return a.exec();
}
