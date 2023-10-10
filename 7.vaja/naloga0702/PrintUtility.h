#ifndef TASK0601_PRINTUTILITY_H
#define TASK0601_PRINTUTILITY_H

#include "ColorCode.h"
// More code info https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
class PrintUtility {
private:
    PrintUtility() = default;
public:
    static void print(const ColorCode &color, const std::string& str);
    static void printSequence(const ColorCode &color, const std::string& str, unsigned int n);
};

#endif //TASK0601_PRINTUTILITY_H
