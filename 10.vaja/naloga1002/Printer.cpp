#include "Printer.h"

Printer::Printer(const std::vector<std::string> &queue) : queue(queue) {}


std::string Printer:: toString(){
   std::stringstream queueString;
    for (int i = 0; i < queue.size(); ++i) {
       queueString << queue[i] << std::endl;
    }
    return queueString.str();
}
void Printer:: print(){
    std::cout<< toString();
    queue.resize(0);
}

















