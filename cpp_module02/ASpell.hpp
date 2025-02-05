#pragma once 

#include <iostream>
#include "ATarget.hpp"

using std::string;
using std::cout;
using std::endl;

class ATarget;

class ASpell {
    protected:
        string _name;
        string _effects;
    public:
        const string& getName() const;
        const string& getEffects() const;
        virtual ASpell* clone() const = 0;
        ASpell(const string& name, const string& effects);
        virtual ~ASpell();

        void launch(const ATarget& target) const;

};