#include "Carte.h"

int Carte::getNiveau(){
    return niveau;
}

Couleur Carte::getRemise(){
    return remise;
}

int Carte::getPrestige(){
    return prestige;
}


int Carte::getIdCarte(){
    return id_Carte;
}

int Carte::getPrix(Couleur c){
    int p = prix[c];
    return p;
}
