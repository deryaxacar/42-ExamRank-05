#include "ATarget.hpp"

const string& ATarget::getType() const {
    return this->_type;
}
ATarget::ATarget(const string& type) : _type(type) {

}
ATarget::~ATarget() {

}

void ATarget::getHitBySpell(const ASpell& spell) const {
    cout << getType() << " has been " << spell.getEffects() << "!" << endl;
}