#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include "Carte.h"
#include "Noble.h"
#include <vector>
#include "Exception.h"

class Joueur{
public: 
    int getPrestige() {return this->prestige;}
    const QString getNom() const {return this->nom;}
    QMap<Couleur, int> getJetons() const {return this->jetons;}
    QMap<Couleur, int> getBonus () const {return this->bonus;}
    Carte** getCartesAchetees() const { return this->cartes_achetees; }
    Carte** getCartesReservees() const { return this->cartes_reservees; }
    Noble** getNobles() const { return this->noble; }

private:
    //friend class Partie; //ou controlleur a def
    const QString nom;
    Carte** cartes_reservees = nullptr;
    Carte** cartes_achetees = nullptr;
    Noble** noble = nullptr;
    QMap<Couleur, int> jetons;
    int prestige;
    QMap<Couleur, int> bonus;
    Joueur(QString n) : nom(n), prestige(0){}
};

#endif // JOUEUR_H_INCLUDED
