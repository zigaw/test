#include "WeightLog.h"

WeightLog::WeightLog(float weight, const Date &date) : weight(weight), date(date) {}

float WeightLog::getWeight() const {
    return weight;
}

const Date &WeightLog::getDate() const {
    return date;
}

