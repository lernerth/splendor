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
    Joueur& getJoueur(size_t numJ);
    Controleur* getControleur() {return cont;}
    void PiocherJetons(Couleur c1, Couleur c2, Couleur c3, Joueur& joueur, Controleur* controleur);
    Carte& AcheterCarte(Carte* carte, Joueur& joueur, Controleur* controleur);
    Carte& ReserverCarte(Carte* carte, Joueur& joueur, Controleur* controleur);
    void FinDePartie();
    void VisiteNoble(Joueur *joueur);

private:
    friend class Controleur;
    Controleur* cont;
    size_t Nbjoueur;
    Joueur* ListeJoueur[3];

};

#endif // PARTIE_H
