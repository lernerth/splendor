#include "joueur.h"

int Joueur::getNbJetonsTot(){
    int t = jetons.value("blanc", 0)+jetons.value("bleu", 0)+jetons["noir"]+jetons["rouge"]+jetons["vert"]+jetons["jaune"];
    return t;
}

//Ajoute la carte entrée dans la réserve s'il reste de la place.
void Joueur::ajouter_carte_reserve(Carte* carte, Carte** cartes_reservees) {
    for(int i = 0; i <3 ; ++i) {
        if(cartes_reservees[i] == 0){
            cartes_reservees[i] = carte;
            break;
        }
        else if(i==2){
            std::cout <<"Impossible réserve déjà pleine";
            break;
        }
    }
}


//Retire une carte de la reserve. ATTENTION : il faut l'acheter après
void Joueur::retirer_carte_reserve(Carte* carte, Carte** cartes_reservees){
    //a faire
}


//Achète une carte
void Joueur::acheter_carte(Carte* carte, Carte** cartes_achetees) {
    int i = 0;
    while(cartes_achetees[i] != 0) {
        i++;
        }
    cartes_achetees[i] = carte;
    //ajouter les prestige
    //ajouter les bonus
}



//Donne un noble au joueur
void Joueur::recupérer_noble(Carte* carte, Noble** noble) {
    int i = 0;
    while(noble[i] != 0) {
        i++;
        }
    cartes_achetees[i] = carte;
    //ajouter les prestige
    //ajouter les bonus
}

/*
void Joueur::ajouter_jeton(Couleur c){
    jetons[c]++;
}
*/



//CONSTRUCTEUR
//Joueur():initialise les attributs de la classe à 0/nullptr

/*
Joueur::Joueur(){

    for (int i = 0; i <3; ++i){
        cartes_reservees[i]=0;
    }

    cartes_achetees = nullptr;
    prestige = 0;

    for (int i = 0; i <6 ; ++i) {
        jetons[i]= 0;
    }

    for (int i = 0; i <5 ; ++i) {
        bonus[i]= 0;
    }

    for (int i = 0; i <5 ; ++i) {
        noble[i] = nullptr;
    }

    id_joueur = 0;
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
int Joueur::getJetons(int indice){
    return jetons[indice];
}

//getReserve(int indice): renvoie le pointeur vers la carte pour la position (indice) donnée.
int Joueur::getReserve(int indice){
    return cartes_reservees[indice];
}

//SETTERS

//Set_Jetons(int add_jetons[6]) : additionne au tableau de jetons le tableau entré.
void Joueur::setJetons (int add_jetons[6]){
    for (int i = 0; i <6 ; ++i) {
        jetons[i]= jetons[i]+ add_jetons[i];
    }
}

//Set_bonus(int indice) : incrémente de 1 le nombre de bonus pour une couleur donnée.
void Joueur::setBonus(int indice){
    bonus[indice]++;
}


//Set_prestige(int points_supp): ajoute un nombre de donné au prestige du joueur.
void Joueur::setPrestige(int nb_points){
    prestige+= nb_points;
}


//set_Id (string id)
//définit l'identifiant du joueur.
void Joueur::setId(int id){
     id_joueur = id;
}

*/
