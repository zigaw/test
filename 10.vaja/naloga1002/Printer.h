

#ifndef NALOGA1002_PRINTER_H
#define NALOGA1002_PRINTER_H

#include "iostream"
#include "vector"
#include "string"
#include "sstream"
#include "algorithm"
#include "functional"
#include "sstream"

class Printer {


private:
    std::vector<std::string> queue;
public:
    Printer(const std::vector<std::string> &queue);


    std::string toString();

    void print();

    template<typename T>
    void add(T insertElement) {
        std::stringstream insertQueue;
        insertQueue << insertElement;
        queue.push_back(insertQueue.str());
    }




    template<typename T>
    void addMultiple(std::vector<T> insertVector) {

        for (int i = 0; i < insertVector.size(); ++i) {
            std::stringstream insertQueue;
            insertQueue << insertVector[i];
            queue.push_back(insertQueue.str());
        }
    }

    template<typename T>
    void remove(T function){
        for (auto it = queue.begin(); it != queue.end();) {
            if (function(*it)) {
                it = queue.erase(it);
            } else {
                ++it;
            }
        }
    }

    template<typename T>
    void  sort(T function){
        for (int i = 0; i < queue.size() - 1; i++) {
            for (int j = i + 1; j < queue.size(); j++) {
                if (function(queue[j], queue[i])) {
                    std::string temp = queue[i];
                    queue[i] = queue[j];
                    queue[j] = temp;
                }
            }
        }
    }

    template<typename T1 ,typename T2>
    void checkAndCorrect(T1 functionOne, T2 functionTwo){
        for (int i = 0; i < queue.size(); ++i) {
            if(functionOne(queue[i])){
                functionTwo(queue[i]);
            }
        }
    }

    template<typename T>
    std::string findFirstMatchingElement(T function){
        auto it = std::find_if(queue.begin(), queue.end(), function);
        if (it != queue.end()) {
            return it;
        }
        return "";
    }


    template <typename T>
    void applyToAll(T function) {
        for (auto& element : queue) {
            function(element);
        }
    }


template<typename T,typename... Arguments>
void add(T first, Arguments... arguments){
    add(first);
    add(arguments...);
}


template<typename... Arguments>
void removeJobs(Arguments... arguments){

    std::vector<int>indexes = {arguments...};

    for (int i = 0; i < indexes.size()  - 1; i++) {
        for (int j = i + 1; j < indexes.size(); j++) {
            if (indexes[j] < indexes[i]) {
                int temp = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = temp;
            }
        }

    }
    for (int i = 0; i < indexes.size(); ++i) {
     queue[indexes[i]].erase();
    }


    }

};

#endif //NALOGA1002_PRINTER_H
