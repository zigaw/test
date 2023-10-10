#ifndef NALOGA0601_GRAPH_H
#define NALOGA0601_GRAPH_H
#include "iostream"
#include "vector"
#include "ColorCode.h"
#include "PrintUtility.h"

class Graph {
protected:
    std::string title;
    std::vector<int> data;
public:
    Graph(const std::string &title, const std::vector<int> &data);
    int getMaxValue() const;
    int getMinValue() const;
    virtual void show(ColorCode color) = 0;

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::vector<int> &getData() const;

    void setData(const std::vector<int> &data);

};


#endif //NALOGA0601_GRAPH_H
