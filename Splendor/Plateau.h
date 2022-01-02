#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>
#include <vector>
#include "Carte.h"
#include "Noble.h"
#include "Pioche_carte.h"
#include "pioche_noble.h"
#include <time.h>
#include <stdlib.h>
#include "Partie.h"
#include "Exception.h"

using namespace std;

class Plateau {
public:
    //Constructeur
    Plateau();

    Noble* getNoble(int indice_noble) {return noble[indice_noble];};
    Carte* getGrille() {return grille[3][4];}
    Carte* getCarteGrille(int niveau, int emplacement) {return grille[niveau][emplacement];};
    void modifCarteGrille(int niveau, int emplacement, const Carte* c);


private:

    Carte* grille[3][4];
    Noble* noble[5];
};
#endif // PLATEAU_H
