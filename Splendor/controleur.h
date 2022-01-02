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

 class Controleur{
	public:
        //constructeur-destructeur
        Controleur() {
            pioches = nullptr;
            plateau = nullptr;
            noble = nullptr;

        };
        ~Controleur(); //Pourquoi delete que la pioche noble ??

        //getters
        Carte** getPioche(int niveau) ;

        //Singleton
        Controleur(const Controleur& c) = delete;
        Controleur& operator=(const Controleur& c) = delete;

        //Methodes
        void initialiser_Plateau(int nb_joueurs);//initialiser la grille et la rangée
        void remplacer_carte(int niveau, int indice);     //remplacer une carte développement du tableau
        void retirer_Noble(int indice);     //retirer une carte noble
        void retirer_Jetons(Couleur c);         //retirer des jetons de la pioche centrale
        void rendre_Jetons(Couleur c);          //rendre des jetons à la pioche centrale

	private:
        friend class Partie;
        Pioche_carte *pioches;
        QMap<Couleur, int> pj;
        Plateau *plateau;
        Pioche_Noble *noble;
	};

#endif
