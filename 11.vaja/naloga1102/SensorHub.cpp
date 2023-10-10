#include "SensorHub.h"


void SensorHub:: readValues() const{
    for (int i = 0; i < sensors.size(); ++i) {
        if(sensors[i]->isActive()){
            std::cout << sensors[i]->toString() << " value: " << std::to_string(sensors[i]->readValue()) << std::endl;

        }
    }
}

void SensorHub:: addSensor(std::shared_ptr<Sensor> sensor){
    int newId = sensor->getId();
        for (int i = 0; i < sensors.size(); ++i) {
            if (sensors[i]->getId() == newId) {
                throw DuplicatedSensorIdExeption(newId);
            }
        }
        sensors.push_back(sensor);
}


void SensorHub::saveSensorsToFile() const {
    std::ofstream outputFile("outSensorData.txt");
    if (outputFile.is_open()) {
        for (const auto& sensor : sensors) {
            if(!sensor->isActive()){
                Log(LogType::WARN) << "Sensor status is set to inactive!\n";
            }
            outputFile << sensor->toString() << std::endl;
        }
        outputFile.close();
        std::cout << "Sensor data saved to outSensorData.txt" << std::endl;
    } else {
        throw FileAccessException("outSensorData.txt");
    }
}

void SensorHub::loadSensorsFromFile(const std::string fileName) {
    std::ifstream inputFile(fileName);
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
            if (inputString.peek() == ';') {
                float latitude, longitude;
                std::getline(inputString, field, ';');
                latitude = std::stof(field);
                std::getline(inputString, field, ';');
                longitude = std::stof(field);
                sensor = std::make_shared<PressureSensorP12>(id, active, unit, latitude, longitude);

            } else {
                sensor = std::make_shared<PressureSensor>(id, active, unit);
            }
            try {
                if(!sensor->isActive()){
                    Log(LogType::WARN) << "Sensor status is set to inactive!\n";
                }
                this->addSensor(sensor);
            }catch(DuplicatedSensorIdExeption){
               std::cout<< DuplicatedSensorIdExeption(sensor->getId()).what();
                Log(LogType::ERROR) << "Sensor with id 12 already exists!\n";
            }
        }
        inputFile.close();
        std::cout << "Sensors loaded from " << fileName << std::endl;
    }else{
        throw FileAccessException(fileName);
    }
}
