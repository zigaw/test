#ifndef NALOGA0901_SMARTPOINTER_H
#define NALOGA0901_SMARTPOINTER_H
#include "ReferenceCounter.h"

template<typename T>
class SmartPointer {
private:
    T *pData;
    ReferenceCounter* referenceCounter;
public:
    SmartPointer(T *pData) : pData(pData), referenceCounter(new ReferenceCounter()) {
        ++(*referenceCounter);
    }

    SmartPointer(const SmartPointer<T>& smartPointer) : pData(smartPointer.pData), referenceCounter(smartPointer.referenceCounter) {
        ++(*referenceCounter);
    };

    ~SmartPointer() {
        if (--(*referenceCounter) == 0) {
            delete pData;
            delete referenceCounter;
        }
    };

    SmartPointer<T>& operator=(const SmartPointer<T>& smartPointer) {
        if (this != &smartPointer) {
            if (--(*referenceCounter) == 0) {
                delete pData;
                delete referenceCounter;
            }
            pData = smartPointer.pData;
            referenceCounter = smartPointer.referenceCounter;
            ++(*referenceCounter);
        }
        return *this;
    }


    T &operator*() {
        return *pData;
    }

    T *operator->() {
        return pData;
    }

    int useCount() const {
        return referenceCounter->getCount();
    }

    bool operator==(const SmartPointer<T>& other) const{
        if(this == &other){
            return true;
        }
        return false;
    }

    bool operator!=(const SmartPointer<T>& other) const{
        if(this != &other){
            return true;
        }
        return false;
    }
};

#endif //NALOGA0901_SMARTPOINTER_H
