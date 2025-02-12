#include "Warlock.hpp"

const string& Warlock::getName() const {
    return this->_name;
}
const string& Warlock::getTitle() const {
    return this->_title;
}
void Warlock::setTitle(const string& title) {
    this->_title = title;
}

Warlock::Warlock(const string& name, const string& title) : _name(name), _title(title) {
    cout << getName() << ": This looks like another boring day." << endl;
}
Warlock::~Warlock() {
    cout << getName() << ": My job here is done!" << endl;
}

void Warlock::introduce() const {
    cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << endl;
}

void Warlock::learnSpell(ASpell* spell) {
    _Spell.learnSpell(spell);
}
void Warlock::forgetSpell(const string& spellName) {
    _Spell.forgetSpell(spellName);
}
void Warlock::launchSpell(const string& spellName, const ATarget& target) {
    ASpell *tmp = _Spell.createSpell(spellName);
    if(tmp != nullptr){
        tmp->launch(target);
        delete tmp;
    }
}
