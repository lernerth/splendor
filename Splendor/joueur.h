#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include "Carte.h"
#include "Noble.h"
#include <vector>
#include "Exception.h"

/*!
 *  \class Joueur
   * \brief classe representant les joueurs
   */
class Joueur{
public: 
    /*!
        *\fn Joueur(int i, QString n);
        *\brief contructeur des éléments joueurs
        *\param i : nombre 'int' correspondant à l'ID du joueur
        *\param n : une chaine de caractère correspondant au nom sous lequel le joueur s'est inscrit
        */
    Joueur(int i, QString n);
    /*!
        *\fn int getPrestige()
        *\brief recupère le nombre de points de prestige d'un joueur donné
        *\return le nombre 'int' de points de prestige du joueur
        */
    int getPrestige() {return prestige;}
    /*!
        *\fn const QString getNom()
        *\brief recupère le nom du joueur
        *\return la chaine de caractère sous lequel le joueur s'est inscrit
        */
    const QString getNom() const {return nom;}
    /*!
        *\fn int getJetons(Couleur c)
        *\brief recupère le nombre de jetons détenus par un joueur pour une couleur donnée
        *\param c : la couleur (blanc, bleu, noir, rouge, vert, jaune) dont un veut savoir le nombre détenu par le joueur
        *\return un nombre 'int' de jetons
        */
    int getJetons(Couleur c);
    /*!
        *\fn int getBonus (Couleur couleur)
        *\brief recupère le nombre de bonus par type de jeton possédé par le joueur
        *\param c : la couleur(blanc, bleu, noir, rouge, vert, jaune) dont un veut savoir le nombre de bonus correspondant
        *\return un nombre 'int' de bonus
        */
    int getBonus (Couleur couleur);
    /*!
        *\fn Carte** getCartesAchetees()
        *\brief pointe sur les cartes achetées par un joueur
        *\return l'ensemble des cartes achetées
        */
    Carte** getCartesAchetees() const { return cartes_achetees; }
    /*!
        *\fn Carte** getCartesReservees()
        *\brief pointe sur les cartes reservées par un joueur
        *\return l'ensemble des cartes reservées
        */
    Carte** getCartesReservees() const { return cartes_reservees; }
    /*!
        *\fn Noble** getNobles()
        *\brief pointe sur les cartes nobles possédées par un joueur
        *\return l'ensemble des nobles possédées
        */
    Noble** getNobles() const { return noble; }
    /*!
        *\fn int getNbJetonsTot()
        *\brief récupère le nombre de jetons total (somme du nombre par couleur) détenus par un joueur
        *\return un nombre 'int' correspondant au nombre de jetons
        */
    int getNbJetonsTot();
    /*!
        *\fn void ajouter_jeton(Couleur c)
        *\brief ajoute un jeton d'une couleur donnée à la reserve d'un joueur
        *\param c : la couleur de la pile où on doit ajouter un jeton
        */
    void ajouter_jeton(Couleur c) {jetons[c]++;}
    /*!
        *\fn void retirer_jeton(Couleur c)
        *\brief retire un jeton d'une couleur donnée à la reserve d'un joueur
        *\param c : la couleur de la pile où on doit retirer un jeton
        */
    void retirer_jeton(Couleur c) {jetons[c]--;}
    /*!
        *\fn void ajouter_carte_reserve(Carte* carte)
        *\brief reserve une carte pour le joueur
        *\param carte : un pointeur sur la carte que l'on souhiate reserver
        */
    void ajouter_carte_reserve(Carte* carte);
    /*!
        *\fn void retirer_carte_reserve(Carte* carte)
        *\brief retire une carte de l'ensemble des cartes reservées du joueur (pou l'acheter)
        *\param carte : un pointeur sur la carte que l'on souhiate reserver
        */
    void retirer_carte_reserve(Carte* carte);
    /*!
        *\fn void acheter_carte(Carte* carte)
        *\brief achète une carte pour le joueur
        *\param carte : un pointeur sur la carte que l'on souhiate reserver
        */
    void acheter_carte(Carte* carte);
    /*!
        *\fn int recuperer_noble(Noble* noble)
        *\brief permet au joueur de recuperer un noble (si bonus suffisant)
        *\param noble : un pointeur sur le noble que l'on récupère
        */
    void recuperer_noble(Noble* noble);

private:
    friend class Partie;
    QString nom;/*!< nom du joueur*/
    int id;/*!< ID du joueur, unique*/
    Carte** cartes_reservees = nullptr;/*!< pointeur sur les cartes réservées par le joueur*/
    Carte** cartes_achetees = nullptr;/*!< pointeur sur les cartes achetées par le joueur*/
    Noble** noble = nullptr;/*!< pointeur sur les nobles possédés par le joueur*/
    QMap<Couleur, int> jetons;/*!< nombre de jetons par couleur possédé par le joueur*/
    int prestige;/*!< nombre de points de prestige du joueur*/
    QMap<Couleur, int> bonus; /*!< nombre de bonus par couleur possédé par le joueur*/
};

#endif // JOUEUR_H_INCLUDED
