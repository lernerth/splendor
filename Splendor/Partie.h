#ifndef PARTIE_H
#define PARTIE_H

#include <iostream>
#include <string>
#include <vector>
#include <QMap>
#include "Carte.h"
#include "pioche_noble.h"
#include "Noble.h"
#include "Pioche_carte.h"
#include "controleur.h"
#include "global.h"
#include "Plateau.h"
#include "Exception.h"
#include "joueur.h"

using namespace std;

class Partie {
public:
    Partie(size_t n, QString j[3]);
    size_t getNbJoueurs() {return Nbjoueur;};
    const Joueur& getJoueur(size_t numJ);
    void PiocherJetons();
    Carte& AcheterCarte();
    Carte& ReserverCarte();


private:
    size_t Nbjoueur;
    Joueur ListeJoueur;

};

#endif // PARTIE_H
