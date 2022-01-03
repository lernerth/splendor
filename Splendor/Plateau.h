#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>
#include <vector>
#include "Carte.h"
#include "Noble.h"
/*
#include "Pioche_carte.h"
#include "pioche_noble.h"*/
#include <time.h>
#include <stdlib.h>
/*
#include "Partie.h"
#include "Exception.h"*/

using namespace std;

class Plateau {
    /*!
     *  \class Plateau
       * \brief classe representant le plateau, soit les cartes faces visibles
       */
public:
    //Constructeur
    /*!
        *\fn Plateau()
        *\brief contructeur du plateau
        */
    Plateau();
    //Plateau& operator=(const Plateau& p);

    /*!
        *\fnNoble* getNoble(int indice_noble)
        *\brief pointe sur un noble afficher sur le plateau
        *\param indice_noble : un nombre int correspondant à la place de la carte sur le plateau
        *\return la carte noble pointée
        */
    Noble* getNoble(int indice_noble) {return noble[indice_noble];};
    /*!
        *\fn Carte* getCarteGrille(int niveau, int emplacement)
        *\brief pointe sur une carte affichée sur le plateau
        *\param niveau : un nombre 'int' correspondant au niveau de la carte (1, 2, 3)
        *\param emplacement : un nombre 'int' correspondant à la place de la carte sur la grille (0, 1, 2, 3)
        *\return
        */
    Carte* getCarteGrille(int niveau, int emplacement) {return grille[niveau][emplacement];};
    /*!
        *\fn void modifCarteGrille(int niveau, int emplacement, Carte* c)
        *\brief change les cartes sur le plateau
        *\param niveau : un nombre 'int' correspondant au niveau de la carte (1, 2, 3)
        *\param emplacement : un nombre 'int' correspondant à la place de la carte sur la grille (0, 1, 2, 3)
        *\param c : la carte a mettre sur la grille
        */
    void modifCarteGrille(int niveau, int emplacement, Carte* c);
    /*!
        *\fn void modifierNoble(int indice, Noble* n)
        *\brief change la carte noble sur le plateau
        *\param indice : le nombre 'int' correspondant à l'emplacement de la carte sur le plateau
        *\param n : la carte noble qui doit être ajoutée sur le plateau
        */
    void modifierNoble(int indice, Noble* n);


private:
    friend class controleur;
    Carte* grille[3][4];/*!< la grille des cartes affichées sur le plateau, par niveau*/
    Noble* noble[5];/*!< l'ensemble des nobles face visible sur le plateau*/
};
#endif // PLATEAU_H
