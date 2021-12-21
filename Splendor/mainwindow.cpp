#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Auto check le non pour activer extension à la génération de la fenêtre
    ui->radioButton_2->setChecked(true);

    //Gestion des extensions avec radio bouton
    connect(ui->radioButton,SIGNAL(pressed()), this, SLOT(oui()));
    connect(ui->radioButton_2,SIGNAL(pressed()), this, SLOT(non()));

    //Gestion du nombre de joueurs
    connect(ui->nbJoueurs, SIGNAL(editingFinished()), this, SLOT(setPlayers()));

    //Gestion du remplissage automatique du nom des bots
    connect(ui->J2bot, SIGNAL(clicked()), this, SLOT(autofillName2()));
    connect(ui->J3bot, SIGNAL(clicked()), this, SLOT(autofillName3()));
    connect(ui->J4bot, SIGNAL(clicked()), this, SLOT(autofillName4()));
}

void MainWindow::oui(){
    ui->extension->setEnabled(true);
}

void MainWindow::non(){
    ui->extension->setEnabled(false);
}

void MainWindow::setPlayers(){
    int nbJoueurs = ui->nbJoueurs->value();
    if (nbJoueurs == 2){
        //Noms des joueurs
        ui->nomJoueur1->setEnabled(true);
        ui->nomJoueur2->setEnabled(true);
        ui->nomJoueur3->setEnabled(false);
        ui->nomJoueur4->setEnabled(false);
        ui->nomJoueur3->clear();
        ui->nomJoueur4->clear();
        //Gestion du bouton de sélection Bot
        ui->J2bot->setEnabled(true);
        ui->J3bot->setEnabled(false);
        ui->J3bot->setChecked(false);
        ui->J4bot->setEnabled(false);
        ui->J4bot->setChecked(false);
    }
    if (nbJoueurs == 3){
        //Noms des joueurs
        ui->nomJoueur1->setEnabled(true);
        ui->nomJoueur2->setEnabled(true);
        ui->nomJoueur3->setEnabled(true);
        ui->nomJoueur4->setEnabled(false);
        ui->nomJoueur4->clear();
        //Gestion du bouton de sélection Bot
        ui->J2bot->setEnabled(true);
        ui->J3bot->setEnabled(true);
        ui->J4bot->setEnabled(false);
        ui->J4bot->setChecked(false);
    }
    if (nbJoueurs == 4){
        //Noms des joueurs
        ui->nomJoueur1->setEnabled(true);
        ui->nomJoueur2->setEnabled(true);
        ui->nomJoueur3->setEnabled(true);
        ui->nomJoueur4->setEnabled(true);
        //Gestion du bouton de sélection Bot
        ui->J2bot->setEnabled(true);
        ui->J3bot->setEnabled(true);
        ui->J4bot->setEnabled(true);

    }
}

void MainWindow::autofillName2(){
    if (ui->J2bot->isChecked()){
        ui->nomJoueur2->clear();
        ui->nomJoueur2->append("Joueur 2");
    }
    if (ui->J2bot->isChecked() == false){
        ui->nomJoueur2->clear();
    }
}

void MainWindow::autofillName3(){
    if (ui->J3bot->isChecked()){
        ui->nomJoueur3->clear();
        ui->nomJoueur3->append("Joueur 3");
    }
    if (ui->J3bot->isChecked() == false){
        ui->nomJoueur3->clear();
    }
}

void MainWindow::autofillName4(){
    if (ui->J4bot->isChecked()){
        ui->nomJoueur4->clear();
        ui->nomJoueur4->append("Joueur 4");
    }
    if (ui->J4bot->isChecked() == false){
        ui->nomJoueur4->clear();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

