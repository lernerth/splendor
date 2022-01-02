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
    QMap<Couleur,int> getNbCartesNecessaires() const { return nbCartesNecessaires; }
    QImage getImage() const { return image; }


private:
    friend class Pioche_Noble;
    int id;
    int nbPoints_Prestige;
    QMap<Couleur,int> nbCartesNecessaires;
    QImage image;
    Noble(int id, int i, QMap<Couleur,int> nbcn, QImage image) : nbPoints_Prestige(i), nbCartesNecessaires(nbcn), image(image){}


};

#endif
