#include "Sensor.h"
#include "PressureUnit.h"
#ifndef NALOGA1101_PRESSURESENSOR_H
#define NALOGA1101_PRESSURESENSOR_H


class PressureSensor: public Sensor{
protected:
    PressureUnit unit;
public:

    PressureSensor() = delete;

    PressureSensor(int id,bool active, PressureUnit unit);

    virtual std::string toString() const override;

   static int toInt(PressureUnit unit);

  static PressureUnit toPressureUnit(int unit);

  float readValue() const final override;

};


#endif //NALOGA1101_PRESSURESENSOR_H
