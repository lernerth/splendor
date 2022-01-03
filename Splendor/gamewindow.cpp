#include "gamewindow.h"

int GameWindow_t::choix = 0;


void GameWindow_t::numChoix(){
    if (ui->prendreJetons->isChecked() == true) partie->setChoix(1);
    else if (ui->acheter->isChecked() == true) partie->setChoix(2);
    else if(ui->reserver->isChecked() == true) partie->setChoix(3);
}

GameWindow_t::GameWindow_t(Partie* p) :
    //QMainWindow(parent),
    ui(new Ui::GameWindow),
    partie(p)
{
    ui->setupUi(this);
    this->setFixedSize(1460,800);
    //Affichage des jetons du plateau
    afficherJetons();
    AffichernbJetons();
    AfficherNobles();
    AfficherJoueur();

    //Affichage à l'initialisation de la fenêtre
    ui->cadreCartes->setVisible(false);
    ui->cadreCartes2->setVisible(false);
    ui->cadreCartes3->setVisible(false);
    ui->cadreCartes4->setVisible(false);
    //Débloquer le clic sur les cartes
    ui->carte00->setEnabled(false);
    ui->carte01->setEnabled(false);
    ui->carte02->setEnabled(false);
    ui->carte03->setEnabled(false);
    ui->carte10->setEnabled(false);
    ui->carte11->setEnabled(false);
    ui->carte12->setEnabled(false);
    ui->carte13->setEnabled(false);
    ui->carte20->setEnabled(false);
    ui->carte21->setEnabled(false);
    ui->carte22->setEnabled(false);
    ui->carte23->setEnabled(false);

    afficherCartes();
    afficherImages();

    //Affichage du cadre de focus lors de l'achat ou la reservation de cartes
    connect(ui->acheter, SIGNAL(clicked()), this, SLOT(highlight()));
    connect(ui->reserver, SIGNAL(clicked()), this, SLOT(highlight()));
    connect(ui->prendreJetons, SIGNAL(clicked()), this, SLOT(highlight()));
    connect(ui->prendreJetons, SIGNAL(clicked()), this, SLOT(numChoix()));
    connect(ui->reserver, SIGNAL(clicked()), this, SLOT(numChoix()));
    connect(ui->acheter, SIGNAL(clicked()), this, SLOT(numChoix()));
}

GameWindow_t::~GameWindow_t()
{
    delete ui;
}

void GameWindow_t::highlight(){
    if (ui->acheter->isChecked()==true){
        ui->cadreCartes->setVisible(true);
        ui->cadreCartes2->setVisible(true);
        ui->cadreCartes3->setVisible(true);
        ui->cadreCartes4->setVisible(true);
        //Débloquer le clic sur les cartes
        ui->carte00->setEnabled(true);
        ui->carte01->setEnabled(true);
        ui->carte02->setEnabled(true);
        ui->carte03->setEnabled(true);
        ui->carte10->setEnabled(true);
        ui->carte11->setEnabled(true);
        ui->carte12->setEnabled(true);
        ui->carte13->setEnabled(true);
        ui->carte20->setEnabled(true);
        ui->carte21->setEnabled(true);
        ui->carte22->setEnabled(true);
        ui->carte23->setEnabled(true);
        //Bloquer
    }
    else if (ui->reserver->isChecked()==true){
        ui->cadreCartes->setVisible(true);
        ui->cadreCartes2->setVisible(true);
        ui->cadreCartes3->setVisible(true);
        ui->cadreCartes4->setVisible(true);
        //Débloquer le clic sur les cartes
        ui->carte00->setEnabled(true);
        ui->carte01->setEnabled(true);
        ui->carte02->setEnabled(true);
        ui->carte03->setEnabled(true);
        ui->carte10->setEnabled(true);
        ui->carte11->setEnabled(true);
        ui->carte12->setEnabled(true);
        ui->carte13->setEnabled(true);
        ui->carte20->setEnabled(true);
        ui->carte21->setEnabled(true);
        ui->carte22->setEnabled(true);
        ui->carte23->setEnabled(true);
    }
    else if (ui->prendreJetons->isChecked()==true){
        ui->cadreCartes->setVisible(false);
        ui->cadreCartes2->setVisible(false);
        ui->cadreCartes3->setVisible(false);
        ui->cadreCartes4->setVisible(false);
        //Débloquer le clic sur les cartes
        ui->carte00->setEnabled(false);
        ui->carte01->setEnabled(false);
        ui->carte02->setEnabled(false);
        ui->carte03->setEnabled(false);
        ui->carte10->setEnabled(false);
        ui->carte11->setEnabled(false);
        ui->carte12->setEnabled(false);
        ui->carte13->setEnabled(false);
        ui->carte20->setEnabled(false);
        ui->carte21->setEnabled(false);
        ui->carte22->setEnabled(false);
        ui->carte23->setEnabled(false);
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
        //Prestige
        ui->PrestigeJoueur3->setVisible(false);
        ui->PrestigeJoueur4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
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
        ui->PrestigeJoueur4->setVisible(false);
        ui->label_6->setVisible(false);
    }
}

