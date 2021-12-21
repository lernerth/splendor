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

    int getRow();
    int getPrestige();
    int getDiscount();
    int getPrix(int index);
    int getIdCarte();

    void setRow(int row);
    void setPrestige(int prestige);
    void setDiscount(int index);
    void setPrix (int tab_price[5]);
    void setIdCarte(int id_Carte);

private:
    int id_Carte;
    int row;
    int prestige;
    int discount[5]; //Bonus color
    int prix[5];
};

#endif // CARTE_H
