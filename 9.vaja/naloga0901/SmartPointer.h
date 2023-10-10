#ifndef NALOGA0901_SMARTPOINTER_H
#define NALOGA0901_SMARTPOINTER_H

template<typename T>
class SmartPointer {
private:
    T *pData;
public:
    SmartPointer(T *pData) : pData(pData) {}

    ~SmartPointer() {
        delete pData;
    };

    T &operator*() {
        return *pData;
    }

    T *operator->() {
        return pData;
    }
};

#endif //NALOGA0901_SMARTPOINTER_H
