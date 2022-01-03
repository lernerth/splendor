#include "Partie.h"

Partie::handler Partie::h;

Partie::Partie(){
    cont = nullptr;
    Nbjoueur =0;
    choice = 0;
    for (int i = 0; i<4; i++){
        ListeJoueur[i] = nullptr;
    }
};

void Partie::SetPartie(size_t n, QString j[4], Partie* p){
    p->choice = 0;
    p->Nbjoueur = n;
    for (size_t i=0; i<n; i++){
        p->ListeJoueur[i] = new Joueur(i+1, j[i]);
    }
    p->cont = new Controleur();
    p->cont->initialiser_Plateau(n, cont);
};

Joueur* Partie::getJoueur(size_t numJ) {
    Joueur* j = nullptr;
    if(numJ>Nbjoueur) throw Exception("Ce joueur n'existe pas");
    j = this->ListeJoueur[numJ];
    return j;
};

void Partie::PiocherJetons(Couleur c1, Couleur c2, Couleur c3, Joueur& joueur, Controleur* controleur){
    if(c1 == c2){
        if (controleur->pj[c1]<4) throw Exception("Il est interdit de prendre deux jetons de même couleur s'il en reste moins de quatre disponibles...");
        controleur->retirer_Jetons(c1);
        controleur->retirer_Jetons(c2);

        joueur.ajouter_jeton(c1);
        joueur.ajouter_jeton(c2);
    }

    else if((c1 != c2)&&(c2!=c3)&&(c3!=c1)){
        if(controleur->pj[c1] == 0 || controleur->pj[c2] == 0 || controleur->pj[c3] == 0){
            throw Exception("Il n'y a plus de jeton dans cette pioche...");
        }

        controleur->retirer_Jetons(c1);
        controleur->retirer_Jetons(c2);
        controleur->retirer_Jetons(c3);

        joueur.ajouter_jeton(c1);
        joueur.ajouter_jeton(c2);
        joueur.ajouter_jeton(c3);
    }

    else{
        throw Exception ("Vous ne pouvez prendre que 2 jetons de la même couelur, ou 3 différents...");
    }

    if(joueur.getNbJetonsTot() > 10){
        throw Exception ("Vous ne pouvez pas avoir plus de 10 jetons, merci de vous en débarasser");
        for(int i=joueur.getNbJetonsTot()-10 ; i > 0; i--){
            Couleur c;
            //TO DO récupérer la couleur du jeton à defausser et la mettre dans la variable c A VOIR EN FONCTION DE L'INTERFACE !!
            joueur.retirer_jeton(c);
            controleur->rendre_Jetons(c);
        }
    }
}


Carte& Partie::AcheterCarte(Carte* carte, Joueur& joueur, Controleur* controleur){
    int manquant = 0;
    int test = 0;
    if(carte->getPrix(Couleur::blanc) - joueur.getBonus(Couleur::blanc) > joueur.getJetons(Couleur::blanc)){
        manquant =  manquant + carte->getPrix(Couleur::blanc) - joueur.getBonus(Couleur::blanc) - joueur.getJetons(Couleur::blanc);
    }

    if(carte->getPrix(Couleur::bleu) - joueur.getBonus(Couleur::bleu) > joueur.getJetons(Couleur::bleu)){
        manquant =  manquant + carte->getPrix(Couleur::bleu) - joueur.getBonus(Couleur::bleu) - joueur.getJetons(Couleur::bleu);
    }

    if(carte->getPrix(Couleur::noir) - joueur.getBonus(Couleur::noir) > joueur.getJetons(Couleur::noir)){
        manquant =  manquant + carte->getPrix(Couleur::noir) - joueur.getBonus(Couleur::noir) - joueur.getJetons(Couleur::noir);
    }

    if(carte->getPrix(Couleur::rouge) - joueur.getBonus(Couleur::rouge) > joueur.getJetons(Couleur::rouge)){
        manquant =  manquant + carte->getPrix(Couleur::rouge) - joueur.getBonus(Couleur::rouge) - joueur.getJetons(Couleur::rouge);
    }

    if(carte->getPrix(Couleur::vert) - joueur.getBonus(Couleur::vert) > joueur.getJetons(Couleur::vert)){
        manquant =  manquant + carte->getPrix(Couleur::vert) - joueur.getBonus(Couleur::vert) - joueur.getJetons(Couleur::vert);
    }


    if(manquant == 0){
        for(int i = 0 ; i<3 ; i++){
            if(joueur.cartes_reservees[i] == carte){
                joueur.retirer_carte_reserve(carte);
                test = 1;
            }
        }
        if (test == 0){
            controleur->remplacer_carte(0, 0, controleur); //Remplacer 0, 0 par niveau indice envoyer par interface
            joueur.acheter_carte(carte);

        }
        for (int j = 0; j<(carte->getPrix(Couleur::blanc) - joueur.getBonus(Couleur::blanc)); j++){
            joueur.retirer_jeton(Couleur::blanc);
            controleur->rendre_Jetons(Couleur::blanc);
        }
        for (int j = 0; j<(carte->getPrix(Couleur::bleu) - joueur.getBonus(Couleur::bleu)); j++){
            joueur.retirer_jeton(Couleur::bleu);
            controleur->rendre_Jetons(Couleur::bleu);
        }
        for (int j = 0; j<(carte->getPrix(Couleur::noir) - joueur.getBonus(Couleur::noir)); j++){
            joueur.retirer_jeton(Couleur::noir);
            controleur->rendre_Jetons(Couleur::noir);
        }
        for (int j = 0; j<(carte->getPrix(Couleur::rouge) - joueur.getBonus(Couleur::rouge)); j++){
            joueur.retirer_jeton(Couleur::rouge);
            controleur->rendre_Jetons(Couleur::rouge);
        }
        for (int j = 0; j<(carte->getPrix(Couleur::vert) - joueur.getBonus(Couleur::vert)); j++){
            joueur.retirer_jeton(Couleur::vert);
            controleur->rendre_Jetons(Couleur::vert);
        }
    }

    else if(manquant > 0 && manquant <= joueur.getJetons(Couleur::jaune)){
        for(int i = 0 ; i<3 ; i++){
            if(joueur.cartes_reservees[i] == carte){
                joueur.retirer_carte_reserve(carte);
                test = 1;
            }
        }
        if (test == 0){
            controleur->remplacer_carte(0, 0, controleur);
            joueur.acheter_carte(carte);
        }
        for (int j = 0; j<(carte->getPrix(Couleur::blanc) - joueur.getBonus(Couleur::blanc)); j++){
            joueur.retirer_jeton(Couleur::blanc);
            controleur->rendre_Jetons(Couleur::blanc);
            if (joueur.getJetons(Couleur::blanc)<0) joueur.jetons[Couleur::blanc]=0;
        }
        for (int j = 0; j<(carte->getPrix(Couleur::bleu) - joueur.getBonus(Couleur::bleu)); j++){
            joueur.retirer_jeton(Couleur::bleu);
            controleur->rendre_Jetons(Couleur::bleu);
            if (joueur.getJetons(Couleur::bleu)<0) joueur.jetons[Couleur::bleu]=0;
        }
        for (int j = 0; j<(carte->getPrix(Couleur::noir) - joueur.getBonus(Couleur::noir)); j++){
            joueur.retirer_jeton(Couleur::noir);
            controleur->rendre_Jetons(Couleur::noir);
            if (joueur.getJetons(Couleur::noir)<0) joueur.jetons[Couleur::noir]=0;
        }
        for (int j = 0; j<(carte->getPrix(Couleur::rouge) - joueur.getBonus(Couleur::rouge)); j++){
            joueur.retirer_jeton(Couleur::rouge);
            controleur->rendre_Jetons(Couleur::rouge);
            if (joueur.getJetons(Couleur::rouge)<0) joueur.jetons[Couleur::rouge]=0;
        }
        for (int j = 0; j<(carte->getPrix(Couleur::vert) - joueur.getBonus(Couleur::vert)); j++){
            joueur.retirer_jeton(Couleur::vert);
            controleur->rendre_Jetons(Couleur::vert);
            if (joueur.getJetons(Couleur::vert)<0) joueur.jetons[Couleur::vert]=0;
        }
        for (int j = 0; j<manquant; j++){
            joueur.retirer_jeton(Couleur::jaune);
            controleur->rendre_Jetons(Couleur::jaune);
        }
    }

    else{
        throw Exception("Vous ne pouvez pas acheter cette carte...");
    }
    return *carte;
}


