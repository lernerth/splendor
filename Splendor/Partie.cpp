#include "Partie.h"


Partie::Partie(size_t n, QString j[3]){
    Nbjoueur = n;
    for (size_t i=0; i<n; i++){
        ListeJoueur[i] = new Joueur(j[i]);
    }
};

const Joueur& Partie::getJoueur(size_t numJ) {
    const Joueur* j = nullptr;
    if(numJ>Nbjoueur) throw Exception("Ce joueur n'existe pas");
    j = this->ListeJoueur[numJ];
    return *j;
};

void Partie::PiocherJetons(Couleur c1, Couleur c2, Couleur c3){
    if(c1 == c2){
        if (pj[c1]<4) throw Exception("Il est interdit de prendre deux jetons de même couleur s'il en reste moins de quatre disponibles...");
            retirer_Jetons(c1);//l'erreur doit venir du fait que les fonction ne soient pas explicitées dans le controleur.cpp
            retirer_Jetons(c2);

            ajouter_jeton(c1);
            ajouter_jeton(c2);
    }

    else if((c1 != c2)&&(c2!=c3)&&(c3!=c1)){
        if(pj[c1] == 0 || pj[c2] == 0 || pj[c3] == 0){
            throw Eception("Il n'y a plus de jeton dans cette pioche...");
        }

        retirer_Jetons(c1);
        retirer_Jetons(c2);
        retirer_Jetons(c3);

        ajouter_jeton(c1);
        ajouter_jeton(c2);
        ajouter_jeton(c3);
    }

    else{
        throw Exception ("Vous ne pouvez prendre que 2 jetons de la même couelur, ou 3 différents...");
    }

    if(getNbJetonsTot > 10){
        throw Excpetion ("Vous ne pouvez pas avoir plus de 10 jetons, merci de vous en débarasser");
        for(int i=getNbJetonsTot-10 ; i > 0; i--){
            retirer_jeton(c);
            rendre_Jetons(c);
        }
    }
}


Carte& Partie::AcheterCarte(Carte* carte){
    int manquant = 0;
    if(prix["blanc"] - bonus["blanc"] > jetons["blanc"]){
        manquant =  manquant + prix["blanc"] - bonus["blanc"] - jetons["blanc"];
    }

    if(prix["bleu"] - bonus["bleu"] > jetons["bleu"]){
        manquant =  manquant + prix["bleu"] - bonus["bleu"] - jetons["bleu"];
    }

    if(prix["noir"] - bonus["noir"] > jetons["noir"]){
        manquant =  manquant + prix["noir"] - bonus["noir"] - jetons["noir"];
    }

    if(prix["rouge"] - bonus["rouge"] > jetons["rouge"]){
        manquant =  manquant + prix["rouge"] - bonus["rouge"] - jetons["rouge"];
    }

    if(prix["vert"] - bonus["vert"] > jetons["vert"]){
        manquant =  manquant + prix["vert"] - bonus["vert"] - jetons["vert"];
    }


    if(manquant == 0){
        for(int i = 0 ; i<3 ; i++){
            if(cartes_reservees = carte){
                retirer_carte_reserve(carte, cartes_reservees);
            }
        }
        retirer_carte(carte);
        acheter_carte(carte, cartes_achetees);
    }

    elseif(manquant > 0 && manquant <= jetons["jaune"]){
        for(int i = 0 ; i<3 ; i++){
            if(cartes_reservees = carte){
                retirer_carte_reserve(carte, cartes_reservees);
            }
        }
        retirer_carte(carte);
        acheter_carte(carte, cartes_achetees);
    }

    else{
        throw Exception("Vous ne pouvez pas acheter cette carte...");
    }
}


Carte& ReserverCarte(Carte* carte){
     ajouter_carte_reserve(carte, cartes_reservees);//ajoute la carte dans la main du joueur, vérifie déjà s'il y en a 3 ou pas
     retirer_carte_reserve(carte, cartes_reservees);//enlève la carte ET la remplace
}
