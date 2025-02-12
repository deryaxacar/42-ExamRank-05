#include "SpellBook.hpp"

SpellBook::SpellBook() {

}
SpellBook::~SpellBook() {
    _SpellBook.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
    map<string, ASpell*>::iterator it = _SpellBook.find(spell->getName());
    if(it == _SpellBook.end()){
        _SpellBook[spell->getName()] = spell->clone();
    }
}
void SpellBook::forgetSpell(string const &spellName) {
    map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
    if(it != _SpellBook.end()){
        delete it->second;
        _SpellBook.erase(spellName);
    }
}
ASpell* SpellBook::createSpell(string const &spellName) {
    map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
    if(it != _SpellBook.end()){
        return it->second->clone();
    }
    return nullptr;
}
