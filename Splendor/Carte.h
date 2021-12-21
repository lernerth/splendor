#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Carte {
public:
    //constructeur
    Carte();

    int getNiveau();
    int getPrestige();
    int getRemise();
    int getPrix(int index);
    int getIdCarte();

    void setNiveau(int niv);
    void setPrestige(int prestige);
    void setRemise(int index);
    void setPrix (int tab_prix[5]);
    void setIdCarte(int id_Carte);

private:
    int id_Carte;
    int niveau;
    int prestige;
    int remise[5]; //Bonus color
    int prix[5];
};

#endif // CARTE_H
