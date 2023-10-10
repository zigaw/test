#ifndef INC_5_VAJA_STRENGTHEXERCISE_H
#define INC_5_VAJA_STRENGTHEXERCISE_H

#include "Difficulty.h"
#include "MuscleGroup.h"
#include "Exercise.h"

class StrengthExercise : public Exercise {
private:
    float weight;
    MuscleGroup muscleGroup;
    unsigned int sets;
    unsigned int reps;
public:
    StrengthExercise(std::string name, Time duration, int avgHeartRate,
                     int caloriesBurned, Date date, Difficulty difficulty,
                     float weight, unsigned int sets, unsigned int reps, MuscleGroup muscleGroup);

    std::string toString() override;

    void print() override;

    void setWeight(float weight);

    void setSets(unsigned int sets);

    void setReps(unsigned int reps);

    float getWeight(float weight);

    unsigned int getSets(unsigned int sets);

    unsigned int getReps(unsigned int reps);

    std::string muscleGroupToString(MuscleGroup muscleGroup);
};


#endif //INC_5_VAJA_STRENGTHEXERCISE_H
