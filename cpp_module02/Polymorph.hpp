#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell{
    public:
        ASpell* clone() const;
        Polymorph();
        ~Polymorph();
};