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


void ExerciseTracker::sort(bool (*c)(Exercise*, Exercise*)) {
    for (int i = 0; i < exercises.size() - 1; i++) {
        for (int j = i + 1; j < exercises.size(); j++) {
            if (c(exercises[j], exercises[i])) {
                Exercise* temp = exercises[i];
                exercises[i] = exercises[j];
                exercises[j] = temp;
            }
        }
    }
}

Exercise* ExerciseTracker::find(bool (*c)(Exercise*)) {
    auto it = std::find_if(exercises.begin(), exercises.end(), c);
        return *it;
    }

void ExerciseTracker::printExercises(PrintIfStrengthExercise i) {
    std::for_each(exercises.begin(), exercises.end(), i);
}


void ExerciseTracker:: add(float weight, Date date){
    WeightLog* weightLog= new WeightLog (weight,date);
    weights.push_back(weightLog);
}


WeightLog* ExerciseTracker:: find(bool (*c)(WeightLog*)){
    auto it = std::find_if(weights.begin(), weights.end(), c);
    return *it;
}

