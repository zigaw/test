#include "Date.h"
#include "vector"
#include "FileNotFound.h"
#include "fstream"
#include "algorithm"
#include <cstdarg>
#include "functional"
#ifndef PRIPRAVA_NAKOLOKVIJ02_FUEL_H
#define PRIPRAVA_NAKOLOKVIJ02_FUEL_H


class Fuel {
private:
    Date date;
    unsigned int milage;
    float fuelAmount;
    std::string fuelType;
    float pricePerLiter;
public:
    Fuel(const Date &date, unsigned int milage, float fuelAmount, const std::string &fuelType, float pricePerLiter);

    std::string toString() const;

    static std::vector<Fuel> loadFromFile(const std::string &fileName) ;

    void static sortRefulesvector(std::vector<Fuel> &refules, std::function<bool(Fuel fuel1, Fuel fuel2)> c);

    void static saveToFile( std::vector<Fuel> & refules, const std ::string & fileName);

    const Date &getDate() const;

    unsigned int getMilage() const;

    float getFuelAmount() const;

    const std::string &getFuelType() const;

    float getPricePerLiter() const;

    template<typename... T>
    static float avgPricePerLiter(int num, T...args){
        float avgPrice= 0;
        std::vector<float>list = {args...};
        for (int i = 0; i < num; ++i) {
            avgPrice+= list[i];
        }
        return avgPrice / num;
    }
};


#endif //PRIPRAVA_NAKOLOKVIJ02_FUEL_H
