#include "VerticalPictograph.h"

VerticalPictograph:: VerticalPictograph(const std::string &title, const std::vector<int> &data, char symbol): Graph(title,data){
    this->title = title;
    this->data = data;
    this->symbol = symbol;
}




char VerticalPictograph::getSymbol() const {
    return symbol;
}

void VerticalPictograph::setSymbol(char symbol) {
    VerticalPictograph::symbol = symbol;
}


void VerticalPictograph::show(ColorCode color) {
    std::cout << title << std::endl;
    std::string str(1, symbol);
    int max_value = getMaxValue();
    for (int i = max_value; i > 0; --i) {
        for (int j = 0; j < data.size(); ++j) {
            if (data[j] >= i) {
                PrintUtility::printSequence(color,str,1);
                std::cout<< " ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < data.size(); ++i) {
        std::cout << "- ";
    }
    std::cout << std::endl;

    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}








