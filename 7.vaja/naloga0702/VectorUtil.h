#ifndef NALOGA0701_VECTORUTIL_H
#define NALOGA0701_VECTORUTIL_H

#include "iostream"
#include "vector"
#include "Point.h"
#include "PrintUtility.h"

template<typename T>
void fillDefault(std::vector<T> &list, int n) {
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


template<typename T>
void print(std::vector<T> list) {
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << std::endl;
    }
}

template<typename T>
void print(std::vector<std::vector<T>> listOfLists) {
    std::vector<T> list;
    for (int i = 0; i < listOfLists.size(); ++i) {
        list = listOfLists[i];
        for (int j = 0; j < list.size(); ++j) {
            std::cout << list[j] << " ";
        }
        std::cout << std::endl;
    }
}


template<typename T>
std::vector<T> reverse(std::vector<T> list) {
    std::vector<T> listCopy = list;
    for (int i = 0; i < list.size(); ++i) {
        list[i] = listCopy[list.size() - 1 - i];
    }
    return list;
}

template<typename T>
std::vector<T> mergeVectors(std::vector<std::vector<T>> listOfVectors) {
    std::vector<T> mergedList;
    std::vector<T> listCopy;
    for (int i = 0; i < listOfVectors.size(); ++i) {
        listCopy = {listOfVectors[i]};
        for (int j = 0; j < listCopy.size(); ++j) {
            mergedList.push_back(listCopy[j]);
        }
    }
    return mergedList;


}

template<typename T>
void printColor(std::vector<T> list, ColorCode color = ColorCode::Green) {
    for (int i = 0; i < list.size(); ++i) {
        PrintUtility::print(color, std::to_string(list[i]));
        std::cout << std::endl;
    }
}

template<typename T, typename T2>
std::vector<std::vector<T>> slice(std::vector<T> list, T2 n) {
    std::vector<std::vector<T>> listOfLists;
    std::vector<T> listNSize;
    int modul = list.size() % n;
    int k = 0;
    for (int i = 0; i < list.size() - modul; i += n) {
        for (int j = 0; j < n; ++j) {
            listNSize.push_back(list[k]);
            k++;
        }
        listOfLists.push_back(listNSize);
        listNSize = {};
    }
    if (modul != 0) {
        for (int i = list.size() - modul; i < list.size(); ++i) {
            listNSize.push_back(list[i]);
        }
        listOfLists.push_back(listNSize);
    }

    return listOfLists;
}

template<typename T>
std::vector<T> removeDuplicates(std::vector<T> list) {
    std::vector<T> finalList;
    std::vector<T> listCopy = list;
    for (int i = 0; i < list.size(); i++) {
        bool duplicateFound = false;
        for (int j = i + 1; j < listCopy.size(); j++) {
            if (list[i] == listCopy[j]) {
                duplicateFound = true;
                break;
            }
        }
        if (!duplicateFound) {
            finalList.push_back(list[i]);
        }
    }
    return finalList;
}

template<typename T>
std::vector<std::vector<T>> sortByDecimal(std::vector<T> list) {
    std::vector<std::vector<T>> listOfLists;
    std::vector<T> decimalList;
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < list.size(); ++i) {

            int checkDecimal = list[i] * 10;
            if (checkDecimal % 10 == j) {
                decimalList.push_back(list[i]);
            }
        }
        listOfLists.push_back(decimalList);
        decimalList = {};
    }
    return listOfLists;
}

template<typename T>
std::vector<std::vector<T>> removeMultipliersOfN(std::vector<std::vector<T>> listOfLists, int n) {
    std::vector<T> list;
    std::vector<T> listCleared;
    std::vector<std::vector<T>> listOfListsCleared;
    for (int i = 0; i < listOfLists.size(); ++i) {
        list = listOfLists[i];
        for (int j = 0; j < list.size(); ++j) {
            if (list[j] % n != 0) {
                listCleared.push_back(list[j]);
            }
        }
        listOfListsCleared.push_back(listCleared);
        listCleared = {};
    }
    return listOfListsCleared;
}

template<typename T, typename T2 = T>
int countType(std::vector<T *> list) {
    int counter = 0;
    for (int i = 0; i < list.size(); ++i) {
        if (dynamic_cast<T2 *>(list[i])) {
            counter++;
        }
    }
    return counter;
}


#endif //NALOGA0701_VECTORUTIL_H
