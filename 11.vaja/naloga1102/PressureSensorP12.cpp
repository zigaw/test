#include "PressureSensorP12.h"

PressureSensorP12::PressureSensorP12(int id, bool active, PressureUnit unit, float latitude, float longitude): PressureSensor(id,active,unit),latitude(latitude),longitude(longitude){}

std::string PressureSensorP12:: toString() const{
    std::stringstream pressureSensorP12Data;
    pressureSensorP12Data << PressureSensor::toString();
    pressureSensorP12Data << ";" <<std::to_string( latitude);
    pressureSensorP12Data << ";" <<std::to_string( longitude);
    return pressureSensorP12Data.str();
}