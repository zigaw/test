#include "HorizonatalPictograph.h"
#include "VerticalPictograph.h"

HorizonatalPictograph::HorizonatalPictograph(const std::string &title, const std::vector<int> &data, char symbol): Graph(title,data) {
    this->title = title;
    this->data = data;
    this->symbol = symbol;
}




char HorizonatalPictograph::getSymbol() const {
    return symbol;
}

void HorizonatalPictograph::setSymbol(char symbol) {
    this->symbol = symbol;
}


void HorizonatalPictograph::show(ColorCode color) {
    std::cout << title << std::endl;
    std::string str(1, symbol);
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << "|";
        for (int j = 0; j < data[i]; ++j) {
            PrintUtility::printSequence(color,str,1);
        }
        std::cout << std::endl;
    }
}








