#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Plateau {
public:
    //Constructeur
    Plateau();

    int getNoble(int index_noble);
    int getIdCarteGrille(int row, int index);

    void setNoble(int tab_noble[5]);
    void setGrille(int tab_grille[3][4]);

private:
    int grille[3][4];
    int noble[5];

};

#endif // PLATEAU_H
