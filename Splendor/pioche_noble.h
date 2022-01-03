#ifndef PIOCHE_NOBLE_H
#define PIOCHE_NOBLE_H
#include "Noble.h"
#include "Exception.h"

class Pioche_Noble{
public:
    Pioche_Noble();
    int getNbNobles() {return nbNoble;}
    Noble** getTous() {return tous;}
    Noble* getNoble(int i) {if (i >= 11) throw Exception("Out of range"); return tous[i];}
    Noble* piocherNoble();
private:
    Pioche_Noble(Pioche_Noble& j) = delete;
    Pioche_Noble& operator=(Pioche_Noble& j) = delete;
    Noble** tous;
    int nbNoble;

};

#endif // PIOCHE_NOBLE_H
