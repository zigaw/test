#ifndef NALOGA0801_LINEARQUEUE_H
#define NALOGA0801_LINEARQUEUE_H

#include "Time.h"

template<typename T>

class LinearQueue {
private:
    std::vector<T> values;
    unsigned int capacity;
public:
    LinearQueue(const std::vector<T> &values) : values(values), capacity(20) {}

    bool empty() const {
        if (values.size() == 0) {
            return true;
        }
        return false;
    }

    int size() const {
        return values.size();
    }


    T element() const {
        return values[0];
    }

    void add(T element) {
        if (values.size() < capacity) {
            values.push_back(element);
        } else {
            std::cout << "Capacity has been reached";
        }
    }

    bool remove() {
        if (!this->empty()) {
            values.erase(values.begin());
            return true;
        }
        return false;
    }

    std::string toString() {
        std::stringstream valuesData;
        for (int i = 0; i < values.size(); ++i) {
            valuesData << std::to_string(values[i]) << " ";
        }
        return valuesData.str();
    }

    void reverse() {
        std::vector<T> valuesCopy = values;
        for (int i = values.size() - 1; i >= 0; --i) {
            values[values.size() - i - 1] = valuesCopy[i];
        }
    }

    T getMax() {
        T max = values[0];
        for (int i = 1; i < values.size(); ++i) {
            if (values[i] > max) {
                max = values[i];
            }
        }
        return max;
    }

    void insertAt(T element, unsigned int n) {
        if (values.size() < capacity) {
            if (n > values.size()) {
                values.push_back(element);
            } else {
                std::vector<T> valuesCopy = values;
                values = {};
                for (int i = 0; i < n; ++i) {
                    values.push_back(valuesCopy[i]);
                }
                values.push_back(element);
                for (unsigned int i = n; i < valuesCopy.size(); ++i) {
                    values.push_back(valuesCopy[i]);
                }
            }
        }
    }

    void unique() {
        std::vector<T> tempList;
        std::vector<T> listCopy = values;
        for (int i = 0; i < values.size(); i++) {
            bool duplicateFound = false;
            for (int j = i + 1; j < listCopy.size(); j++) {
                if (values[i] == listCopy[j]) {
                    duplicateFound = true;
                    break;
                }
            }
            if (!duplicateFound) {
                tempList.push_back(values[i]);
            }

        }
        values = {};
        for (int i = 0; i < tempList.size(); ++i) {
            values.push_back(tempList[i]);
        }

    }

    unsigned int getCapacity() const {
        return capacity;
    }

    void changeCapacity(unsigned int newCapacity) {
        this->capacity = newCapacity;
        if (values.size() > capacity) {
            while (values.size() > capacity) {
                this->remove();
            }
        }
    }
};

template<>
class LinearQueue<Time> {
private:
    std::vector<Time> values;
    unsigned int capacity;

public:
    LinearQueue(const std::vector<Time> &values) : values(values), capacity(20) {}

    bool empty() const {
        if (values.size() == 0) {
            return true;
        }
        return false;
    }

    int size() const {
        return values.size();
    }


    Time element() const {
        return values[0];
    }

    void add(Time element) {
        if (values.size() < capacity) {
            values.push_back(element);
        } else {
            std::cout << "Capacity has been reached";
        }
    }

    bool remove() {
        if (!this->empty()) {
            values.erase(values.begin());
            return true;
        }
        return false;
    }

    std::string toString() {
        std::stringstream valuesData;
        for (int i = 0; i < values.size(); ++i) {
            valuesData << values[i].toString() << " ";
        }
        return valuesData.str();
    }

    void reverse() {
        std::vector<Time> valuesCopy = values;
        for (int i = values.size() - 1; i >= 0; --i) {
            values[values.size() - i - 1] = valuesCopy[i];
        }
    }

    Time getMax() {
        unsigned int index;
        int max = values[0].getInSeconds();
        for (int i = 1; i < values.size(); ++i) {
            if (values[i].getInSeconds() > max) {
                max = values[i].getInSeconds();
                index = i;
            }
        }
        return values[index];
    }

    void insertAt(Time element, unsigned int n) {
        if (values.size() < capacity) {
            if (n > values.size()) {
                values.push_back(element);
            } else {
                std::vector<Time> valuesCopy = values;
                values = {};
                for (int i = 0; i < n; ++i) {
                    values.push_back(valuesCopy[i]);
                }
                values.push_back(element);
                for (unsigned int i = n; i < valuesCopy.size(); ++i) {
                    values.push_back(valuesCopy[i]);
                }
            }
        }
    }

    void unique() {
        std::vector<Time> tempList;
        std::vector<Time> listCopy = values;
        for (int i = 0; i < values.size(); i++) {
            bool duplicateFound = false;
            for (int j = i + 1; j < listCopy.size(); j++) {
                if (values[i].getInSeconds() == listCopy[j].getInSeconds()) {
                    duplicateFound = true;
                    break;
                }
            }
            if (!duplicateFound) {
                tempList.push_back(values[i]);
            }

        }
        values = {};
        for (int i = 0; i < tempList.size(); ++i) {
            values.push_back(tempList[i]);
        }

    }

    unsigned int getCapacity() const {
        return capacity;
    }

    void changeCapacity(unsigned int newCapacity) {
        this->capacity = newCapacity;
        if (values.size() > capacity) {
            while (values.size() > capacity) {
                this->remove();
            }
        }
    }

};


#endif //NALOGA0801_LINEARQUEUE_H
