#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED
#include "Exception.h"
#include "Carte.h"
#include "Noble.h"
#include "Plateau.h"

 class Controleur {
	public:
    //controleur-destructeur
        Controleur(Pioche_carte c1, Pioche_carte c2, Pioche_carte c3, Nobles* n[10]): p1(c1),p2(c2),p3(c3),plateau(new Plateau){
        //initialisation de la pile de jetons
        int jetons[6];
        for (int i = 0; i <5; ++i) {
            jetons[i]= 7;
        }
        jetons[5]=5;
		}

        ~Controleur() { delete pn; }
    //getters
		const Plateau& getPlateau() const { return plateau; }
        const Pioche_jetons& getJetons() const { return pj; }
        const Pioche_carte& getPioche(int niveau) const;
        const Nobles* getNobles() const {return pn}
    //Singleton
		Controleur(const Controleur& c) = delete;
		Controleur& operator=(const Controleur& c) = delete;

    //Methodes
    void initialiser_Plateau(int nb_joueurs);//initialiser la grille et la rangée
    //remplacer une carte développement du tableau
    Carte& retirer_carte(Carte* carte);
    //retirer une carte noble
    Noble& retirer_Noble(int pos);
    //retirer des jetons de la pioche centrale
    void retirer_Jetons(Couleur c);
    //rendre des jetons à la pioche centrale
    void rendre_Jetons(Couleur c);

	private:
        friend class Partie;
		Pioche_carte p1;
		Pioche_carte p2;
		Pioche_carte p3;
        QMap<QString, int> pj;
		Plateau plateau;
		Nobles* pn[10];
	};

#endif
