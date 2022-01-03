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
#include "gamewindow.h"

using namespace std;

class Partie {
public:
    size_t getNbJoueurs() {return Nbjoueur;};
    Joueur* getJoueur(size_t numJ);
    Controleur* getControleur() {return cont;}
    void PiocherJetons(Couleur c1, Couleur c2, Couleur c3, Joueur& joueur, Controleur* controleur);
    Carte& AcheterCarte(Carte* carte, Joueur& joueur, Controleur* controleur);
    Carte& ReserverCarte(Carte* carte, Joueur& joueur, Controleur* controleur);
    void FinDePartie();
    void VisiteNoble(Joueur *joueur);
    void setChoix(int choice);
    void Tour(Partie* p);;
    void AfficherCarte(int i, int j, Partie* p);
    void SetPartie(size_t n, QString j[4], Partie* p);
    static Partie* getInstance() {
        if (h.Instance == nullptr) {
            h.Instance = new Partie;
        } return h.Instance;};

private:
    struct handler{
        Partie* Instance;
        handler(): Instance(nullptr){}
        ~handler(){delete Instance;}
    };
    static handler h;
    friend class Controleur;
    Partie();
    Controleur* cont;
    size_t Nbjoueur;
    Joueur* ListeJoueur[4];
    int choice;

};

#endif // PARTIE_H
