#ifndef TASK0401_DATE_H
#define TASK0401_DATE_H
#include "iostream"
#include "string"

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    Date(unsigned int day, unsigned int month, unsigned int year);

    unsigned int getDay() const;
    void setDay(unsigned int day);

    unsigned int getMonth() const;
    void setMonth(unsigned int month);

    unsigned int getYear() const;
    void setYear(unsigned int year);

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream &out, const Date &date);

    Date& operator++();

    bool operator==(const Date& other) const;

    Date operator++(int dummy) ;

};



#endif //TASK0401_DATE_H
