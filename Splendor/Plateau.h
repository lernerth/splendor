#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>
#include <vector>
#include <Carte.h>
#include <Noble.h>
#include <Pioche_carte.h>
#include <time.h>
#include <stdlib.h>
#include <Partie.h>


using namespace std;
class Plateau {
//Suggestion : plutôt que des id entiers, fonctionner avec des pointeurs (à initialiser dans le cpp avec nullptr)
public:
    //Constructeur
    Plateau();

    int getNoble(int index_noble);
    //Noble* getNoble(int indice_noble);
    int getIdCarteGrille(int niveau, int indice);
    //Carte* getCarteGrille(int niveau, int indice);

    void setNoble(int tab_noble[5]);
    //void setNoble (Noble* tab_noble[5]):
    void setGrille(int tab_grille[3][4]);
    //void setGrille(Carte* tab_grille[3][4])
    //void remplacerCarte(int niveau, int indice);->Controleur

private:
    int grille[3][4];
    int noble[5];
    
};

#endif // PLATEAU_H
