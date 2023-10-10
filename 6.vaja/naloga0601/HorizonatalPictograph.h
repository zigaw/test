#ifndef NALOGA0601_HORIZONATALPICTOGRAPH_H
#define NALOGA0601_HORIZONATALPICTOGRAPH_H
#include "Graph.h"

class HorizonatalPictograph: public Graph{
private:
    char symbol;
public:
    HorizonatalPictograph(const std::string &title, const std::vector<int> &data, char symbol);
    void show(ColorCode color) override;
    char getSymbol() const;
    void setSymbol(char symbol);
};


#endif //NALOGA0601_HORIZONATALPICTOGRAPH_H
