#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell {
    public:
        ASpell* clone() const;
        Fireball();
        ~Fireball();
};