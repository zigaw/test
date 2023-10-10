#ifndef EXERCISE_H
#define EXERCISE_H
#include <string>
#include "Difficulty.h"
#include "Time.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Exercise.h"
#include "Person.h"
#include "Time.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>

class Exercise {
private:
    Date date;
   std:: string name;
    Time duration = Time(0,0,0);
    Difficulty difficulty;
    int avgHeartRate;
    int caloriesBurned;

public:
    Exercise(std::string constructorName, Time constructorDuration, int constructorAvgHeartRate, int constructorCaloriesBurned, Date date, Difficulty difficulty);
    std::string getName();
    Time getDuration();
    int getAvgHeartRate();
    int getCaloriesBurned();
    int setCaloriesBurned(int caloriesBurned);
    void setDuration(Time duration);
    std::string toString();
    void print();
    Exercise();
    Exercise(const Exercise &exercise);
    ~Exercise();
    std::string enumToString(Difficulty difficulty);
    Exercise* isMoreIntense(Exercise* second);
};
#endif // EXERCISE_H
