#include "CompetitiveExercise.h"

CompetitiveExercise::CompetitiveExercise(std::string name, Time duration, int avgHeartRate,
                                         int caloriesBurned, Date date,
                                         Difficulty difficulty, double points, Person *competitor) : points(points), competitor(competitor) {
    this->name = name;
    this->avgHeartRate = avgHeartRate;
    this->caloriesBurned = caloriesBurned;
    this->date = date;
    this->duration = duration;
    this->difficulty = difficulty;
}

std::string CompetitiveExercise::toString() {
    std::stringstream competitiveExerciseData;
    competitiveExerciseData << Exercise::toString();
    competitiveExerciseData << "Points: " << points << std::endl;
    competitiveExerciseData << "Competitor: " << competitor->toString() << std::endl;
    return competitiveExerciseData.str();
}



void CompetitiveExercise:: print(){
    std::cout << toString();
}