#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include <QString>
#include <string>



void test(){
    QString j[4];
    j[0] = "t";
    j[1] = "p";
    j[2] = "";
    j[3] = "";
    Partie* p = new Partie(2, j);
    GameWindow_t* g= new GameWindow_t(p);
}