//Afficher les images des cartes
void GameWindow_t::afficherCartes(){
    //mapper = new QSignalMapper;


    //Niveau 3
    ui->carte20->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,0)->getImage()));
    ui->carte20->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte20]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,0);
    TableauBouton[8]=ui->carte20;
    ui->carte21->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,1)->getImage()));
    ui->carte21->setIconSize(QSize(122, 169));
    ui->carte22->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,2)->getImage()));
    ui->carte22->setIconSize(QSize(122, 169));
    ui->carte23->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,3)->getImage()));
    ui->carte23->setIconSize(QSize(122, 169));
    //Niveau 2
    ui->carte10->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,0)->getImage()));
    ui->carte10->setIconSize(QSize(122, 169));
    ui->carte11->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,1)->getImage()));
    ui->carte11->setIconSize(QSize(122, 169));
    ui->carte12->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,2)->getImage()));
    ui->carte12->setIconSize(QSize(122, 169));
    ui->carte13->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,3)->getImage()));
    ui->carte13->setIconSize(QSize(122, 169));
    //Niveau 1
    ui->carte00->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,0)->getImage()));
    ui->carte00->setIconSize(QSize(122, 169));
    ui->carte01->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,1)->getImage()));
    ui->carte01->setIconSize(QSize(122, 169));
    ui->carte02->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,2)->getImage()));
    ui->carte02->setIconSize(QSize(122, 169));
    ui->carte03->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,3)->getImage()));
    ui->carte03->setIconSize(QSize(122, 169));
}

//Afficher les images des jetons
void GameWindow_t::afficherJetons(){
    ui->JetonBlancPlateau->setIcon(QIcon("ressources/jetons/blanc.png"));
    ui->JetonBlancPlateau->setIconSize(QSize(80, 81));
    ui->JetonNoirPlateau->setIcon(QIcon("ressources/jetons/noir.png"));
    ui->JetonNoirPlateau->setIconSize(QSize(80, 81));
    ui->JetonBleuPlateau->setIcon(QIcon("ressources/jetons/bleu.png"));
    ui->JetonBleuPlateau->setIconSize(QSize(80, 81));
    ui->JetonRougePlateau->setIcon(QIcon("ressources/jetons/rouge.png"));
    ui->JetonRougePlateau->setIconSize(QSize(80, 81));
    ui->JetonVertPlateau->setIcon(QIcon("ressources/jetons/vert.png"));
    ui->JetonVertPlateau->setIconSize(QSize(80, 81));
    ui->JetonOrPlateau->setIcon(QIcon("ressources/jetons/or.png"));
    ui->JetonOrPlateau->setIconSize(QSize(80, 81));
}

