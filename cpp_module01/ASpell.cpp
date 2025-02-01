#include "ASpell.hpp"

const string& ASpell::getName() const {
    return this->_name;
}
const string& ASpell::getEffects() const {
    return this->_effects;
}
ASpell::ASpell(const string& name, const string& effects) : _name(name), _effects(effects) {

}
ASpell::~ASpell() {

}

void ASpell::launch(const ATarget& target) const {
    target.getHitBySpell(*this);
}