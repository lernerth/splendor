#include "gamewindow.h"




/*void test(){
    QString j[4];
    j[0] = "t";
    j[1] = "p";
    j[2] = "";
    j[3] = "";
    Partie* p = new Partie(2, j);
    GameWindow_t* g= new GameWindow_t(p);
}*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
#include <QString>
#include <string>

MainWindow::MainWindow(QWidget *parent):
      QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialisation des élements de la fenetre à l'ouverture
    ui->radioButton_2->setChecked(true);
    ui->boutonLancer->setEnabled(false);
    ui->avertissement->setVisible(true);
    ui->avertissement->setText("<font color = 'red'>Tous les joueurs doivent avoir un nom !</font>");
    //Joueur 3
    ui->Joueur3->setVisible(false);
    ui->nomJoueur3->setVisible(false);
    ui->J3bot->setVisible(false);
    ui->J3bot->setChecked(false);
    //Joueur 4
    ui->Joueur4->setVisible(false);
    ui->nomJoueur4->setVisible(false);
    ui->J4bot->setVisible(false);
    ui->J4bot->setChecked(false);

    //Gestion des extensions avec radio bouton
    connect(ui->radioButton,SIGNAL(pressed()), this, SLOT(oui()));
    connect(ui->radioButton_2,SIGNAL(pressed()), this, SLOT(non()));

    //Gestion du nombre de joueurs
    connect(ui->nbJoueurs, SIGNAL(valueChanged(int)), this, SLOT(setPlayers()));

    //Gestion du remplissage automatique du nom des bots
    connect(ui->J2bot, SIGNAL(clicked()), this, SLOT(autofillName2()));
    connect(ui->J3bot, SIGNAL(clicked()), this, SLOT(autofillName3()));
    connect(ui->J4bot, SIGNAL(clicked()), this, SLOT(autofillName4()));

    //Lancement de la partie
    connect(ui->boutonLancer, SIGNAL(clicked()), this, SLOT(fermer()));

    //Verification de la présence de noms de joueurs
    connect(ui->nomJoueur1, SIGNAL(textChanged(QString)), this, SLOT(checkName()));
    connect(ui->nomJoueur2, SIGNAL(textChanged(QString)), this, SLOT(checkName()));
    connect(ui->nomJoueur3, SIGNAL(textChanged(QString)), this, SLOT(checkName()));
    connect(ui->nomJoueur4, SIGNAL(textChanged(QString)), this, SLOT(checkName()));

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
        ui->Joueur3->setVisible(false);
        ui->Joueur4->setVisible(false);
        ui->nomJoueur3->setVisible(false);
        ui->nomJoueur4->setVisible(false);
        ui->nomJoueur3->clear();
        ui->nomJoueur4->clear();
        //Gestion du bouton de sélection Bot
        ui->J2bot->setVisible(true);
        ui->J3bot->setVisible(false);
        ui->J3bot->setChecked(false);
        ui->J4bot->setVisible(false);
        ui->J4bot->setChecked(false);
    }
    if (nbJoueurs == 3){
        //Noms des joueurs
        ui->nomJoueur1->setVisible(true);
        ui->nomJoueur2->setVisible(true);
        ui->nomJoueur3->setVisible(true);
        ui->Joueur3->setVisible(true);
        ui->Joueur4->setVisible(false);
        ui->nomJoueur4->setVisible(false);
        ui->nomJoueur4->clear();
        //Gestion du bouton de sélection Bot
        ui->J2bot->setVisible(true);
        ui->J3bot->setVisible(true);
        ui->J4bot->setVisible(false);
        ui->J4bot->setChecked(false);
    }
    if (nbJoueurs == 4){
        //Noms des joueurs
        ui->nomJoueur1->setEnabled(true);
        ui->nomJoueur2->setVisible(true);
        ui->nomJoueur3->setVisible(true);
        ui->nomJoueur4->setVisible(true);
        ui->Joueur3->setVisible(true);
        ui->Joueur4->setVisible(true);
        //Gestion du bouton de sélection Bot
        ui->J2bot->setVisible(true);
        ui->J3bot->setVisible(true);
        ui->J4bot->setVisible(true);

    }
}

void MainWindow::autofillName2(){
    if (ui->J2bot->isChecked()){
        ui->nomJoueur2->clear();
        ui->nomJoueur2->setText("Joueur 2");
    }
    if (ui->J2bot->isChecked() == false){
        ui->nomJoueur2->clear();
    }
}

void MainWindow::autofillName3(){
    if (ui->J3bot->isChecked()){
        ui->nomJoueur3->clear();
        ui->nomJoueur3->setText("Joueur 3");
    }
    if (ui->J3bot->isChecked() == false){
        ui->nomJoueur3->clear();
    }
}

void MainWindow::autofillName4(){
    if (ui->J4bot->isChecked()){
        ui->nomJoueur4->clear();
        ui->nomJoueur4->setText("Joueur 4");
    }
    if (ui->J4bot->isChecked() == false){
        ui->nomJoueur4->clear();
    }
}


void MainWindow::checkName(){
    if (ui->nomJoueur1->text()  == "" && ui->nomJoueur1->isVisible() == true){
        ui->boutonLancer->setEnabled(false);
    }
    else if (ui->nomJoueur2->text() == "" && ui->nomJoueur2->isVisible() == true){
        ui->boutonLancer->setEnabled(false);
    }
    else if (ui->nomJoueur3->text() == "" && ui->nomJoueur3->isVisible() == true){
        ui->boutonLancer->setEnabled(false);
    }
    else if (ui->nomJoueur4->text() == "" && ui->nomJoueur4->isVisible() == true){
        ui->boutonLancer->setEnabled(false);
    }
    else {
        ui->boutonLancer->setEnabled(true);
        ui->avertissement->setVisible(false);
    }
}


void MainWindow::fermer()
{
   MainWindow::close();
   QString joueur[4];

   if (ui->nbJoueurs->value()==2){
       joueur[0] = ui->nomJoueur1->text();
       joueur[1] = ui->nomJoueur2->text();
       joueur[2] = "";
       joueur[3] = "";

   }
   if (ui->nbJoueurs->value()==3){
       joueur[0] = ui->nomJoueur1->text();
       joueur[1] = ui->nomJoueur2->text();
       joueur[2] = ui->nomJoueur3->text();
       joueur[3] = "";

   }
   if (ui->nbJoueurs->value()==3){
       joueur[0] = ui->nomJoueur1->text();
       joueur[1] = ui->nomJoueur2->text();
       joueur[2] = ui->nomJoueur3->text();
       joueur[3] = ui->nomJoueur4->text();
   }
   Partie* p = new Partie(ui->nbJoueurs->value(), joueur);

   GameWindow_t* GameWindow = new GameWindow_t(p);
   GameWindow->setNom1(ui->nomJoueur1->text());
   GameWindow->setNom2(ui->nomJoueur2->text());
   GameWindow->setNom3(ui->nomJoueur3->text());
   GameWindow->setNom4(ui->nomJoueur4->text());
   GameWindow->setNbJoueurs(ui->nbJoueurs->value());
   GameWindow->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}

size_t MainWindow::getNbJoueurs() const {
    size_t nbJoueurs = ui->nbJoueurs->value();
    return nbJoueurs;
}




