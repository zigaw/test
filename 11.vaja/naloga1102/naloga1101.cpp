#include "SensorHub.h"

using namespace std;

int main() {

    SensorHub sensorHub;


    Log(LogType::INFO) << "This is additional message. We can also put multiple << and other types, not just strings e.g. " << 5 << "\n" ;


    try {
        sensorHub.loadSensorsFromFile("sensor_Data.txt");
    }catch(FileAccessException){
        cout << FileAccessException("sensor_Data.txt").what();
        Log(LogType::ERROR) << "Sensor_Data.txt does not exist!\n";
    }


    try {
        sensorHub.loadSensorsFromFile("sensorData.txt");
    }catch(FileAccessException){
        cout << FileAccessException("sensorData.txt").what();
        Log(LogType::ERROR) << "SensorData.txt does not exist!\n";
    }

    sensorHub.readValues();

    cout << "---------------" << endl;

    PressureSensor sensor(12, true, PressureUnit::PSI);
    try {
        sensorHub.addSensor(make_shared<PressureSensor>(sensor));
    } catch (DuplicatedSensorIdExeption) {
       cout<< DuplicatedSensorIdExeption(sensor.getId()).what();
        Log(LogType::ERROR) << "Sensor with id 12 already exists!\n";
    }

    PressureSensor sensor2(21, true, PressureUnit::PSI);
    PressureSensorP12 sensor3(2, true, PressureUnit::PSI, 12.222, 10.244);
    PressureSensor sensor4(31, false, PressureUnit::PA);
    if(!sensor4.isActive()){
        Log(LogType::WARN) << "Sensor status is set to inactive!\n";
    }
    PressureSensorP12 sensor5(1, false, PressureUnit::PA, 6.6, 0.244);
    PressureSensorP12 sensor6(7, false, PressureUnit::PSI, 8.6, 3.244);

    sensorHub.addSensor(make_shared<PressureSensor>(sensor2));
    sensorHub.addSensor(make_shared<PressureSensorP12>(sensor3));
    sensorHub.addSensor(make_shared<PressureSensor>(sensor4));
    sensorHub.addSensor(make_shared<PressureSensorP12>(sensor5));
    sensorHub.addSensor(make_shared<PressureSensorP12>(sensor6));

    sensorHub.readValues();

    cout << sensor3.toString() << endl;

    try {
        sensorHub.saveSensorsToFile();
    }catch(FileAccessException){
        cout << FileAccessException("outSensorData.txt").what();
        Log(LogType::ERROR) <<"outSensorData.txt does not exist!\n";
    }


    return 0;
}
