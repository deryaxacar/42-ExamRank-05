#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {

}
TargetGenerator::~TargetGenerator() {
    _TargetG.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
    map<string, ATarget*>::iterator it = _TargetG.find(target->getType());
    if(it == _TargetG.end()){
        _TargetG[target->getType()] = target;
    }
}
void TargetGenerator::forgetTargetType(string const &targetName) {
    map<string, ATarget*>::iterator it = _TargetG.find(targetName);
    if(it != _TargetG.end()){
        _TargetG.erase(targetName);
    }
}
ATarget* TargetGenerator::createTarget(string const &targetName) {
    map<string, ATarget*>::iterator it = _TargetG.find(targetName);
    if(it != _TargetG.end()){
        return it->second->clone();
    }
    return nullptr;
}
