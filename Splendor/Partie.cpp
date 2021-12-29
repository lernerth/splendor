#include "Partie.h"


Partie::Partie(size_t n, QString j[3]){
    Nbjoueur = n;
    for (size_t i=1; i<=n; i++){
        ListeJoueur[i] = new Joueur(j[i-1]);
    }
};

const Joueur& Partie::getJoueur(size_t numJ) {
    const Joueur* j = nullptr;
    if(numJ>Nbjoueur) throw Exception("Ce joueur n'existe pas");
    j = this->ListeJoueur[numJ];
    return *j;
};
