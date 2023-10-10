
#include "PressureSensor.h"

PressureSensor::PressureSensor(int id, bool active, PressureUnit unit): Sensor(id,active),unit(unit) {}

 int PressureSensor::toInt(PressureUnit unit) {
    return static_cast<int>(unit);
}

 PressureUnit PressureSensor::toPressureUnit(int unit) {
    return static_cast<PressureUnit>(unit);
}

std::string PressureSensor::toString() const {
    std::stringstream pressuresensorData;
    pressuresensorData << Sensor::toString();
    pressuresensorData << ";" << std::to_string(toInt(unit));
    return pressuresensorData.str();
}

float PressureSensor::readValue() const {
    return rand();
}




