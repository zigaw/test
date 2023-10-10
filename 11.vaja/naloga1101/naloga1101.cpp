#include "SensorHub.h"

using namespace std;

int InvalidLocationExeption::counterOfExceprions = 0;

int main() {



    SensorHub sensorHub;
    sensorHub.loadSensorsFromFile("sensorData.txt");

    sensorHub.readValues();
    cout << "---------------" << endl;

    PressureSensor sensor(12, true, PressureUnit::PSI);
    try {
        sensorHub.addSensor(make_shared<PressureSensor>(sensor));
    } catch (DuplicatedSensorIdExeption& dupEx) {
        cout << dupEx.what();
    }

    int tempId;

    PressureSensor sensor2(21, true, PressureUnit::PSI);

    PressureSensorP12 sensor3(1, false, PressureUnit::PA, 20, 0.244);
    PressureSensor sensor4(31, false, PressureUnit::PA);

    try {

        PressureSensorP12 sensor5(1, false, PressureUnit::PA, 200, 0.244);
    } catch (InvalidLocationExeption ex) {
        cout << ex.what();
    }

    //PressureSensorP12 sensor6(56, false, PressureUnit::PA, 200, 0.244);

    /*
    sensorHub.addSensor(make_shared<PressureSensor>(sensor2));
    sensorHub.addSensor(make_shared<PressureSensorP12>(sensor3));
    sensorHub.addSensor(make_shared<PressureSensor>(sensor4));
    sensorHub.addSensor(make_shared<PressureSensorP12>(sensor5));
    sensorHub.addSensor(make_shared<PressureSensorP12>(sensor6));
*/
    sensorHub.readValues();

    sensorHub.saveSensorsToFile("outSensorData.txt");

    return 0;
}
