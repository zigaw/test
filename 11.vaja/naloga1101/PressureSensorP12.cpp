#include "PressureSensorP12.h"

PressureSensorP12::PressureSensorP12(int id, bool active, PressureUnit unit, float latitude, float longitude): PressureSensor(id,active,unit){
    if (latitude > 90 || latitude < -90 || longitude > 180 || longitude < -180){
        throw InvalidLocationExeption(id);
    }else{
        this->longitude = longitude;
        this->latitude = latitude;
    }
}

std::string PressureSensorP12:: toString() const{
    std::stringstream pressureSensorP12Data;
    pressureSensorP12Data << PressureSensor::toString();
    pressureSensorP12Data << ";" <<std::to_string( latitude);
    pressureSensorP12Data << ";" <<std::to_string( longitude);
    return pressureSensorP12Data.str();
}

float PressureSensorP12::getLatitude() const {
    return latitude;
}

float PressureSensorP12::getLongitude() const {
    return longitude;
}
