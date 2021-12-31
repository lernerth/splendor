#include "joueur.h"

int Joueur::getJetons(Couleur c) {
    int nbJ = jetons[c];
    return nbJ;
}

int Joueur::getBonus(Couleur couleur){
    int nbBonus = bonus[couleur];
    return nbBonus;
}

int Joueur::getNbJetonsTot(){
    int t = jetons[Couleur::blanc]+jetons[Couleur::bleu]+jetons[Couleur::jaune]+jetons[Couleur::noir]+jetons[Couleur::rouge]+jetons[Couleur::vert];
    return t;
}

//Ajoute la carte entrée dans la réserve s'il reste de la place.
void Joueur::ajouter_carte_reserve(Carte* carte) {
    for(int i = 0; i <3 ; ++i) {
        if(cartes_reservees[i] == 0){
            cartes_reservees[i] = carte;
            break;
        }
        else if(i==2){
            std::cout <<"Impossible réserve déjà pleine";
            break;
        }
    }
}


//Retire une carte de la reserve. ATTENTION : il faut l'acheter après
void Joueur::retirer_carte_reserve(Carte* carte){
    //TO DO
}


//Achète une carte
void Joueur::acheter_carte(Carte* carte) {
    int i = 0;
    while(cartes_achetees[i] != 0) {
        i++;
        }
    cartes_achetees[i] = carte;
    prestige += carte->getPrestige();
    bonus[carte->getRemise()] ++;

}



//Donne un noble au joueur
void Joueur::recupérer_noble(Noble* n) {
    //TO DO
}




