#include "Noble.h"

//constructeur
Noble::Noble() {
    id_noble = 0;
    for(int i = 0; i < 5; ++i){
        cout[i] = 0;
    }
    point_prestige = 0;
}


//récupérateur
int Noble::getIdNoble(){
    return this->id_noble;
}

int Noble::getCout(int index){
    switch(index){
        case '0':
            return cout[0];
        case '1':
            return cout[1];
        case '2':
            return cout[2];
        case '3':
            return cout[3];
        case '4':
            return cout[4];
    }
    return -1;
}

int Noble::getPtPrestige(){
    return this->point_prestige;
}


//setters
void Noble::setIdNoble(int id_Noble){
    this->id_noble = id_Noble;
}

void Noble::setCout(int *tab_cout){
    for(int i = 0; i < 5; i++){
        cout[i] = tab_cout[i];
    }
}

void Noble::setPtPrestige(int point_prestige){
    this->point_prestige = point_prestige;
}
