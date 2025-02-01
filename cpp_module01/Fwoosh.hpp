#pragma once

#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell{
    public:
        ASpell* clone() const;
        Fwoosh();
        ~Fwoosh();
};