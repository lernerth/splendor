#ifndef PIOCHE_CARTE_H
#define PIOCHE_CARTE_H

#include <iostream>
#include <string>
#include <vector>
#include "Carte.h"
#include "Exception.h"

class Pioche_carte {
    /*!
     *  \class Pioche_carte
       * \brief classe representant les 3 pioches, une par niveau de cartes
       */
public:
    /*!
        *\fn size_t getNbCartes(int niveau)
        *\brief recupère le nombre de carte dans la pioche
        *\param niveau : le nombre 'int' (1, 2 ou 3)
        */
    size_t getNbCartes(int niveau);
    /*!
        *\fn Carte* piocher(int niveau, Pioche_carte* p)
        *\brief recupère la première carte de la pioche
        *\param niveau : le nombre 'int' correspondant au niveau de la pioche où l'on doit piocher
        *\param p : la pioche où l'on souhaite piocher
        */
    Carte* piocher(int niveau, Pioche_carte* p);
    /*!
        *\fn Carte** getToutes()
        *\brief recupères toutes les cartes de la pioche
        *\return un pointeur sur les cartes
        */
    Carte** getToutes() { return toutes; };
    /*!
        *\fn Carte** getLvl1()
        *\brief récupère les cartes de niveau 1
        *\return un pointeur sur les cartes de niveau 1
        */
    Carte** getLvl1() { return lvl1; };
    /*!
        *\fn Carte** getLvl2()
        *\brief récupère les cartes de niveau 2
        *\return un pointeur sur les cartes de niveau 2
        */
    Carte** getLvl2() { return lvl2; };
    /*!
        *\fn Carte** getLvl3()
        *\brief récupère les cartes de niveau 3
        *\return un pointeur sur les cartes de niveau 3
        */
    Carte** getLvl3() { return lvl3; };
    /*!
        *\fn Carte& getCarte(size_t i)
        *\brief récupère l'ensemble des cartes des 3 pioches
        *\param i : le nombre 'size_t' de cartes à récupérer
        */
    Carte& getCarte(size_t i) const { if (i >= 91) throw Exception("Out of range");  return *toutes[i]; }

private:
    friend class Controleur;
    Pioche_carte();
    //Pioche_carte(const Pioche_carte& j);
    Pioche_carte& operator=(Pioche_carte& j) {return j;};

    Carte** toutes;/*!< l'ensemble des cartes*/
    Carte** lvl1;/*!< l'ensemble des cartes de niveau 1*/
    Carte** lvl2;/*!< l'ensemble des cartes de niveau 2*/
    Carte** lvl3;/*!< l'ensemble des cartes de niveau 3*/
    size_t nb_cartes;/*!< le nombre de cartes*/
    size_t nb_carteslvl1;/*!< le nombre de cartes de niveau 1*/
    size_t nb_carteslvl2;/*!< le nombre de cartes de niveau 2*/
    size_t nb_carteslvl3;/*!< le nombre de cartes de niveau 3*/
};

#endif
