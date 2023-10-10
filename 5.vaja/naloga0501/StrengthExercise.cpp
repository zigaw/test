#include "StrengthExercise.h"

StrengthExercise::StrengthExercise(std::string name, Time duration, int avgHeartRate,
                                   int caloriesBurned, Date date, Difficulty difficulty,
                                   float weight, unsigned int sets, unsigned int reps, MuscleGroup muscleGroup) {
    this->name = name;
    this->avgHeartRate = avgHeartRate;
    this->caloriesBurned = caloriesBurned;
    this->date = date;
    this->duration = duration;
    this->weight = weight;
    this->difficulty = difficulty;
    this->sets = sets;
    this->reps = reps;
    this->muscleGroup = muscleGroup;

}


std::string StrengthExercise::toString() {
    std::stringstream stringStrengthExercise;
    stringStrengthExercise << Exercise::toString();
    stringStrengthExercise << "Sets: " << std::to_string(sets) << std::endl;
    stringStrengthExercise << "Reps: " << std::to_string(reps) << std::endl;
    stringStrengthExercise << "Muscle group: " << muscleGroupToString(muscleGroup) << std::endl;
    return stringStrengthExercise.str();
}


void StrengthExercise::print() {
    std::cout << toString();
}

void StrengthExercise::setWeight(float weight) {
    weight = weight;
}

void StrengthExercise::setSets(unsigned int sets) {
    sets = sets;
}

void StrengthExercise::setReps(unsigned int reps) {
    reps = reps;
}

float StrengthExercise::getWeight(float weight) {
    return weight;
}

unsigned int StrengthExercise::getSets(unsigned int sets) {
    return sets;
}

unsigned int StrengthExercise::getReps(unsigned int reps) {
    return reps;
}

std::string StrengthExercise::muscleGroupToString(MuscleGroup muscleGroup) {
    switch (muscleGroup) {
        case MuscleGroup::Legs:
            return "Legs";
        case MuscleGroup::Back:
            return "Back";
        case MuscleGroup::Arms:
            return "Arms";
    }
}
