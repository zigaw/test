#ifndef NALOGA0701_VECTORUTIL_H
#define NALOGA0701_VECTORUTIL_H

#include "iostream"
#include "vector"
#include "Point.h"


template<typename Type>
void fillDefault(std::vector<Type> &list, int n) {
    for (int i = 0; i < n; ++i) {
        list.push_back(Point());
    }
}
template<>
void fillDefault<int>(std::vector<int> &list, int n) {
    for (int i = 0; i < n; ++i) {
        list.push_back(rand() % 10);
    }
}

template<>
void fillDefault<Point>(std::vector<Point> &list, int n) {
    for (int i = 0; i < n; ++i) {
        list.push_back(Point(rand() % 101,rand() % 101));
    }
}


template<typename VectorUtil>
void print(std::vector<VectorUtil> list) {
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << std::endl;
    }
}

template<typename VectorUtil>
std::vector<VectorUtil> reverse(std::vector<VectorUtil> list) {
    std::vector<VectorUtil> listCopy = list;
    for (int i = 0; i < list.size(); ++i) {
        list[i] = listCopy[list.size() - 1 - i];
    }
    return list;
}

template<typename VectorUtil>
std::vector<VectorUtil> mergeVectors(std::vector<std::vector<VectorUtil>> listOfVectors) {
    std::vector<VectorUtil> mergedList;
    for (int i = 0; i < listOfVectors.size(); ++i) {
        for (int j = 0; j < listOfVectors[i].size(); ++j) {
            mergedList.push_back(listOfVectors[i][j]);
        }
    }
    return mergedList;
}



#endif //NALOGA0701_VECTORUTIL_H
