//
// Created by weing on 08/04/2023.
//

#include "Graph.h"

Graph:: Graph(const std::string &title, const std::vector<int> &data){
this->title = title;
this->data = data;
}

int Graph:: getMaxValue() const{
    int maxValue =data[0];
    for (int i = 1; i < data.size(); ++i) {
        if(maxValue < data[i]){
            maxValue = data[i];
        }
    }
    return maxValue;
}

int Graph:: getMinValue() const{
    int minValue =data[0];
    for (int i = 1; i < data.size(); ++i) {
        if(minValue > data[i]){
            minValue = data[i];
        }
    }
    return minValue;
}

void Graph:: show(ColorCode color){}



const std::string &Graph::getTitle() const {
    return title;
}

void Graph::setTitle(const std::string &title) {
    Graph::title = title;
}

const std::vector<int> &Graph::getData() const {
    return data;
}

void Graph::setData(const std::vector<int> &data) {
    Graph::data = data;
}
