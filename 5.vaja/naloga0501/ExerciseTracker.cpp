#include "ExerciseTracker.h"

std::string ExerciseTracker::toString() {
    std::stringstream allExerciseTrackerData;
    allExerciseTrackerData << "Exercises: " << std::endl;
    for (int i = 0; i < exercises.size(); i++) {
        allExerciseTrackerData << exercises[i]->toString() << ", ";
    }
    allExerciseTrackerData << std::endl << "Trainee: " << trainee->toString() << std::endl;
    return allExerciseTrackerData.str();
}


void ExerciseTracker::addExercise(Exercise *newExercise) {
    exercises.push_back(newExercise);
}

ExerciseTracker::ExerciseTracker(Person *trainee) {

    this->trainee = trainee;
}

std::vector<Exercise*> ExerciseTracker::getExercisesBetweenDurations(Time from, Time to) {
    std::vector<Exercise*> correctExercises;
    for (int i = 0; i < exercises.size(); i++) {
        if (from.getInSeconds() < exercises[i]->getDuration().getInSeconds() &&
            exercises[i]->getDuration().getInSeconds() < to.getInSeconds()) {
            correctExercises.push_back(exercises[i]);
        }
    }
    return correctExercises;
}

ExerciseTracker::~ExerciseTracker() {
    for (int i = 0; i <exercises.size(); ++i) {
        delete exercises[i];
    }
}
