#ifndef NOBLE_H
#define NOBLE_H

#include <iostream>
#include <string>
#include <vector>

class Noble {
public:
    //constructeur
    Noble();

    //récupérateur
    int getIdNoble();
    int getPrix(int index);
    int getPtPrestige();

    //setters
    void setIdNoble(int id_Noble);
    void setPrix(int prix[5]);
    void setPtPrestige(int point_prestige);

private:
    int id_noble;
    int prix[5];
    int point_prestige;

};

#endif
