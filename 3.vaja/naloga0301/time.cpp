#include "Time.h"
#include <iostream>
#include <string>
#include <sstream>

Time::Time(unsigned int constructorHours, unsigned int constructorMinutes, unsigned int constructorSeconds) {
    if (isTimeValid(constructorHours, constructorMinutes, constructorSeconds)) {
        hours = constructorHours;
        minutes = constructorMinutes;
        seconds = constructorSeconds;
    } else {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
}

string Time::toString() {
    stringstream completeTime;
    if (hours < 10) {
        completeTime << "0" << to_string(hours) << ":";
    } else {
        completeTime << to_string(hours) << ":";
    }
    if (minutes < 10) {
        completeTime << "0" << to_string(minutes) << ":";
    } else {
        completeTime << to_string(minutes) << ":";
    }
    if (seconds < 10) {
        completeTime << "0" << to_string(seconds);
    } else {
        completeTime << to_string(seconds);
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

Time Time::parse(string &time) {
    stringstream stringHours;
    stringstream stringMinutes;
    stringstream stringSeconds;
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

int Time::getHours() {
    return hours;
}

string Time::toStringGmt() {
    unsigned int gmtHours;
    gmtHours = hours;
    if (gmtHours == 0) {
        gmtHours = 23;
    } else {
        gmtHours = gmtHours - 1;
    }
    stringstream stringGmtHours;
    if (gmtHours < 10) {
        stringGmtHours << "0" << to_string(gmtHours) << ":";
    } else {
        stringGmtHours << to_string(gmtHours) << ":";
    }
    if (minutes < 10) {
        stringGmtHours << "0" << to_string(minutes) << ":";
    } else {
        stringGmtHours << to_string(minutes) << ":";
    }
    if (seconds < 10) {
        stringGmtHours << "0" << to_string(seconds);
    } else {
        stringGmtHours << to_string(seconds);
    }
    stringGmtHours << " Gmt";
    return stringGmtHours.str();
}