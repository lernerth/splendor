#include "controleur.h"




//~Controleur() { delete pn; }

//getters
Carte** Controleur::getPioche(int niveau) {
    switch (niveau){
        case 1 :
            return pioches->getLvl1();
            break;
        case 2 :
            return pioches->getLvl2();
            break;
        case 3 :
            return pioches->getLvl3();
            break;
        default:
            return nullptr;
        }
}

//Methodes
void Controleur::initialiser_Plateau(int nb_joueurs){
    Plateau plateau = Plateau();
    //Carte à acheter
    for (int j = 0; j < 4; j++){
        for(int i = 1; i < 4; i++){
            plateau.modifCarteGrille(i, j, pioches->piocher(i));
        }
    }
    //Cartes nobles
    for(int i = 0; i < nb_joueurs+1 ; i++){
        plateau.modifierNoble(i, noble->piocherNoble());
    }
}

//remplacer une carte
void Controleur::retirer_carte (Carte* carte){
    Carte& c = plateau.getIdCarteGrille(niveau,indice);//on r?cup?re une ref vers la carte ? retirer
    switch (niveau){
        case 1 : plateau.getIdCarteGrille(niveau,indice)=p1.piocher(); //on la remplace vers la carte de la pioche
        case 2 : plateau.getIdCarteGrille(niveau, indice)= p2.piocher();//?a marche avec un get ?
        case 3 : plateau.getIdCarteGrille(niveau, indice)= p3.piocher();
    }
}

//retirer une carte noble
void Controleur::retirer_Noble(Noble* noble){
    int i = noble->getId;
    Noble& n = plateau.getNoble(pos);

    plateau.getNoble(pos) = nullptr;
}

//retirer des jetons de la pioche centrale
void Controleur::retirer_Jetons(Couleur c){
    pj[c]--;
}

//Remettre les jetons dans la pioche centrale
void Controleur::rendre_Jetons(Couleur c){
    pj[c]++;
}

