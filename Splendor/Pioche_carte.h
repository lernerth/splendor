#ifndef PIOCHE_CARTE_H
#define PIOCHE_CARTE_H

#include <iostream>
#include <string>
#include <vector>
#include <Carte.h>


class Pioche_carte {
public:
    //constructeur-destructeur
    Pioche_carte();
    ~Pioche_carte()	{delete[] cartes;}//edit

    //Setters
    void setNiveau(int niv);
    void setNbCarte();

    //récupérateurs
    int getNbCarte()const {return nb;}//edit
    int getNiveau() const {return niveau;}//edit

    //méthodes
    size_t getNbCartes() {return nb_cartes;}//edit
    bool estVide() const {return nb_cartes == 0;}//edit
    const Carte& piocher();//edit

private:
    int nb_cartes;
    int niveau;
    const Carte** cartes = nullptr;//edit
};

#endif
