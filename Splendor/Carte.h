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
    string getBonusColor();
    int getPrice(int index);
    int getIdCarte();

    void setRow(int row);
    void setPrestige(int prestige);
    void setDiscount(string discount);
    void setPrice (int tab_price[5]);
    void setIdCarte(int id_Carte);

private:
    int id_Carte;
    int row;
    int prestige;
    string discount; //Bonus color
    int price[5];
};

#endif // CARTE_H
