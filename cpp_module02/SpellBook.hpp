#pragma once

#include <map>
#include "ASpell.hpp"

using std::string;
using std::map;

class ASpell;

class SpellBook {
    private:
        map<string, ASpell*> _SpellBook;
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell* spell);
        void forgetSpell(string const &spellName);
        ASpell* createSpell(string const &spellName);
};