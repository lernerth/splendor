#include "Carte.h"

Carte::Carte() {
    setRow(0);
    setPrestige(0);
    setDiscount(0);
    for (int i = 0; i < 5; i++){
        prix[i]=0;
    }
}

void Carte::setRow(int row){
    this->row = row;
}

int Carte::getRow(){
    return this->row;
}

void Carte::setDiscount(int index){
    this->discount[index] = 1;
}

int Carte::getDiscount(){
    for(int i = 0; i < 5; i++){
        if(discount[i]==1){
            return i;
        }
    }
    return -1;
}

void Carte::setPrestige(int prestige){
    this->prestige = prestige;
}

int Carte::getPrestige(){
    return this->prestige;
}

void Carte::setIdCarte(int id_Carte){
    this->id_Carte = id_Carte;
}

int Carte::getIdCarte(){
    return this->id_Carte;
}

void Carte::setPrix(int *tab_prix){
    for (int i = 0; i < 5; ++i){
        prix[i]=tab_prix[i];
    }
}

int Carte::getPrix(int index){
    if(index == 0){
            return prix[0];
        }
        if(index == 1){
            return prix[1];
        }
        if(index == 2){
            return prix[2];
        }
        if(index == 3){
            return prix[3];
        }
        if(index == 4){
            return prix[4];
        }
        return 0;
}
