#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

//indice 0:blanc 1:bleu 2:noir 3:rouge 4:vert 5:jaune
