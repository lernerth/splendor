#ifndef PIOCHE_NOBLE_H
#define PIOCHE_NOBLE_H
#include "Noble.h"
#include "Exception.h"

class Pioche_Noble{
    /*!
     *  \class Pioche_Noble
       * \brief classe representant la pioche des nobles
       */
public:
    /*!
        *\fn Pioche_Noble()
        *\brief contructeur de la pioche noble
        */
    Pioche_Noble();
    /*!
        *\fn int getNbNobles()
        *\brief recupère le nombre de noble
        *\return un nombre 'int'
        */
    int getNbNobles() {return nbNoble;}
    /*!
        *\fn Noble** getTous()
        *\brief pointe sur l'ensemble des cartes de la pioche
        *\return un pointeur sur les cartes noble
        */
    Noble** getTous() {return tous;}
    /*!
        *\fn Noble* getNoble(int i)
        *\brief recupère un certain nombre de cartes nobles
        *\param i : le nombre 'int' de cartes à récupérer
        *\return l'ensemble des cartes nobles récupérées
        */
    Noble* getNoble(int i) {return tous[i];}
    /*!
        *\fn Noble* piocherNoble(Pioche_Noble* n)
        *\brief récupère une carte noble dans la pioche
        *\param n : la pioche dans laquelle on doit récupérer la carte
        */
    Noble* piocherNoble(Pioche_Noble* n);
private:
    friend class Controleur;
    Pioche_Noble(Pioche_Noble& j) = delete;
    Pioche_Noble& operator=(Pioche_Noble& j) = delete;
    Noble** tous;/*!< l'ensemble des nobles*/
    int nbNoble;/*!< le nombre de cartes noble*/

};

#endif // PIOCHE_NOBLE_H
