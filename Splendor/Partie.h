#ifndef PARTIE_H
#define PARTIE_H

#include <iostream>
#include <string>
#include <vector>
#include "Exception.h"

using namespace std;
class Partie {
public:
    //Constructeur
    Partie();

    int getNombreJoueur();

    void setNombreJoueur(int nb_joueur);

private:
    int Nombre_Joueur;

};

#endif // PARTIE_H
