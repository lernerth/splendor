#include "Plateau.h"

//PASSER AUX POINTEURS
Plateau::Plateau(){
    for (int i = 0; i < 5; i++){
        noble[i] = nullptr;
    }

    for (int j = 0; j < 3; j++){
        for (int k = 0; k < 4; k++){
            grille[j][k] = nullptr;
        }
    }
}

void Plateau::modifCarteGrille(int niveau, int emplacement, Carte* c){
    grille[niveau][emplacement] = c;
}

void Plateau::modifierNoble(int indice, Noble* n){
    noble[indice] = n;
}

