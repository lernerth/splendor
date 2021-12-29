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

QMap<Couleur, int> Carte::getPrix(){
    return prix;
}
