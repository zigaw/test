#include "Sensor.h"

Sensor::Sensor(int id, bool active) : id(id), active(active) {}

int Sensor::getId() const {
    return id;
}

bool Sensor::isActive() const {
    return active;
}

std::string Sensor:: toString() const{
    std::stringstream sensorData;
    sensorData << std::to_string(id) << ";" << std::to_string(active);
    return sensorData.str();
}

float Sensor:: readValue() const{
    return rand();
}
