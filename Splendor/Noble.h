#ifndef NOBLE_H
#define NOBLE_H

#include <iostream>
#include <string>
#include <vector>
#include <QMap>
#include <QImage>
#include "Exception.h"
#include "global.h"

/*!
 *  \class Noble
   * \brief classe representant les cartes de noble
   */
class Noble {
public:
    /*!
        *\fn int getPrestige()
        *\brief recupère le nombre de points de prestige fourni par la carte
        *\return un nombre 'int' correspondant aux points de prestige
        */
    int getPrestige() const { return nbPoints_Prestige; }
    /*!
        *\fn int getPrix(Couleur c)
        *\brief recupère le nombre de bonus nécessaires par couleur de jetons pour récupérer la carte noble
        *\param c : la couleur du bonus
        *\return un nombre 'int' correpsondant au nombre de bonus nécessaire de la couleur donnée
        */
    int getPrix(Couleur c) const { return prixNoble[c]; }
    /*!
        *\fn QImage getImage()
        *\brief recupère l'image correspondant à la carte noble
        *\return l'image
        */
    QString getImage() const { return image; }


private:
    friend class Pioche_Noble;
    int id;/*!< ID de la carte noble, unique pour chacune*/
    int nbPoints_Prestige;/*!< nombre de points de prestige reçu par le joueur lorsqu'il récupère la carte*/
    QMap<Couleur,int> prixNoble;/*!< prix de la carte par couleur de jeton*/
    QString image;/*!< chemin de l'image correspondant à la carte noble*/
    Noble(int i, QMap<Couleur,int> nbcn, QString image) : nbPoints_Prestige(i), prixNoble(nbcn), image(image){}


};

#endif
