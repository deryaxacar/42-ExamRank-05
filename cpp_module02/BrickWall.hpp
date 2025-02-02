#pragma once

#include "ATarget.hpp"

class BrickWall : public ATarget{
    public:
        ATarget* clone() const;
        BrickWall();
        ~BrickWall();
};