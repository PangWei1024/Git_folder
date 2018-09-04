#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
qDebug() << "Can't find RTC";

    return a.exec();
}
