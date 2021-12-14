#include "Carte.h"

Carte::Carte() {
    setRow(0);
    setPrestige(0);
    setDiscount("");
    for (int i = 0; i < 5; i++){
        price[i]=0;
    }
}

void Carte::setRow(int row){
    this->row = row;
}

int Carte::getRow(){
    return this->row;
}

void Carte::setDiscount(string discount){
    this->discount = discount;
}

string Carte::getBonusColor(){
    return this->discount;
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

void Carte::setPrice(int *tab_price){
    for (int i = 0; i < 5; ++i){
        price[i]=tab_price[i];
    }
}

int Carte::getPrice(int index){
    if(index == 0){
            return price[0];
        }
        if(index == 1){
            return price[1];
        }
        if(index == 2){
            return price[2];
        }
        if(index == 3){
            return price[3];
        }
        if(index == 4){
            return price[4];
        }
        return 0;
}
