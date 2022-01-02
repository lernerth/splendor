#include "joueur.h"


Joueur::Joueur(int i, QString n){
    this->prestige = 0;
    this->id = i;
    this->nom = n;
    this->cartes_reservees = nullptr;
    this->cartes_achetees = nullptr;
    this->noble = nullptr;
}

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
        if(cartes_reservees[i] == nullptr){
            cartes_reservees[i] = carte;
            break;
        }
        else if(i==2){
            std::cout <<"Impossible réserve déjà pleine";
            break;
        }
    }
}


//Retire une carte de la reserve. ATTENTION : l'achat se fait automatiquement
void Joueur::retirer_carte_reserve(Carte* carte){
    for (int i = 0; i<3; i++){
        if (carte->getIdCarte() == cartes_reservees[i]->getIdCarte()){
            for (int j = i; j<3; j++){
                cartes_reservees[j] = cartes_reservees[j+1];
                cartes_reservees[j+1] = nullptr;
            }
        }
    }
    acheter_carte(carte); //achat automatique !
}

//Achète une carte
void Joueur::acheter_carte(Carte* carte) {
    int i = 0;
    while(cartes_achetees[i] != nullptr) {
        i++;
        }
    cartes_achetees[i] = carte;
    prestige += carte->getPrestige();
    bonus[carte->getRemise()] ++;

}



//Donne un noble au joueur
void Joueur::recuperer_noble(Noble* n) {
    int i = 0;
    while(noble[i] != nullptr) {
        i++;
        }
    noble[i] = n;
    prestige += n->getPrestige();
}




