#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include <string>
#include <QString>

GameWindow_t::GameWindow_t(Partie* p) :
    //QMainWindow(parent),
    ui(new Ui::GameWindow),
    partie(p)
{
    ui->setupUi(this);
    this->setFixedSize(1260,800);
    //Affichage des jetons du plateau
    afficherJetons();

    //Affichage à l'initialisation de la fenêtre
    ui->cadreCartes->setVisible(false);
    ui->cadreCartes2->setVisible(false);
    ui->cadreCartes3->setVisible(false);
    ui->cadreCartes4->setVisible(false);

    //Affichage du cadre de focus lors de l'achat ou la reservation de cartes
    connect(ui->acheter, SIGNAL(pressed()), this, SLOT(highlight()));
    connect(ui->reserver, SIGNAL(pressed()), this, SLOT(highlight()));
    connect(ui->prendreJetons, SIGNAL(pressed()), this, SLOT(highlight()));
    connect(ui->prendreJetons, SIGNAL(pressed()), this, SLOT(numChoix()));
    connect(ui->reserver, SIGNAL(pressed()), this, SLOT(numChoix()));
    connect(ui->acheter, SIGNAL(pressed()), this, SLOT(numChoix()));
}

GameWindow_t::~GameWindow_t()
{
    delete ui;
}

void GameWindow_t::afficherJetons(){
    ui->JetonBlancPlateau->setPixmap(QPixmap(":/ressources/jetons/blanc.png"));
    ui->JetonNoirPlateau->setPixmap(QPixmap(":/ressources/jetons/noir.png"));
    ui->JetonBleuPlateau->setPixmap(QPixmap(":/ressources/jetons/bleu.png"));
    ui->JetonRougePlateau->setPixmap(QPixmap(":/ressources/jetons/rouge.png"));
    ui->JetonVertPlateau->setPixmap(QPixmap(":/ressources/jetons/vert.png"));
    ui->JetonJaunePlateau->setPixmap(QPixmap(":/ressources/jetons/or.png"));
}

void GameWindow_t::afficherJetonsJoueurs(){

}

void GameWindow_t::highlight(){
    if (ui->acheter->isChecked()==true){
        ui->cadreCartes->setVisible(true);
        ui->cadreCartes2->setVisible(true);
        ui->cadreCartes3->setVisible(true);
        ui->cadreCartes4->setVisible(true);
    }
    if (ui->reserver->isChecked()==false){
        ui->cadreCartes->setVisible(true);
        ui->cadreCartes2->setVisible(true);
        ui->cadreCartes3->setVisible(true);
        ui->cadreCartes4->setVisible(true);
    }
    else {
        ui->cadreCartes->setVisible(false);
        ui->cadreCartes2->setVisible(false);
        ui->cadreCartes3->setVisible(false);
        ui->cadreCartes4->setVisible(false);
    }
}

void GameWindow_t::setNom1(QString nom1){
    ui->NomJoueur1->setText(nom1);
}

void GameWindow_t::setNom2(QString nom1){
    ui->NomJoueur2->setText(nom1);
}

void GameWindow_t::setNom3(QString nom1){
    ui->NomJoueur3->setText(nom1);
}

void GameWindow_t::setNom4(QString nom1){
    ui->NomJoueur4->setText(nom1);
}

void GameWindow_t::setNbJoueurs(size_t nb){
    if (nb < 3){
        //Noms
        ui->NomJoueur3->setVisible(false);
        ui->NomJoueur4->setVisible(false);
        //Nombre de jetons
        ui->jetonsBlancJ3->setVisible(false);
        ui->jetonsNoirJ3->setVisible(false);
        ui->jetonsBleuJ3->setVisible(false);
        ui->jetonsRougeJ3->setVisible(false);
        ui->jetonsVertJ3->setVisible(false);
        ui->jetonsOrJ3->setVisible(false);
        ui->jetonsBlancJ4->setVisible(false);
        ui->jetonsNoirJ4->setVisible(false);
        ui->jetonsBleuJ4->setVisible(false);
        ui->jetonsRougeJ4->setVisible(false);
        ui->jetonsVertJ4->setVisible(false);
        ui->jetonsOrJ4->setVisible(false);
        //Jetons
        ui->line_4->setVisible(false);
        ui->Blanc3->setVisible(false);
        ui->Noir3->setVisible(false);
        ui->Bleu3->setVisible(false);
        ui->Rouge3->setVisible(false);
        ui->Vert3->setVisible(false);
        ui->Or3->setVisible(false);
        ui->Blanc4->setVisible(false);
        ui->Noir4->setVisible(false);
        ui->Bleu4->setVisible(false);
        ui->Rouge4->setVisible(false);
        ui->Vert4->setVisible(false);
        ui->Or4->setVisible(false);
    }
    if (nb < 4){
        //Nombre de jetons
        ui->NomJoueur4->setVisible(false);
        ui->jetonsBlancJ4->setVisible(false);
        ui->jetonsNoirJ4->setVisible(false);
        ui->jetonsBleuJ4->setVisible(false);
        ui->jetonsRougeJ4->setVisible(false);
        ui->jetonsVertJ4->setVisible(false);
        ui->jetonsOrJ4->setVisible(false);
        //Jetons
        ui->Blanc4->setVisible(false);
        ui->Noir4->setVisible(false);
        ui->Bleu4->setVisible(false);
        ui->Rouge4->setVisible(false);
        ui->Vert4->setVisible(false);
        ui->Or4->setVisible(false);
    }
}

int GameWindow_t::numChoix(){
    if (ui->prendreJetons->isChecked() == true) this->choix = 1;
    else if (ui->acheter->isChecked() == true) this->choix = 2;
    else if(ui->reserver->isChecked() == true) this->choix = 3;
    //Partie::setChoix(choix);
    return this->choix;
}
