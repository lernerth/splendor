#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED
#include "Exception.h"
#include "Carte.h"
#include "Noble.h"
#include "Plateau.h"

 class Controleur {
	public:
    //controleur-destructeur
        Controleur(Carte** c1, Carte** c2, Carte** c3, Noble* n[10]): p1(c1),p2(c2),p3(c3), plateau(new Plateau) {
        //initialisation de la pile de jetons
            int jetons[6];
            for (int i = 0; i <5; ++i) {
                jetons[i]= 7;
            }
            jetons[5]=5;
		}

        // ~Controleur() { delete pn; } Pourquoi delete que la pioche noble ??
    //getters
		const Plateau& getPlateau() const { return plateau; }
       // const Pioche_jetons& getJetons() const { return pj; } //Pioche de jetons n'existe pas !
        const Pioche_carte& getPioche(int niveau) const;
        const Noble* getNobles(int i) const {return pn[i];}
    //Singleton
		Controleur(const Controleur& c) = delete;
		Controleur& operator=(const Controleur& c) = delete;

    //Methodes
    void initialiser_Plateau(int nb_joueurs);//initialiser la grille et la rangée
    //remplacer une carte développement du tableau
    Carte& retirer_carte(Carte* carte);
    //retirer une carte noble
    Noble& retirer_Noble(Noble* noble);
    //retirer des jetons de la pioche centrale
    void retirer_Jetons(Couleur c);
    //rendre des jetons à la pioche centrale
    void rendre_Jetons(Couleur c);

	private:
        friend class Partie;
        Carte** p1;
        Carte** p2;
        Carte** p3;
        QMap<Couleur, int> pj;
		Plateau plateau;
        const Noble* pn[10];
	};

#endif