Carte& Partie::ReserverCarte(Carte* carte, Joueur& joueur, Controleur* controleur){
     joueur.ajouter_carte_reserve(carte);//ajoute la carte dans la main du joueur, vérifie déjà s'il y en a 3 ou pas
     controleur->remplacer_carte(0, 0, controleur);//enlève la carte ET la remplace
     return *carte;
}

void Partie::VisiteNoble(Joueur *joueur){
    Noble* actuel;
    int i = 0;
    int test = 0;
    while (i < cont->noble->getNbNobles() && test == 0){
        actuel = cont->noble->getNoble(i);
        if (actuel->getPrix(Couleur::blanc)<= joueur->getBonus(Couleur::blanc) && actuel->getPrix(Couleur::bleu)<= joueur->getBonus(Couleur::bleu) && actuel->getPrix(Couleur::noir)<= joueur->getBonus(Couleur::noir) && actuel->getPrix(Couleur::rouge)<= joueur->getBonus(Couleur::rouge) && actuel->getPrix(Couleur::vert)<= joueur->getBonus(Couleur::vert)){
            cont->retirer_Noble(i);
            joueur->recuperer_noble(actuel);
        }
    }
}

void Partie::setChoix(int c){
    this->choice = c;
}

void Partie::Tour(Partie* p){
    int fin = 0;
    int tourfini = 0;

    Joueur* joueur_actuel;
    Controleur* controleur;
    int choix = 0;
    Carte *c;
    size_t n = p->Nbjoueur;

    while(fin != 1){
        for(size_t i = 0; i < n; i++){
            joueur_actuel = getJoueur(i);
            controleur = getControleur();
            while(tourfini == 0){

                qDebug()<<"choix"<<choix;
                switch(choix){
                    case '1' :
                        Couleur c1; //cliquer sur un jeton
                        Couleur c2; //cliquer sur un jeton
                        Couleur c3; //cliquer sur un jeton
                        PiocherJetons(c1, c2, c3, *joueur_actuel, controleur);

                    case '2' :
                        //cliquer sur une carte;
                        AcheterCarte(c, *joueur_actuel, controleur);

                    case '3' :
                        //cliquer sur une carte;
                        ReserverCarte(c, *joueur_actuel, controleur);
                    default:
                        tourfini = 0;
                }
            }
            choix = 0;
            tourfini = 0;

            if(joueur_actuel->getPrestige()>=15){
                fin = 1;
            }
        }
    }

    void FinDePartie();
}

/*void Partie::AfficherCarte(int i, int j, Partie* p){
    QString carte;
    carte = "carte"+QString::toStdString(std::to_string(i))+QString::toStdString(std::to_string(j))
}*/
