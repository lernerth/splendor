#ifndef PIOCHE_CARTE_H
#define PIOCHE_CARTE_H

#include <iostream>
#include <string>
#include <vector>
#include <Carte.h>


class Pioche_carte {
public:
    //constructeur
    Pioche_carte();

    //récupérateur
    int getNbCarte();
    int getNiveau();

    //Setters
    void setNbCarte(int nbcarte);
    void setNiveau(int niv);

private:
    int nb_carte;
    int niveau;
};

#endif
