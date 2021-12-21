#include "Pioche_carte.h"

//constructeur
Pioche_carte::Pioche_carte() {
    nb_carte = 0;
    niveau = 0;
}


//Récupérateur
int Pioche_carte::getNbCarte(){
    return this->nb_carte;
}

int Pioche_carte::getNiveau(){
    return this->niveau;
}


//setters
void Pioche_carte::setNbCarte(int nb_cartes_retirees){
    nb_carte = nb_carte-nb_cartes_retirees;
}

void Pioche_carte::setNiveau(int niv){
    this->niveau = niv;
}
