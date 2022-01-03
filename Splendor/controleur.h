#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED
#include "Exception.h"
#include "Carte.h"
#include "Noble.h"
#include "Plateau.h"
#include "Carte.h"
#include "Noble.h"
#include "pioche_noble.h"
#include "Pioche_carte.h"

/*!
 *  \class Controleur
   * \brief classe representant le controleur, chargé de mettre à jour les cartes sur le plateau ainsi que les piles de jetons de la banque
   */

 class Controleur{
	public:
        //constructeur-destructeur

     /*!
          *\fn Controleur()
          *\brief Construit et initialise le controleur
          */
        Controleur() {
            pioches = new Pioche_carte();
            plateau = new Plateau();
            noble = new Pioche_Noble();

        };

        /*!
                *\fn ~Controleur()
                *\brief Détruit le controleur
                */
        ~Controleur(); //Pourquoi delete que la pioche noble ??

        //getters
        /*!
                *\fn Carte** getPioche(int niveau)
                *\brief permet d'accéder à la pioche pour un niveau donné
                *\param niveau : un nombre 'int' (1, 2 ou 3) qui indique le niveau de la pioche à laquelle on souhaite accéder
                *\return un pointeur sur la première carte de la pioche
                */
        Carte** getPioche(int niveau) ;
        /*!
                *\fn int getCouleur(Couleur c)
                *\brief récupère le nombre de jeton par couleur dans la banque de jetons
                *\param c : couleur souhaitée
                *\return un nombre 'int' correspondant au nombre de jetons
                */
        int getCouleur(Couleur c) {return pj[c];};
        /*!
                *\fn Plateau* getPlateau()
                *\brief récupère l'instance de plateau du controleur
                *\return un pointeur sur une instance de plateau
                */
        Plateau* getPlateau() {return plateau;};

        //Singleton
        Controleur(const Controleur& c) = delete;
        Controleur& operator=(const Controleur& c) = delete;

        //Methodes
        /*!
                *\fn void initialiser_Plateau(size_t nb_joueurs, Controleur* contr)
                *\brief initialise le plateau (les cartes et les nobles faces visibles)
                *\param nb_joueurs : un nombre 'size_t' indiquant le nombre de joueur participants à cette partie, ce qui influe le nombre de nobles sur le plateau
                *\param contr : un pointeur sur le controleur, chargé d'installer les cartes sur le plateau à partir des pioches
                */
        void initialiser_Plateau(size_t nb_joueurs, Controleur* contr);//initialiser la grille et la rangée
        /*!
                *\fn void remplacer_carte(int niveau, int indice, Controleur* contr)
                *\brief un fois une carte achetée ou reservée, remplace sur le plateau l'ancienne carte par une de la pioche correspondante
                *\param niveau : un nombre 'int' (1, 2 ou 3) indiquant le niveau de la carte que l'on souhaite remplacer
                *\param indice : un nombre 'int' (0, 1, 2 ou 3) indiquant la place sur la grille où la nouvelle carte doit être installée
                *\param contr : un pointeur sur le controleur, chargé d'installer les cartes sur le plateau à partir des pioches
                */
        void remplacer_carte(int niveau, int indice, Controleur* contr);     //remplacer une carte développement du tableau
        /*!
                *\fn void retirer_Noble(int indice)
                *\brief une fois attribuée à un joueur, enlève la carte noble du plateau (et ne la remplace pas, l'emplacement est ensuite vide)
                *\param indice : un nombre 'int' (0, 1, 2, 3 ou 4) indiquant l'emplacement de la carte sur le plateau
                */
        void retirer_Noble(int indice);     //retirer une carte noble
        /*!
                *\fn void retirer_Jetons(Couleur c)
                *\brief enlève un jeton de la couleur indiquée dans la banque de jetons
                *\param c : la couleur du jeton qui doit être retiré (blanc, bleu, noir, rouge ou vert)
                */
        void retirer_Jetons(Couleur c);         //retirer des jetons de la pioche centrale
        /*!
                *\fn rendre_Jetons(Couleur c)
                *\brief ajoute un jeton de la couleur indiquée dans la banque de jetons
                *\param c : la couleur du jeton qui doit être ajouté (blanc, bleu, noir, rouge ou vert)
                */
        void rendre_Jetons(Couleur c);          //rendre des jetons à la pioche centrale

	private:
        friend class Partie;
        Pioche_carte *pioches; /*!< pointeur sur la première carte de la pioche*/
        QMap<Couleur, int> pj; /*!< le nombre de jetons restant par couleur dans la banque*/
        Plateau *plateau; /*!< pointeur sur le plateau*/
        Pioche_Noble *noble; /*!< pointeur sur la première carte de la pioche des cartes nobles*/
	};

#endif
