#ifndef TIME_H
#define TIME_H


#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Time {
private:
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    static const unsigned int MaxHours = 24;
    static const unsigned int MaxMinutes = 60;
    static const unsigned int MaxSeconds = 60;
public:
    Time(unsigned int construtorHours, unsigned int constructorMinutes, unsigned int constructorSeconds);

    std::string toString();

    static bool isTimeValid(unsigned int hours, unsigned int minutes, unsigned int seconds);

    static Time parse(std::string &time);

    int getInSeconds();

};


#endif // TIME_H