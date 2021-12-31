#include "Partie.h"


Partie::Partie(size_t n, QString j[3]){
    Nbjoueur = n;
    for (size_t i=0; i<n; i++){
        ListeJoueur[i] = new Joueur(j[i]);
    }
};

const Joueur& Partie::getJoueur(size_t numJ) {
    const Joueur* j = nullptr;
    if(numJ>Nbjoueur) throw Exception("Ce joueur n'existe pas");
    j = this->ListeJoueur[numJ];
    return *j;
};

void Partie::PiocherJetons(Couleur c1, Couleur c2, Couleur c3, Joueur* joueur, Controleur* controleur){
    if(c1 == c2){
        if (controleur->pj[c1]<4) throw Exception("Il est interdit de prendre deux jetons de même couleur s'il en reste moins de quatre disponibles...");
        controleur->retirer_Jetons(c1);
        controleur->retirer_Jetons(c2);

        joueur->ajouter_jeton(c1);
        joueur->ajouter_jeton(c2);
    }

    else if((c1 != c2)&&(c2!=c3)&&(c3!=c1)){
        if(controleur->pj[c1] == 0 || controleur->pj[c2] == 0 || controleur->pj[c3] == 0){
            throw Exception("Il n'y a plus de jeton dans cette pioche...");
        }

        controleur->retirer_Jetons(c1);
        controleur->retirer_Jetons(c2);
        controleur->retirer_Jetons(c3);

        joueur->ajouter_jeton(c1);
        joueur->ajouter_jeton(c2);
        joueur->ajouter_jeton(c3);
    }

    else{
        throw Exception ("Vous ne pouvez prendre que 2 jetons de la même couelur, ou 3 différents...");
    }

    if(joueur->getNbJetonsTot() > 10){
        throw Exception ("Vous ne pouvez pas avoir plus de 10 jetons, merci de vous en débarasser");
        for(int i=joueur->getNbJetonsTot()-10 ; i > 0; i--){
            Couleur c;
            //TO DO récupérer la couleur du jeton à defausser et la mettre dans la variable c
            joueur->retirer_jeton(c);
            controleur->rendre_Jetons(c);
        }
    }
}


Carte& Partie::AcheterCarte(Carte* carte, Joueur* joueur, Controleur* controleur){
    int manquant = 0;
    if(carte->getPrix(Couleur::blanc) - joueur->getBonus(Couleur::blanc) > joueur->getJetons(Couleur::blanc)){
        manquant =  manquant + carte->getPrix(Couleur::blanc) - joueur->getBonus(Couleur::blanc) - joueur->getJetons(Couleur::blanc);
    }

    if(carte->getPrix(Couleur::bleu) - joueur->getBonus(Couleur::bleu) > joueur->getJetons(Couleur::bleu)){
        manquant =  manquant + carte->getPrix(Couleur::bleu) - joueur->getBonus(Couleur::bleu) - joueur->getJetons(Couleur::bleu);
    }

    if(carte->getPrix(Couleur::noir) - joueur->getBonus(Couleur::noir) > joueur->getJetons(Couleur::noir)){
        manquant =  manquant + carte->getPrix(Couleur::noir) - joueur->getBonus(Couleur::noir) - joueur->getJetons(Couleur::noir);
    }

    if(carte->getPrix(Couleur::rouge) - joueur->getBonus(Couleur::rouge) > joueur->getJetons(Couleur::rouge)){
        manquant =  manquant + carte->getPrix(Couleur::rouge) - joueur->getBonus(Couleur::rouge) - joueur->getJetons(Couleur::rouge);
    }

    if(carte->getPrix(Couleur::vert) - joueur->getBonus(Couleur::vert) > joueur->getJetons(Couleur::vert)){
        manquant =  manquant + carte->getPrix(Couleur::vert) - joueur->getBonus(Couleur::vert) - joueur->getJetons(Couleur::vert);
    }


    if(manquant == 0){
        for(int i = 0 ; i<3 ; i++){
            if(joueur->cartes_reservees[i] == carte){
                joueur->retirer_carte_reserve(carte);
            }
        }
        controleur->retirer_carte(carte);
        joueur->acheter_carte(carte);
    }

    else if(manquant > 0 && manquant <= joueur->getJetons(Couleur::jaune)){
        for(int i = 0 ; i<3 ; i++){
            if(joueur->cartes_reservees[i] == carte){
                joueur->retirer_carte_reserve(carte);
            }
        }
        controleur->retirer_carte(carte);
        joueur->acheter_carte(carte);
    }

    else{
        throw Exception("Vous ne pouvez pas acheter cette carte...");
    }
}


Carte& ReserverCarte(Carte* carte, Joueur* joueur, Controleur* controleur){
     joueur->ajouter_carte_reserve(carte);//ajoute la carte dans la main du joueur, vérifie déjà s'il y en a 3 ou pas
     controleur->retirer_carte(carte);//enlève la carte ET la remplace
}
