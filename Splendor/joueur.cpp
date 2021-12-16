#include "joueur.h"

//CONSTRUCTEUR
//Joueur():initialise les attributs de la classe à 0/nullptr

Joueur::Joueur(){

    for (int i = 0; i <3; ++i){
    cartes_reservees[i]=nullptr;
    }

    cartes_achetees = nullptr;
    noble = nullptr;
    prestige = 0;

    for (int i = 0; i <6 ; ++i) {
        jetons[i]= 0;
    }

    for (int i = 0; i <5 ; ++i) {
        bonus[i]= 0;
    }

    for (int i = 0; i <3 ; ++i) {
        reserveCartes[i] = nullptr;
    }
}

//GETTERS
//totalPrestige(): renvoie le prestige du joueur.
int Joueur::totalPrestige() {
    return prestige;
}

//Getbonus(): renvoie le bonus pour une couleur donnée(représentée par un entier entre 1 et 5)
int Joueur::getBonus(int indice) {
    return bonus[indice];
}

//getnbJetons(int indice): renvoie le nombres de jetons d'une couleur donnée.
int Joueur::getnbJetons(int indice){
    return jetons[indice];
}

//getReserve(int indice): renvoie le pointeur vers la carte pour la position (indice) donnée.
Carte* Joueur::getReserve(int indice){
    return reserveCartes[indice];
}

//SETTERS

//Set_Jetons(int add_jetons[6]) : additionne au tableau de jetons le tableau entré.
void Joueur::setJetons (int add_jetons[6]){
    for (int i = 0; i <6 ; ++i) {
        jetons[i]= jetons[i]+ jetons[i];
    }
}

//Set_bonus(int indice) : incrémente de 1 le nombre de bonus pour une couleur donnée.
void Joueur::setBonus(int indice){
    bonus[indice] = bonus[indice] +1;
}

//Set_ReserveCartes
//Ajoute la carte entrée dans la réserve s'il reste de la place.
void Joueur::setReserveCartes(Carte *reserve_carte) {
    for (int i = 0; i <3 ; ++i) {
        if(reserveCartes[i] == nullptr){
            reserveCartes[i] = reserve_carte;
            break;
        }
    }
}

//Set_prestige(int points_supp): ajoute un nombre de donné au prestige du joueur.
void Joueur::setPrestige(int points_supp){
    prestige+= points_supp;
}


//remove_Reserve
//carte entrée dans la réserve s'il reste de la place.
void Joueur::removeReserve(int indice){
    reserveCartes[indice] = nullptr;
}

//set_Id (string id)
//définit l'identifiant du joueur.
void Joueur::set_Id(string id){
     id_joueur = id;
}
