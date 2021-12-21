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
    int getJetons (int indice);
    int getBonus (int indice);
    int getReserve(int indice);

    //setters
    void setJetons (int add_jetons[6]);
    void setBonus(int indice);
    void setReserveCartes(int reserve_carte);
    void setPrestige(int nb_points);
    void removeReserve(int index);
    void setId(int id);

private:
    int id_joueur;
    int cartes_reservees[3];
    const Carte** cartes_achetees;
    Noble* noble[5];
    //ou const Noble** noble = nullptr;
    int jetons [6];
    int prestige;
    int bonus[5];
};

#endif // JOUEUR_H_INCLUDED
