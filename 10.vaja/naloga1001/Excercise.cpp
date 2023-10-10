#include "Exercise.h"

Exercise::Exercise(std::string constructorName, Time constructorDuration, int constructorAvgHeartRate,
                   int constructorCaloriesBurned,Date date, Difficulty difficulty) : difficulty(difficulty), date(date) {
    name = constructorName;
    duration = constructorDuration;
    avgHeartRate = constructorAvgHeartRate;
    caloriesBurned = constructorCaloriesBurned;

}

Exercise::Exercise() : name(""), duration(0, 0, 0), avgHeartRate(0), caloriesBurned(0), date(0,0,0) , difficulty() {
}

Exercise::Exercise(const Exercise &exercise) : name(exercise.name), duration(exercise.duration),
                                               avgHeartRate(exercise.avgHeartRate),
                                               caloriesBurned(exercise.caloriesBurned),date(exercise.date),
                                               difficulty(exercise.difficulty)
                                               {
}

Exercise::~Exercise() {};

std::string Exercise::getName() {
    return name;
}

Time Exercise::getDuration() {
    return duration;
}

int Exercise::getCaloriesBurned() {
    return caloriesBurned;
}

int Exercise::getAvgHeartRate() {
    return avgHeartRate;
}

Difficulty Exercise::getDifficulty() {
    return difficulty;
}

void Exercise::setDuration(Time setDuration) {
    this->duration = setDuration;
}

int Exercise::setCaloriesBurned(int setCalories) {
    this->caloriesBurned = setCalories;
}

Exercise *Exercise::isMoreIntense(Exercise *second) {

    if (this->caloriesBurned > second->caloriesBurned) {
        return this;
    } else {
        return second;
    }
};

std::string Exercise::toString() {
    std::stringstream allExerciseData;
    allExerciseData << "Name:" << name << std::endl;
    allExerciseData << "Duration:" << duration.toString() << std::endl;
    allExerciseData << "Average heart rate:" << std::to_string(avgHeartRate) << std::endl;
    allExerciseData << "Calories burned:" << std::to_string(caloriesBurned) << std::endl;
    allExerciseData << "Date:" << date.toString() << std::endl;
    allExerciseData << "Difficulty:" << enumToString(difficulty) << std::endl;
    return allExerciseData.str();
}

void Exercise::print() {
    std::cout << toString();
}

std::string Exercise::enumToString(Difficulty difficulty) {
    switch (difficulty) {
        case Difficulty::Easy:
            return "Easy";
        case Difficulty::Normal:
            return "Normal";
        case Difficulty::Hard:
            return "Hard";
    }
}