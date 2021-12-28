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
    int getPrestige() const { return nbPoints_Prestige; }
    QMap<Couleur,int> getNbCartesNecessaires() const { return nbCartesNecessaires; }
    QImage getImage() const { return image; }
    PositionNoble getPositionNoble() const { return positionNoble; }
    void changerPosition(PositionNoble pn) {positionNoble=pn;}

private:
    friend class Pioche_Noble;
    int nbPoints_Prestige;
    QMap<Couleur,int> nbCartesNecessaires;
    QImage image;
    PositionNoble positionNoble;
    Noble(int i, QMap<Couleur,int> nbcn, QImage image, PositionNoble pn) : nbPoints_Prestige(i), nbCartesNecessaires(nbcn), image(image), positionNoble(pn) {}


};

#endif
