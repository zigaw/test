#include "PressureSensorP12.h"
#include "DuplicatedSensorIdExeption.h"
#include "FileAccessException.h"
#include "Log.h"
#ifndef NALOGA1101_SENSORHUB_H
#define NALOGA1101_SENSORHUB_H


class SensorHub {
private:
    std::vector<std::shared_ptr<Sensor>> sensors;
public:
    SensorHub() = default;

    void readValues() const;

    void addSensor(std::shared_ptr<Sensor> sensor);

    void saveSensorsToFile() const;

    void loadSensorsFromFile(const std::string filename);

};


#endif //NALOGA1101_SENSORHUB_H
