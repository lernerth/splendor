#include "controleur.h"

//controleur-destructeur

Controleur(Pioche_carte c1, Pioche_carte c2, Pioche_carte c3, Nobles* n[10]): p1(c1),p2(c2),p3(c3),plateau(new Plateau){
    //initialisation de la pile de jetons
        for (int i = 0; i <5; ++i) {
        jetons[i]= 7;
        }
        jetons[5]=5;
        }

~Controleur() { delete pn; }

    //getters
        const Pioche_carte& Controleur::getPioche(int niveau) const {
            switch (niveau){
                case 1 : return p1;
                break;
                case 2 : return p2;
                break;
                case 3 : return p3;
                break;
                }
        }

    //Methodes
        void Controleur::initialiser_Plateau(int nb_joueurs){

        //initialisation de la grille avec cartes de d?veloppement
            for (int j = 0; j < 4; j++){
            plateau.getIdCarteGrille(1,j) = p1.piocher();
          }

            for (int j = 0; j < 4; j++){
            plateau.getIdCarteGrille(2,j) = p2.piocher();
          }

            for (int j = 0; j < 4; j++){
            plateau.getIdCarteGrille(3,j) = p3.piocher();
          }

          //initialisation de la grille avec cartes nobles
          ?plateau.setNoble(pn); //plateau.h ? adapter
     }
          //remplacer une carte d?veloppement du tableau
           Carte& Controleur::retirer_carte (int niveau, int indice){
               Carte& c = *plateau.getIdCarteGrille(niveau,indice);//on r?cup?re une ref vers la carte ? retirer
               switch (niveau){
               case 1 : plateau.getIdCarteGrille(niveau,indice)=p1.piocher(); //on la remplace vers la carte de la pioche
               case 2 : plateau.getIdCarteGrille(niveau, indice)= p2.piocher();//?a marche avec un get ?
               case 3 : plateau.getIdCarteGrille(niveau, indice)= p3.piocher();
               }
               return c;//on r?cup?re la carte qu'on vient de retirer
        }
          //retirer une carte noble
          Noble& Controleur::retirer_Noble(int pos){
              n=plateau.getNoble(pos);
              plateau.getNoble(pos)=nullptr;
              return n;
          }
          //retirer des jetons de la pioche centrale
          void Controleur::retirer_Jetons(Couleur c){
            pj[c]--;
          }

          //rendre des jetons ? la pioche centrale
          void Controleur::rendre_Jetons(Couleur c){
            pj[c]++;
          }
