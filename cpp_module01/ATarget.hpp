#pragma once 

#include <iostream>
#include "ASpell.hpp"

using std::string;
using std::cout;
using std::endl;

class ASpell;

class ATarget {
    protected:
        string _type;
    public:
        const string& getType() const;
        virtual ATarget* clone() const = 0;
        ATarget(const string& type);
        virtual ~ATarget();

        void getHitBySpell(const ASpell& spell) const;
};