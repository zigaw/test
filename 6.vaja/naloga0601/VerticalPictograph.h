#ifndef NALOGA0601_VERTICALPICTORGRAPH_H
#define NALOGA0601_VERTICALPICTORGRAPH_H
#include "Graph.h"


class VerticalPictograph : public Graph{
private:
    char symbol;
public:
    VerticalPictograph(const std::string &title, const std::vector<int> &data, char symbol);
    void show(ColorCode color) override;
    char getSymbol() const;

    void setSymbol(char symbol);
};


#endif //NALOGA0601_VERTICALPICTORGRAPH_H
