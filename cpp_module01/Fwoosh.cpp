#include "Fwoosh.hpp"

ASpell* Fwoosh::clone() const {
    return new Fwoosh();
}
Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed" ) {

}
Fwoosh::~Fwoosh() {

}