#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED
#include "Exception.h"
#include "Carte.h"
#include "Noble.h"
#include "Plateau.h"
#include "Carte.h"
#include "Noble.h"

 class Controleur{
	public:
        //constructeur-destructeur
        Controleur();
        //~Controleur() { delete pn; } //Pourquoi delete que la pioche noble ??

        //getters
        const Plateau& getPlateau() const { return plateau; }
        const Pioche_carte& getPioche(int niveau) const;
        const Noble* getNobles(int i) const {return pn[i];}

        //Singleton
        Controleur(const Controleur& c) = delete;
        Controleur& operator=(const Controleur& c) = delete;

        //Methodes
        void initialiser_Plateau(int nb_joueurs);//initialiser la grille et la rangée
        void retirer_carte(Carte* carte);     //remplacer une carte développement du tableau
        void retirer_Noble(Noble* noble);     //retirer une carte noble
        void retirer_Jetons(Couleur c);         //retirer des jetons de la pioche centrale
        void rendre_Jetons(Couleur c);          //rendre des jetons à la pioche centrale

	private:
        friend class Partie;
        Pioche_carte& p1;
        Pioche_carte& p2;
        Pioche_carte& p3;
        QMap<Couleur, int> pj;
        Plateau& plateau;
        const Noble* pn[10];
	};

#endif
