#include "Partie.h"

Partie::Partie(){
    this->Nombre_Joueur = 0;
}

int Partie::getNombreJoueur(){
    return this->Nombre_Joueur;
}

void Partie::setNombreJoueur(int nb_joueur){
    this->Nombre_Joueur = nb_joueur;
}
