#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>
#include <vector>
#include <QMap>
#include <QPixmap>
#include "global.h"
#include "Exception.h"

using namespace std;

class Carte {
public:
    //constructeur
    int getNiveau();
    int getPrestige();
    Couleur getRemise();
    int getPrix(Couleur c);
    int getIdCarte();
    QString getImage(){return image;};

private:
    friend class Pioche_carte;
    int id_Carte;
    int niveau;
    int prestige; 
    Couleur remise; //Bonus color
    QMap<Couleur, int> prix;
    QString image;
    Carte(int id, int n, int p, Couleur r, QMap<Couleur, int> pr, QString i) : id_Carte(id), niveau(n), prestige(p), remise(r), prix(pr), image(i) {};
};

#endif // CARTE_H
