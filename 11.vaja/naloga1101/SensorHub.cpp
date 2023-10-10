#include "SensorHub.h"


void SensorHub::readValues() const {
    for (int i = 0; i < sensors.size(); ++i) {
        if (sensors[i]->isActive()) {
            std::cout << sensors[i]->toString() << " value: " << std::to_string(sensors[i]->readValue()) << std::endl;

        }
    }
}

void SensorHub::addSensor(std::shared_ptr<Sensor> sensor) {
    int newId = sensor->getId();
    for (int i = 0; i < sensors.size(); ++i) {
        if (sensors[i]->getId() == newId) {
            throw DuplicatedSensorIdExeption(newId);
        }
    }
    sensors.push_back(sensor);
}


void SensorHub::saveSensorsToFile(const std::string &filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto &sensor: sensors) {
            outputFile << sensor->toString() << std::endl;
        }
        outputFile.close();
        std::cout << "Sensor data saved to " << filename << std::endl;
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }
}

void SensorHub::loadSensorsFromFile(const std::string &filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        sensors.clear();
        std::string line;
        while (std::getline(inputFile, line)) {
            std::stringstream inputString(line);
            std::string field;
            std::getline(inputString, field, ';');
            int id = std::stoi(field);
            std::getline(inputString, field, ';');
            bool active = std::stoi(field);
            std::getline(inputString, field, ';');
            PressureUnit unit = PressureSensor::toPressureUnit(stoi(field));
            std::shared_ptr<Sensor> sensor;
            try {
                float latitude, longitude = -200;
                std::getline(inputString, field, ';');
                latitude = std::stof(field);
                std::getline(inputString, field, ';');
                longitude = std::stof(field);
                if (longitude > 0) {
                    sensor = std::make_shared<PressureSensorP12>(id, active, unit, latitude, longitude);

                } else {
                    sensor = std::make_shared<PressureSensor>(id, active, unit);

                }

                this->addSensor(sensor);
            } catch (DuplicatedSensorIdExeption &ex) {
                std::cout << ex.what();
            }
            catch (InvalidLocationExeption &ex) {
                std::cout << ex.what();
            }
        }
        inputFile.close();
        std::cout << "Sensors loaded from " << filename << std::endl;
    }
}