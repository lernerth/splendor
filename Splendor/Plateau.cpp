#include "Plateau.h"


Plateau::Plateau(){
    for (int i = 0; i < 5; i++){
        noble[i] = 0;
    }

    for (int j = 0; j < 3; j++){
        for (int k = 0; k < 4; k++){
            grille[j][k] = 0;
        }
    }
}

int Plateau::getNoble(int index_noble){
    return this->noble[index_noble];
}

int Plateau::getIdCarteGrille(int niveau, int indice){
    return this->grille[niveau][indice];
}

void Plateau::setNoble(int *tab_noble) {
    srand(time(NULL));
    int nb_joueur = Partie::getNombreJoueur();
    if (nb_joueur == 2){
        for (int i = 0; i < 3; i++){
            tab_noble[i] = rand() %10+1;
        }
    }
    else if (nb_joueur == 3){
        for (int i = 0; i < 4; i++){
            tab_noble[i] = rand() %10+1;
        }
    }
    else if (nb_joueur == 4){
        for (int i = 0; i < 5; i++){
            tab_noble[i] = rand() %10+1;
        }
    }
}

void Plateau::setGrille(int (*tab_grille)[4]){
    srand(time(NULL));
    for (int i = 0; i < 4; i++){
        tab_grille[0][i] = rand() %40+1;
        tab_grille[1][i] = rand() %30+41;
        tab_grille[2][i] = rand() %20+71;
    }
}

void Plateau::remplacerCarte(int niveau, int indice){
    grille[niveau][indice] = 0 // remplacer par l'id de la carte sur le dessus de la pioche du niveau correspondant
}
