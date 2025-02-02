#pragma once

#include "ATarget.hpp"

class Dummy : public ATarget{
    public:
        ATarget* clone() const;
        Dummy();
        ~Dummy();
};