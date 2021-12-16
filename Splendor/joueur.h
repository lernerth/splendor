#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include "Carte.h"
#include "Noble.h"
#include <vector>

class Joueur{
public:
    //constructeur
    Joueur();

    //getters
    int totalPrestige();
    int getJetons (int index);
    int getBonus (int index);
    Carte* getReserve(int index);

    //setters
    void setJetons (int nb, string couleur);
    void setPierres(int pierres[6]);
    void setReserveCartes(Carte* reserve_cartes[3]);
    void setPrestige(int nb_points);
    void removeReserve(int index);

private:
    int id_joueur;
    Carte* cartes_reservees[3];
	const Carte** cartes_achetees = nullptr;
    Noble* noble;
    int jetons [6];
    int prestige;
    int bonus[5];
};

#endif // JOUEUR_H_INCLUDED
