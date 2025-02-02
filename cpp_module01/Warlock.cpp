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

void Warlock::learnSpell(const ASpell* spell) {
    map<string, ASpell*>::iterator it = _spellBook.find(spell->getName());
    if(it == _spellBook.end()){
        _spellBook[spell->getName()] = spell->clone();
    }
}
void Warlock::forgetSpell(const string& spellName) {
    map<string, ASpell*>::iterator it = _spellBook.find(spellName);
    if(it != _spellBook.end()){
        delete it->second;
        _spellBook.erase(spellName);
    }
}
void Warlock::launchSpell(const string& spellName, const ATarget& target) {
    map<string, ASpell*>::iterator it = _spellBook.find(spellName);
    if(it != _spellBook.end()){
        it->second->launch(target);
    }
}