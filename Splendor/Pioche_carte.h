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
    int getNiv();

    //Setters
    void setNbCarte(int nb_carte);
    void setNiv(int niv);

private:
    int nb_carte_initiale;
    int niveau;
};

#endif
