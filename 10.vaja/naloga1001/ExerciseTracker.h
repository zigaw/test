#ifndef NALOGA0401_EXERCISETRACKER_H
#define NALOGA0401_EXERCISETRACKER_H

#include "PrintIfStrengthExercise.h"
#include "WeightLog.h"

class ExerciseTracker {
private:
    Difficulty difficulty;
    std::vector<Exercise*> exercises;
    Person *trainee;
    std::vector<WeightLog*>weights;
public:
    ExerciseTracker(Person *);

    virtual ~ExerciseTracker();

    void addExercise(Exercise *newExercise);

    std::string toString();

    std::vector<Exercise*> getExercisesBetweenDurations(Time from, Time to);

    void sort(bool (*c)(Exercise*, Exercise*));

    Exercise* find(bool (*c)(Exercise*));

    void printExercises(PrintIfStrengthExercise i);

    void add(float weight, Date date);

    WeightLog* find(bool (*c)(WeightLog*));

};


#endif //NALOGA0401_EXERCISETRACKER_H
