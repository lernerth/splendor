#include "controleur.h"

/*
Controleur::Controleur(){
    Carte** p1 = nullptr;
    Carte** p2 = nullptr;
    Carte** p3 = nullptr;
    //static QMap<Couleur, int> pj{{"blanc", 7}, {"bleu", 7}, {"noir", 7}, {"rouge", 7}, {"vert", 7}, {"jaune", 5},};
    //Plateau& plateau = Plateau.Plateau();
    const Noble* pn[10];
    for(int i = 0; i <10; i++){
        pn[i] = nullptr;
    }
}*/

//~Controleur() { delete pn; }

    //getters
        const Pioche_carte& Controleur::getPioche(int niveau) const {
            switch (niveau){
                case 1 :
                    return p1;
                    break;
                case 2 :
                    return p2;
                    break;
                case 3 :
                    return p3;
                    break;
                }
        }

//Methodes
void Controleur::initialiser_Plateau(int nb_joueurs){
    Plateau plateau = Plateau();
    //Carte à acheter
    for (int j = 0; j < 4; j++){
        for(int i = 1; i < 4; i++){
            plateau.modifCarteGrille(i, j, p1.piocher(i));
        }
    }
    //Cartes nobles
    for(int i = 0; i < nb_joueurs+1 ; i++){
        plateau.setNoble(pn);
    }
}

//remplacer une carte
void Controleur::retirer_carte (Carte* carte){
    Carte& c = Plateau.getIdCarteGrille(niveau,indice);//on r?cup?re une ref vers la carte ? retirer
    switch (niveau){
        case 1 : Plateau.getIdCarteGrille(niveau,indice)=p1.piocher(); //on la remplace vers la carte de la pioche
        case 2 : Plateau.getIdCarteGrille(niveau, indice)= p2.piocher();//?a marche avec un get ?
        case 3 : Plateau.getIdCarteGrille(niveau, indice)= p3.piocher();
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
