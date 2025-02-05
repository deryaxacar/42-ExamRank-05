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
    map<string, ASpell*>::iterator it = _SpellBook.find(spell->getName());
    if(it == _SpellBook.end()){
        _SpellBook[spell->getName()] = spell->clone();
    }
}
void Warlock::forgetSpell(const string& spellName) {
    map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
    if(it != _SpellBook.end()){
        delete it->second;
        _SpellBook.erase(spellName);
    }
}
void Warlock::launchSpell(const string& spellName, const ATarget& target) {
    map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
    if(it != _SpellBook.end()){
        it->second->launch(target);
    }
}