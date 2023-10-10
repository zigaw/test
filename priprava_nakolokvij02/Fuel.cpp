
#include "Fuel.h"

std::string Fuel::toString() const {
    std::stringstream fuelData;
    fuelData << date.toString() << ", ";
    fuelData << std::to_string(milage) << ", ";
    fuelData << std::to_string(fuelAmount) << ", ";
    fuelData << fuelType << ", ";
    fuelData << std::to_string(pricePerLiter) << std::endl;
    return fuelData.str();
}


std::vector<Fuel> Fuel::loadFromFile(const std::string &fileName)  {
    std::vector<Fuel> fuelV;
    std::fstream vhodnaDatoteka(fileName);
    if (!vhodnaDatoteka.is_open()) {
        throw FileNotFound(fileName);
    } else {
        while (!vhodnaDatoteka.eof()) {
            std::string line;
            std::getline(vhodnaDatoteka, line);
            std::istringstream lineStream(line);
            std::string date;
            std::getline(lineStream, date, ',');
            std::string milage;
            std::getline(lineStream, milage, ',');
            std::string fuelAmount;
            std::getline(lineStream, fuelAmount, ',');
            std::string fuelType;
            std::getline(lineStream, fuelType, ',');
            std::string pricePerLiter;
            std::getline(lineStream, pricePerLiter, ',');
            try {
                Fuel fuel(Date::getDateFromStrinf(date), std::stoul(milage), std::stof(fuelAmount), fuelType,
                          std::stof(pricePerLiter));
                fuelV.push_back(fuel);
            } catch (UnparsableDateException &e) {
                std::cout << e.what();
            }

        }
        vhodnaDatoteka.close();
        return fuelV;
    }

}

Fuel::Fuel(const Date &date, unsigned int milage, float fuelAmount, const std::string &fuelType, float pricePerLiter)
        : date(date), milage(milage), fuelAmount(fuelAmount), fuelType(fuelType), pricePerLiter(pricePerLiter) {}

void Fuel::sortRefulesvector(std::vector<Fuel> &refules, std::function<bool(Fuel fuel1, Fuel fuel2)> c) {
    std::sort(refules.begin(), refules.end(), c);
}

void Fuel::saveToFile( std::vector<Fuel> &refules, const std::string &fileName) {

    sortRefulesvector(refules, [](Fuel fuel1, Fuel fuel2) {
        if (fuel1.getMilage() < fuel2.getMilage()) {
            return true;
        }
        return false;
    });
    std::fstream vhodnaDatoteka(fileName);
    if(!vhodnaDatoteka.is_open()){
        throw FileNotFound(fileName);
    }else{
        for (int i = 0; i < refules.size(); ++i) {
            vhodnaDatoteka << refules[i].toString();
        }
    }
    vhodnaDatoteka.close();
}

const Date &Fuel::getDate() const {
    return date;
}

unsigned int Fuel::getMilage() const {
    return milage;
}

float Fuel::getFuelAmount() const {
    return fuelAmount;
}

const std::string &Fuel::getFuelType() const {
    return fuelType;
}

float Fuel::getPricePerLiter() const {
    return pricePerLiter;
}
