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
    int getPrestige() {return prestige;}
    const QString getNom() const {return nom;}
    int getJetons(Couleur c);
    int getBonus (Couleur couleur);
    Carte** getCartesAchetees() const { return cartes_achetees; }
    Carte** getCartesReservees() const { return cartes_reservees; }
    Noble** getNobles() const { return noble; }
    int getNbJetonsTot();

    void ajouter_jeton(Couleur c) {jetons[c]++;}
    void retirer_jeton(Couleur c) {jetons[c]--;}

    void ajouter_carte_reserve(Carte* carte);
    void retirer_carte_reserve(Carte* carte);
    void acheter_carte(Carte* carte);
    void recupérer_noble(Carte* carte);

private:
    friend class Partie; //ou controleur a def
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
