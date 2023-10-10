#include "Time.h"


Time::Time(unsigned int constructorHours, unsigned int constructorMinutes, unsigned int constructorSeconds) {
    if (isTimeValid(constructorHours, constructorMinutes, constructorSeconds) == true) {
        hours = constructorHours;
        minutes = constructorMinutes;
        seconds = constructorSeconds;
    } else {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
}

std::string Time::toString() {
    std::stringstream completeTime;
    if (hours < 10) {
        completeTime << "0" << std::to_string(hours) << ":";
    } else {
        completeTime << std::to_string(hours) << ":";
    }
    if (minutes < 10) {
        completeTime << "0" << std::to_string(minutes) << ":";
    } else {
        completeTime << std::to_string(minutes) << ":";
    }
    if (seconds < 10) {
        completeTime << "0" << std::to_string(seconds);
    } else {
        completeTime << std::to_string(seconds);
    }

    return completeTime.str();
}

bool Time::isTimeValid(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    if (hours >= MaxHours || minutes >= MaxMinutes || seconds >= MaxSeconds) {
        return false;
    } else {
        return true;
    }
}

Time Time::parse(std::string &time) {
    std::stringstream stringHours;
    std::stringstream stringMinutes;
    std::stringstream stringSeconds;
    unsigned int parseHours;
    unsigned int parseMinutes;
    unsigned int parseSeconds;
    stringHours << time.substr(0, 2);
    stringMinutes << time.substr(3, 2);
    stringSeconds << time.substr(6, 2);
    stringHours >> parseHours;
    stringMinutes >> parseMinutes;
    stringSeconds >> parseSeconds;
    return Time(parseHours, parseMinutes, parseSeconds);
}



int Time::getInSeconds() {

    return (hours*3600 + minutes*60 + seconds);

}