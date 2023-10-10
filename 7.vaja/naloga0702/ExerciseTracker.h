#ifndef NALOGA0401_EXERCISETRACKER_H
#define NALOGA0401_EXERCISETRACKER_H

#include "StrengthExercise.h"
#include "Person.h"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

class ExerciseTracker {
private:
    Difficulty difficulty;
    std::vector<Exercise*> exercises;
    Person *trainee;
public:
    ExerciseTracker(Person *);

    virtual ~ExerciseTracker();

    void addExercise(Exercise *newExercise);

    std::string toString();

    std::vector<Exercise*> getExercisesBetweenDurations(Time from, Time to);

};


#endif //NALOGA0401_EXERCISETRACKER_H
