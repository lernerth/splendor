#include "controleur.h"


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
void Controleur::initialiser_Plateau(size_t nb_joueurs, Controleur* contr){
    //Carte à acheter
    for (int j = 0; j < 4; j++){
        for(int i = 1; i < 4; i++){
            contr->plateau->modifCarteGrille(i-1, j, pioches->piocher(i, contr->pioches));
        }
    }
    //Cartes nobles
    for(size_t i = 0; i < nb_joueurs+1 ; i++){
        contr->plateau->modifierNoble(i, noble->piocherNoble(contr->noble));
    }

    //Jetons
    contr->pj[Couleur::jaune]=5;
    if (nb_joueurs==2){
        contr->pj[Couleur::blanc]=4;
        contr->pj[Couleur::bleu]=4;
        contr->pj[Couleur::noir]=4;
        contr->pj[Couleur::rouge]=4;
        contr->pj[Couleur::vert]=4;
    }
    else if (nb_joueurs==3){
        contr->pj[Couleur::blanc]=5;
        contr->pj[Couleur::bleu]=5;
        contr->pj[Couleur::noir]=5;
        contr->pj[Couleur::rouge]=5;
        contr->pj[Couleur::vert]=5;
    }
    else {
        contr->pj[Couleur::blanc]=7;
        contr->pj[Couleur::bleu]=7;
        contr->pj[Couleur::noir]=7;
        contr->pj[Couleur::rouge]=7;
        contr->pj[Couleur::vert]=7;
    }
}

//remplacer une carte
void Controleur::remplacer_carte (int niveau, int indice, Controleur* contr){
    contr->plateau->modifCarteGrille(niveau-1, indice, pioches->piocher(niveau, contr->pioches));
}

//retirer une carte noble
void Controleur::retirer_Noble(int indice){
    Plateau p = *plateau;
    p.modifierNoble(indice, nullptr);
}

//retirer des jetons de la pioche centrale
void Controleur::retirer_Jetons(Couleur c){
    pj[c]--;
}

//Remettre les jetons dans la pioche centrale
void Controleur::rendre_Jetons(Couleur c){
    pj[c]++;
}

