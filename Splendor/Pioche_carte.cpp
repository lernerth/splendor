#include "Pioche_carte.h"

//constructeur
Pioche_carte::Pioche_carte() {
    nb_carte_initiale = 0;
    niveau = 1;
}


//Récupérateur
int Pioche_carte::getNbCarte(){
    this->nb_carte_initiale = nb_carte_initiale;
}

int Pioche_carte::getNiv(){
    this->niveau = niveau;
}


//setters
void Pioche_carte::setNbCarte(int nb_cartes_retirees){
    nb_carte_initiale = nb_carte_initiale-nb_cartes_retirees;
}

void Pioche_carte::setNiv(){
    this->niveau = niveau;
}