#pragma once

#include <map>
#include <iostream>
#include "ASpell.hpp"

using std::string;
using std::map;

class ASpell;

class SpellBook{
    protected:
        map<string, ASpell*> _SpellBook;
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(const ASpell* spell);
        void forgetSpell(string const &spellName);
        ASpell* createSpell(string const &spellName);
};