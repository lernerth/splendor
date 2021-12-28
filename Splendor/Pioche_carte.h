#ifndef PIOCHE_CARTE_H
#define PIOCHE_CARTE_H

#include <iostream>
#include <string>
#include <vector>
#include "Carte.h"
#include "Exception.h"

class Pioche_carte {
public:
    int getNbCartes() const {return 90;}
    const Carte** getToutes() const { return toutes; };
    const Carte** getLvl1() const { return lvl1; };
    const Carte** getLvl2() const { return lvl2; };
    const Carte** getLvl3() const { return lvl3; };
    const Carte& getCarte(size_t i) const { if (i >= 91) throw Exception("Out of range");  return *toutes[i]; }

private:
    Pioche_carte();
    Pioche_carte(const Pioche_carte& j) = delete;
    Pioche_carte& operator=(const Pioche_carte& j) = delete;

    const Carte** toutes;
    const Carte** lvl1;
    const Carte** lvl2;
    const Carte** lvl3;
};

#endif
