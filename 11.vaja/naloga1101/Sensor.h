
#ifndef NALOGA1101_SENSOR_H
#define NALOGA1101_SENSOR_H
#include "iostream"
#include "sstream"
#include "string"
#include "vector"
#include "memory"
#include "fstream"
#include "InvalidLocationExeption.h"
class Sensor {
protected:
    int id;
    bool active;
public:

    Sensor(int id, bool active);

    int getId() const;

    bool isActive() const;

    virtual std::string toString() const;

    virtual float readValue() const;
};


#endif //NALOGA1101_SENSOR_H
