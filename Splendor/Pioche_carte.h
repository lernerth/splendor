#ifndef PIOCHE_CARTE_H
#define PIOCHE_CARTE_H

#include <iostream>
#include <string>
#include <vector>
#include "Carte.h"
#include "Exception.h"

class Pioche_carte {
public:
    size_t getNbCartes(int niveau);
    Carte* piocher(int niveau);
    Carte** getToutes() { return toutes; };
    Carte** getLvl1() { return lvl1; };
    Carte** getLvl2() { return lvl2; };
    Carte** getLvl3() { return lvl3; };
    Carte& getCarte(size_t i) const { if (i >= 91) throw Exception("Out of range");  return *toutes[i]; }

private:
    friend class Controleur;
    Pioche_carte();
    //Pioche_carte(const Pioche_carte& j);
    Pioche_carte& operator=(Pioche_carte& j) {return j;};

    Carte** toutes;
    Carte** lvl1;
    Carte** lvl2;
    Carte** lvl3;
    size_t nb_cartes;
    size_t nb_carteslvl1;
    size_t nb_carteslvl2;
    size_t nb_carteslvl3;
};

#endif
