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

/*!
 *  \class Carte
   * \brief classe representant les cartes
   */

class Carte {
public:
    //constructeur

    /*!
        *\fn int getNiveau()
        *\brief recupère le niveau de la carte
        *\return nombre 'int' : 1, 2 ou 3
        */
        /*!
        *\fn int getPrestige()
        *\brief recupère le nombre de points de prestige obtenu par le joueur après achat de la carte
        *\return nombre 'int' correspondant au nombre de points
        */
        /*!
        *\fn Couleur getRemise()
        *\brief récupère la couleur du jeton bonus obtenu pour l'achat de la carte
        *\return couleur (blanc, bleu, noir, rouge ou vert)
        */
        /*!
        *\fn int getPrix(Couleur c)
        *\brief récupère le nombre de jeton de chaque couleur nécessaire pour acheter la carte
        *\param c la couleur dont on veut indiquer le coût (blanc, bleu, noir, rouge ou vert)
        *\return nombre 'int' le nombre de jeton de la couleur indiquée nécessaire pour acheter la carte
        */
        /*!
        *\fn int getIdCarte()
        *\brief recupère l'id de la carte
        *\return nombre 'int' correspondand à l'ID de la carte (unique) pour chaque carte
        */
        /*!
        *\fn int getImage()
        *\brief renvoie le chemin de l'image
        *\return image 'QString' chemin du visuel de la carte
        */
    int getNiveau();
    int getPrestige();
    Couleur getRemise();
    int getPrix(Couleur c);
    int getIdCarte();
    QString getImage(){return image;};

private:
    friend class Pioche_carte;
    int id_Carte; /*!< ID de la carte, unique pour chacune*/
    int niveau; /*!< Niveau de la carte (1, 2 ou 3)*/
    int prestige; /*!< Nombre de points de prestige de la carte*/
    Couleur remise; /*!< Couleur du jeton obtenu en bonus pour achat de la carte*/
    QMap<Couleur, int> prix; /*!< Coût de la carte pour chaque type de jeton*/
    QString image; /*!< Image liée à l'ID de la carte*/
    Carte(int id, int n, int p, Couleur r, QMap<Couleur, int> pr, QString i) : id_Carte(id), niveau(n), prestige(p), remise(r), prix(pr), image(i) {};
};

#endif // CARTE_H
