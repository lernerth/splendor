#ifndef NOBLE_H
#define NOBLE_H

#include <iostream>
#include <string>
#include <vector>
#include <QMap>
#include <QImage>
#include "Exception.h"
#include "global.h"

class Noble {
public:
    int getId() const{return id; }
    int getPrestige() const { return nbPoints_Prestige; }
    int getPrix(Couleur c) const { return prixNoble[c]; }
    QString getImage() const { return image; }


private:
    friend class Pioche_Noble;
    int id;
    int nbPoints_Prestige;
    QMap<Couleur,int> prixNoble;
    QString image;
    Noble(int i, QMap<Couleur,int> nbcn, QString image) : nbPoints_Prestige(i), prixNoble(nbcn), image(image){}


};

#endif
