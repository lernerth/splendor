#ifndef PIOCHE_NOBLE_H
#define PIOCHE_NOBLE_H
#include "Noble.h"
#include "Exception.h"

class Pioche_Noble{
public:
    Pioche_Noble();
    int getNbNobles() {return nbNoble;}
    Noble** getTous() {return tous;}
    Noble* getNoble(int i) {return tous[i];}
    Noble* piocherNoble(Pioche_Noble* n);
private:
    friend class Controleur;
    Pioche_Noble(Pioche_Noble& j) = delete;
    Pioche_Noble& operator=(Pioche_Noble& j) = delete;
    Noble** tous;
    int nbNoble;

};

#endif // PIOCHE_NOBLE_H
