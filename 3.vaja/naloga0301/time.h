#ifndef TIME_H
#define TIME_H
using namespace std;

#include <string>

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

    string toString();

    int getHours();

    string toStringGmt();

    static bool isTimeValid(unsigned int hours, unsigned int minutes, unsigned int seconds);

    static Time parse(string &time);

};


#endif // TIME_H