//Afficher les images statiques
void GameWindow_t::afficherImages(){
    //affichage des pioches
    ui->Carte1->setPixmap(QPixmap("ressources/deck/1.png"));
    ui->Carte2->setPixmap(QPixmap("ressources/deck/2.png"));
    ui->Carte3->setPixmap(QPixmap("ressources/deck/3.png"));
    //affichage des jetons des joueurs
    //Joueur 1
    ui->Blanc1->setPixmap(QPixmap("ressources/jetons/blanc.png"));
    ui->Noir1->setPixmap(QPixmap("ressources/jetons/noir.png"));
    ui->Bleu1->setPixmap(QPixmap("ressources/jetons/bleu.png"));
    ui->Rouge1->setPixmap(QPixmap("ressources/jetons/rouge.png"));
    ui->Vert1->setPixmap(QPixmap("ressources/jetons/vert.png"));
    ui->Or1->setPixmap(QPixmap("ressources/jetons/or.png"));
    //Joueur 2
    ui->Blanc2->setPixmap(QPixmap("ressources/jetons/blanc.png"));
    ui->Noir2->setPixmap(QPixmap("ressources/jetons/noir.png"));
    ui->Bleu2->setPixmap(QPixmap("ressources/jetons/bleu.png"));
    ui->Rouge2->setPixmap(QPixmap("ressources/jetons/rouge.png"));
    ui->Vert2->setPixmap(QPixmap("ressources/jetons/vert.png"));
    ui->Or2->setPixmap(QPixmap("ressources/jetons/or.png"));
    //Joueur 3
    ui->Blanc3->setPixmap(QPixmap("ressources/jetons/blanc.png"));
    ui->Noir3->setPixmap(QPixmap("ressources/jetons/noir.png"));
    ui->Bleu3->setPixmap(QPixmap("ressources/jetons/bleu.png"));
    ui->Rouge3->setPixmap(QPixmap("ressources/jetons/rouge.png"));
    ui->Vert3->setPixmap(QPixmap("ressources/jetons/vert.png"));
    ui->Or3->setPixmap(QPixmap("ressources/jetons/or.png"));
    //Joueur 4
    ui->Blanc4->setPixmap(QPixmap("ressources/jetons/blanc.png"));
    ui->Noir4->setPixmap(QPixmap("ressources/jetons/noir.png"));
    ui->Bleu4->setPixmap(QPixmap("ressources/jetons/bleu.png"));
    ui->Rouge4->setPixmap(QPixmap("ressources/jetons/rouge.png"));
    ui->Vert4->setPixmap(QPixmap("ressources/jetons/vert.png"));
    ui->Or4->setPixmap(QPixmap("ressources/jetons/or.png"));
}

void GameWindow_t::AffichernbJetons(){
    ui->NbJetonsBlanc->display(Partie::getInstance()->getControleur()->getCouleur(Couleur::blanc));
    ui->NbJetonsBleu->display(Partie::getInstance()->getControleur()->getCouleur(Couleur::bleu));
    ui->NbJetonsRouge->display(Partie::getInstance()->getControleur()->getCouleur(Couleur::rouge));
    ui->NbJetonsNoir->display(Partie::getInstance()->getControleur()->getCouleur(Couleur::noir));
    ui->NbJetonsVert->display(Partie::getInstance()->getControleur()->getCouleur(Couleur::vert));
    ui->NbJetonsOr->display(Partie::getInstance()->getControleur()->getCouleur(Couleur::jaune));
};

void GameWindow_t::AfficherNobles(){
    ui->Noble1->setPixmap(QPixmap(Partie::getInstance()->getControleur()->getPlateau()->getNoble(0)->getImage()));
    ui->Noble2->setPixmap(QPixmap(Partie::getInstance()->getControleur()->getPlateau()->getNoble(1)->getImage()));
    ui->Noble3->setPixmap(QPixmap(Partie::getInstance()->getControleur()->getPlateau()->getNoble(2)->getImage()));
    if (Partie::getInstance()->getNbJoueurs()== 3 || Partie::getInstance()->getNbJoueurs() ==4) { ui->Noble4->setPixmap(QPixmap(Partie::getInstance()->getControleur()->getPlateau()->getNoble(3)->getImage()));}
    if (Partie::getInstance()->getNbJoueurs() ==4) { ui->Noble5->setPixmap(QPixmap(Partie::getInstance()->getControleur()->getPlateau()->getNoble(4)->getImage()));}
}

void GameWindow_t::AfficherJoueur(){
    ui->Joueuractuel->setText(Partie::getInstance()->getJoueur(1)->getNom());
}

/*void GameWindow_t::FindeTour(){
    switch(choix){
        case '1' :
            Couleur c1; //cliquer sur un jeton
            Couleur c2; //cliquer sur un jeton
            Couleur c3; //cliquer sur un jeton
            Partie::getInstance()->PiocherJetons(c1, c2, c3, *joueur_actuel, Partie::getInstance()->getControleur());

        case '2' :
            //cliquer sur une carte;
            Partie::getInstance()->AcheterCarte(c, *joueur_actuel, Partie::getInstance()->getControleur());

        case '3' :
            //cliquer sur une carte;
            Partie::getInstance()->ReserverCarte(c, *joueur_actuel, Partie::getInstance()->getControleur());
        default:
            tourfini = 0;
    }
}
*/
