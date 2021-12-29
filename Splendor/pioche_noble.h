#ifndef PIOCHE_NOBLE_H
#define PIOCHE_NOBLE_H
#include "Noble.h"
#include "Exception.h"

class Pioche_Noble{
public:
    int getNbNobles() const {return 10;}
    const Noble** getTous() const {return tous;}
    const Noble& getNoble(size_t i) const {if (i >= 11) throw Exception("Out of range"); return *tous[i];}
private:
    Pioche_Noble();
    Pioche_Noble(const Pioche_Noble& j) = delete;
    Pioche_Noble& operator=(const Pioche_Noble& j) = delete;
    const Noble** tous;

};

#endif // PIOCHE_NOBLE_H
