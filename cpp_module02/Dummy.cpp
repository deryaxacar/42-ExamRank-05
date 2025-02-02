#include "Dummy.hpp"

ATarget* Dummy::clone() const {
    return new Dummy();
}
Dummy::Dummy() : ATarget("Target Practice Dummy") {

}
Dummy::~Dummy() {

}