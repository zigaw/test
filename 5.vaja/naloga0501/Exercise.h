#ifndef EXERCISE_H
#define EXERCISE_H

#include "Difficulty.h"
#include "Time.h"
#include <vector>
#include <sstream>
#include <iostream>
#include "Person.h"
#include "Date.h"

class Exercise {
protected:
    Date date;
    Time duration = Time(0, 0, 0);
    Difficulty difficulty;
    int caloriesBurned;
    std::string name;
    int avgHeartRate;
public:
    Exercise(std::string constructorName, Time constructorDuration, int constructorAvgHeartRate,
             int constructorCaloriesBurned, Date date, Difficulty difficulty);

    std::string getName();

    Time getDuration();

    int getAvgHeartRate();

    int getCaloriesBurned();

    int setCaloriesBurned(int caloriesBurned);

    void setDuration(Time duration);

    virtual std::string toString();

    virtual void print();

    Exercise();

    Exercise(const Exercise &exercise);

    ~Exercise();

    std::string enumToString(Difficulty difficulty);

    Exercise *isMoreIntense(Exercise *second);
};

#endif // EXERCISE_H
