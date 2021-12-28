#include "Carte.h"

int Carte::getNiveau(){
    return this->niveau;
}

Couleur Carte::getRemise(){
    return this->remise;
}

int Carte::getPrestige(){
    return this->prestige;
}


int Carte::getIdCarte(){
    return this->id_Carte;
}

QMap<Couleur, int> Carte::getPrix(){
    return this->prix;
}

/*
void Carte::setNiveau(int niv){
    this->niveau = niv;
}

void Carte::setPrix(int *tab_prix){
    for (int i = 0; i < 5; ++i){
        prix[i]=tab_prix[i];
    }
}

void Carte::setRemise(Couleur couleur){
    this->remise = couleur;
}

void Carte::setPrestige(int prestige){
    this->prestige = prestige;
}

void Carte::setIdCarte(int id_Carte){
    this->id_Carte = id_Carte;
}
*/
