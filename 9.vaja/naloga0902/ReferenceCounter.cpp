#include "ReferenceCounter.h"

ReferenceCounter:: ReferenceCounter() : count(0) {}

unsigned int ReferenceCounter::operator--(){
    return count--;
}

unsigned int ReferenceCounter::operator++() {
    return count++;
}

unsigned int ReferenceCounter:: getCount() const {
    return count;
}