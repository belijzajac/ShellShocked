#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlag(Qt::WindowStaysOnTopHint);

    // run ./ShellShocked --frameless to have a frameless window
    // on KDE this is a recommended option
    if(argc == 2 && strcmp(argv[1], "--frameless") == 0)
        w.setWindowFlags(Qt::FramelessWindowHint);

    w.show();

    return a.exec();
}
