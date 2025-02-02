#include "Polymorph.hpp"

ASpell* Polymorph::clone() const {
    return new Polymorph();
}

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {

}

Polymorph::~Polymorph() {

}