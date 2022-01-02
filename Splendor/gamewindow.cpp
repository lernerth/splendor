#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include <QPalette>
#include <string>
#include <QString>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1260,800);
    //Affichage des jetons du plateau
    afficherJetons();

    //Affichage du nom des joueurs
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::afficherJetons(){
    ui->JetonBlancPlateau->setPixmap(QPixmap(":/ressources/jetons/blanc.png"));
    ui->JetonNoirPlateau->setPixmap(QPixmap(":/ressources/jetons/noir.png"));
    ui->JetonBleuPlateau->setPixmap(QPixmap(":/ressources/jetons/bleu.png"));
    ui->JetonRougePlateau->setPixmap(QPixmap(":/ressources/jetons/rouge.png"));
    ui->JetonVertPlateau->setPixmap(QPixmap(":/ressources/jetons/vert.png"));
    ui->JetonJaunePlateau->setPixmap(QPixmap(":/ressources/jetons/or.png"));
}

void GameWindow::afficherJetonsJoueurs(){

}
