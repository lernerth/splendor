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
    QButtonGroup* cartes = new QButtonGroup(this);
    this->setFixedSize(1460,800);
    //Gestion des cartes
    creerGroupeCartes(cartes);

    //Affichage des jetons du plateau
    afficherJetons();
    AffichernbJetons();
    AfficherNobles();
    AfficherJoueur();
    ui->prendreJetons->setChecked(true);

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

    //Signal quand on clique sur un jeton pour l'achat
    connect(ui->JetonBlancPlateau, SIGNAL(clicked()), this, SLOT(clicJetonBlanc()));
    connect(ui->JetonNoirPlateau, SIGNAL(clicked()), this, SLOT(clicJetonNoir()));
    connect(ui->JetonBleuPlateau, SIGNAL(clicked()), this, SLOT(clicJetonBleu()));
    connect(ui->JetonRougePlateau, SIGNAL(clicked()), this, SLOT(clicJetonRouge()));
    connect(ui->JetonVertPlateau, SIGNAL(clicked()), this, SLOT(clicJetonVert()));
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
        //Bloquer les jetons
        ui->JetonBlancPlateau->setEnabled(false);
        ui->JetonNoirPlateau->setEnabled(false);
        ui->JetonBleuPlateau->setEnabled(false);
        ui->JetonRougePlateau->setEnabled(false);
        ui->JetonVertPlateau->setEnabled(false);
        ui->JetonOrPlateau->setEnabled(false);
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
        //Bloquer les jetons
        ui->JetonBlancPlateau->setEnabled(false);
        ui->JetonNoirPlateau->setEnabled(false);
        ui->JetonBleuPlateau->setEnabled(false);
        ui->JetonRougePlateau->setEnabled(false);
        ui->JetonVertPlateau->setEnabled(false);
        ui->JetonOrPlateau->setEnabled(false);
    }
    else if (ui->prendreJetons->isChecked()==true){
        ui->cadreCartes->setVisible(false);
        ui->cadreCartes2->setVisible(false);
        ui->cadreCartes3->setVisible(false);
        ui->cadreCartes4->setVisible(false);
        //Bloquer le clic sur les cartes
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
        //Débloquer les jetons
        ui->JetonBlancPlateau->setEnabled(true);
        ui->JetonNoirPlateau->setEnabled(true);
        ui->JetonBleuPlateau->setEnabled(true);
        ui->JetonRougePlateau->setEnabled(true);
        ui->JetonVertPlateau->setEnabled(true);
        ui->JetonOrPlateau->setEnabled(true);
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
    //TableauBouton[8]=ui->carte20;

    ui->carte21->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,1)->getImage()));
    ui->carte21->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte21]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,1);

    ui->carte22->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,2)->getImage()));
    ui->carte22->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte22]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,2);

    ui->carte23->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,3)->getImage()));
    ui->carte23->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte23]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(2,3);

    //Niveau 2
    ui->carte10->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,0)->getImage()));
    ui->carte10->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte10]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,0);

    ui->carte11->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,1)->getImage()));
    ui->carte11->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte11]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,1);

    ui->carte12->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,2)->getImage()));
    ui->carte12->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte12]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,2);

    ui->carte13->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,3)->getImage()));
    ui->carte13->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte13]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(1,3);

    //Niveau 1
    ui->carte00->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,0)->getImage()));
    ui->carte00->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte00]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,0);

    ui->carte01->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,1)->getImage()));
    ui->carte01->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte01]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,1);

    ui->carte02->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,2)->getImage()));
    ui->carte02->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte02]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,2);

    ui->carte03->setIcon(QIcon(Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,3)->getImage()));
    ui->carte03->setIconSize(QSize(122, 169));
    BoutonCarte[ui->carte03]=Partie::getInstance()->getControleur()->getPlateau()->getCarteGrille(0,3);
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

void GameWindow_t::FindeTour(){
    Carte* c;
    int actuel = 0;
    int test = 0;
    QPushButton* carteSelectionnee;
    Joueur * joueur_actuel = Partie::getInstance()->getJoueur(actuel);
    Carte ** Reserve = Partie::getInstance()->getJoueur(actuel)->getCartesReservees();
    Couleur c1 = priseJeton(); //cliquer sur un jeton
    Couleur c2 = priseJeton(); //cliquer sur un jeton
    Couleur c3 = priseJeton(); //cliquer sur un jeton
    switch(choix){
        case '1' :
            Partie::getInstance()->PiocherJetons(c1, c2, c3, *joueur_actuel, Partie::getInstance()->getControleur());

        case '2' :
            //cliquer sur une carte;
            carteSelectionnee = dynamic_cast<QPushButton*>(cartes->checkedButton());
            c = BoutonCarte[carteSelectionnee];
            Partie::getInstance()->AcheterCarte(c, *joueur_actuel, Partie::getInstance()->getControleur());

        case '3' :
            //cliquer sur une carte
            for(int i = 0; i <3 ; ++i) {
                    if(Reserve[i] == nullptr){
                        test = 1;
                    }
                    if(i==2){
                        std::cout <<"Impossible réserve déjà pleine";
                    }
            }
            if (test == 1){
                carteSelectionnee = dynamic_cast<QPushButton*>(cartes->checkedButton());
                c = BoutonCarte[carteSelectionnee];
                Partie::getInstance()->ReserverCarte(c, *joueur_actuel, Partie::getInstance()->getControleur());
            }
            else std::cout <<"Impossible réserve déjà pleine";

        default:
            //Message d'Erreur
            qDebug()<<"erreur";
    }
}


void GameWindow_t::creerGroupeCartes(QButtonGroup* group){
    group->addButton(ui->carte00);
    group->addButton(ui->carte01);
    group->addButton(ui->carte02);
    group->addButton(ui->carte03);
    group->addButton(ui->carte10);
    group->addButton(ui->carte11);
    group->addButton(ui->carte12);
    group->addButton(ui->carte13);
    group->addButton(ui->carte20);
    group->addButton(ui->carte21);
    group->addButton(ui->carte22);
    group->addButton(ui->carte23);
    group->setExclusive(true);
}

Couleur GameWindow_t::clicJetonBlanc(){
    return Couleur::blanc;
}

Couleur GameWindow_t::clicJetonNoir(){
    return Couleur::noir;
}

Couleur GameWindow_t::clicJetonBleu(){
    return Couleur::bleu;
}

Couleur GameWindow_t::clicJetonRouge(){
    return Couleur::rouge;
}

Couleur GameWindow_t::clicJetonVert(){
    return Couleur::vert;
}

Couleur GameWindow_t::priseJeton(){
    connect(ui->JetonBlancPlateau, SIGNAL(clicked()), this, SLOT(clicJetonBlanc()));
    connect(ui->JetonNoirPlateau, SIGNAL(clicked()), this, SLOT(clicJetonNoir()));
    connect(ui->JetonBleuPlateau, SIGNAL(clicked()), this, SLOT(clicJetonBleu()));
    connect(ui->JetonRougePlateau, SIGNAL(clicked()), this, SLOT(clicJetonRouge()));
    connect(ui->JetonVertPlateau, SIGNAL(clicked()), this, SLOT(clicJetonVert()));
}
