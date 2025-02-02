#pragma once

#include <map>
#include <iostream>
#include "ATarget.hpp"

using std::string;
using std::map;

class ATarget;

class TargetGenerator{
    protected:
        map<string, ATarget*> _TargetG;
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget* target);
        void forgetTargetType(string const &targetName);
        ATarget* createTarget(string const &targetName);
};