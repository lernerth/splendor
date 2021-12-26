#include "Pioche_carte.h"

//constructeur
Pioche_carte::Pioche_carte(int niv) {
    switch(niv){
        case 1 : this->nb_cartes = 40;
        break;
        case 2 : this->nb_cartes = 30;
        break;
        case 3 : this->nb_cartes = 20;
        break;
    }
    this->cartes=new Carte* [nb_cartes];
    //remplir la pioche avec les cartes du jeu (mélangées) correspondant au niveau entré
    //pb : comment garantir qu'il n'y ait qu'une instance de pioche par niveau ?
    //trois classes-singleton ?
    
}

const Carte& Pioche_carte::piocher() {//issu de set.cpp
    if (this->nb_cartes == 0) throw SetException("Pioche vide");
    size_t x = rand() % nb;
	const Carte* c = this->cartes[x];
	for (size_t i = x + 1; i < nb; i++) this->cartes[i - 1] = this->cartes[i];
	nb--;
	return *c;
	}
