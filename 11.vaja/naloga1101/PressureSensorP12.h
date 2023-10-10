#include "PressureSensor.h"
#ifndef NALOGA1101_PRESSURESENSORP12_H
#define NALOGA1101_PRESSURESENSORP12_H


class PressureSensorP12 final :public PressureSensor{
private:
    float latitude;
    float longitude;
public:
    PressureSensorP12(int id, bool active, PressureUnit unit, float latitude, float longitude);

    float getLatitude() const;

    float getLongitude() const;

    std::string toString() const override;

};


#endif //NALOGA1101_PRESSURESENSORP12_H
