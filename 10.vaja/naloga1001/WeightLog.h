#include "Date.h"
#ifndef NALOGA1001_WEIGHTLOG_H
#define NALOGA1001_WEIGHTLOG_H


class WeightLog {
private:
    float weight;
    Date date;
public:
    WeightLog(float weight, const Date &date);

    float getWeight() const;

    const Date &getDate() const;

    friend std::ostream &operator<<(std::ostream &out, const WeightLog &weightLog) {
        out <<  std::to_string(weightLog.getWeight());
        out << weightLog.getDate().toString();
        return out;
    }
};


#endif //NALOGA1001_WEIGHTLOG_H
