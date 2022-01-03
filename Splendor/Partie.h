#ifndef PARTIE_H
#define PARTIE_H

#include <iostream>
#include <string>
#include <vector>
#include <QMap>
#include "Carte.h"
#include "pioche_noble.h"
#include "Noble.h"
#include "Pioche_carte.h"
#include "controleur.h"
#include "global.h"
#include "Plateau.h"
#include "Exception.h"
#include "joueur.h"
#include "gamewindow.h"

using namespace std;
/*!
 *  \class Partie
   * \brief classe representant la partie, et les tours de jeu des joueurs
   */
class Partie {
public:
    /*!
        *\fn size_t getNbJoueurs()
        *\brief récupère le nombre de joueurs pour la partie
        *\return un nombre 'size_t'
        */
    size_t getNbJoueurs() {return Nbjoueur;};
    /*!
        *\fn Joueur* getJoueur(size_t numJ)
        *\brief pointe sur les joueurs de la partie
        *\param numJ : un nombre size_t correspondant au nombre de joueurs
        *\return les joueurs
        */
    Joueur* getJoueur(size_t numJ);
    /*!
        *\fn Controleur* getControleur()
        *\brief pointe sur le controleur
        *\return le controleur qui met à jour le plateau
        */
    Controleur* getControleur() {return cont;}
    /*!
        *\fn void PiocherJetons(Couleur c1, Couleur c2, Couleur c3, Joueur& joueur, Controleur* controleur)
        *\brief enlève les jetons de la banque et les attributs au joueur
        *\param c1, c2, c3 : les couleurs des jetons à piocher
        *\param joueur : le joueur qui doit récupérer les jetons
        *\param controleur : le controleur qui retire les jetons de la banque
        */
    void PiocherJetons(Couleur c1, Couleur c2, Couleur c3, Joueur& joueur, Controleur* controleur);
    /*!
        *\fn Carte& AcheterCarte(Carte* carte, Joueur& joueur, Controleur* controleur)
        *\brief enlève la carte achetée du plateau et l'attribue au joueur
        *\param carte : la carte achetée,
        *\param joueur : le joueur qui a acheté la carte,
        *\param controleur : le controleur qui met à jour le plateau
        *\return l'adresse de la carte
        */
    Carte& AcheterCarte(Carte* carte, Joueur& joueur, Controleur* controleur);
    /*!
        *\fn void VisiteNoble(Joueur *joueur)
        *\brief verifie si le joeur est éligible à la visite d'un noble
        *\param joueur : pointeur sur le joueur
        */
    void VisiteNoble(Joueur *joueur);
    /*!
        *\fn Carte& ReserverCarte(Carte* carte, Joueur& joueur, Controleur* controleur)
        *\brief enlève la carte reservée du plateau et l'attribue au joueur
        *\param carte : la carte reservée
        *\param joueur : le joueur qui a reservé la carte
        *\param controleur : le controleur qui met à jour le plateau
        *\return l'adresse de la carte
        */
    Carte& ReserverCarte(Carte* carte, Joueur& joueur, Controleur* controleur);
    /*!
        *\fn void setChoix(int choice)
        *\brief informe du choix du joueur (entre récupérer des jetons, acheter ou reserver une carte)
        *\param choix : un nombre 'int' correspondant au choix
        */
    void setChoix(int choice);
    /*!
        *\fn void SetPartie(size_t n, QString j[4], Partie* p)
        *\brief lance la la partie
        *\param n : nombre 'size_t' de joueurs
        *\param j[4] : la liste des noms des joueurs
        *\param p : la partie en cours
        */
    void SetPartie(size_t n, QString j[4], Partie* p);
    /*!
        *\fn static Partie* getInstance()
        *\brief Singleton de la partie
        *\return retour un pointeur sur l'instance partie
        */
    static Partie* getInstance() {
        if (h.Instance == nullptr) {
            h.Instance = new Partie;
        } return h.Instance;};

private:
    struct handler{
        Partie* Instance;
        handler(): Instance(nullptr){}
        ~handler(){delete Instance;}
    };
    static handler h;
    friend class Controleur;
    Partie();
    Controleur* cont; /*!< le controleur, qui gère la mise à jour du plateau*/
    size_t Nbjoueur;/*!< le nombre de joueur dans la partie*/
    Joueur* ListeJoueur[4];/*!< la liste des joueurs*/
    int choice;/*!< le choix que fait le joueur dont c'est le tour*/

};

#endif // PARTIE_H
