#ifndef NALOGA0902_REFERENCECOUNTER_H
#define NALOGA0902_REFERENCECOUNTER_H


class ReferenceCounter {
private:
    unsigned int count;
public:
    ReferenceCounter();
    unsigned int operator--();

    unsigned int operator++();

    unsigned int getCount() const;

};


#endif //NALOGA0902_REFERENCECOUNTER_H
