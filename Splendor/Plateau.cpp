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

