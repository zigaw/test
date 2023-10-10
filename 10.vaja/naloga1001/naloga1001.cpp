#include "StrengthExercise.h"
#include "ExerciseTracker.h"
#include "CompetitiveExercise.h"
using namespace std;

bool ascendingTime(Exercise* firstExercise, Exercise* secondExercise){
    if (firstExercise->getDuration().getInSeconds() < secondExercise->getDuration().getInSeconds()){
        return true;
    }
    return false;
}

bool ascendingDifficulty(Exercise* firstExercise, Exercise* secondExercise){
    if (firstExercise->getDifficulty() < secondExercise->getDifficulty()){
        return true;
    }
    return false;
}

bool isAerobicExercise(Exercise* exercise){
    if ( 120 <  exercise->getAvgHeartRate() && exercise->getAvgHeartRate() < 150){
        return true;
    }
    return false;
}


int main() {

    Person *person1 = new Person("Chris", "Bumstead", 28, 120, 190);

    ExerciseTracker tracker(person1);

    Exercise *exercise1 = new Exercise("jumping", Time(2, 0, 0), 140, 500, Date(20, 1, 2023), Difficulty::Hard);
    Exercise *exercise2 = new Exercise("running", Time(1, 0, 0), 160, 100, Date(21, 2, 2020), Difficulty::Normal);
    Exercise *exercise3 = new Exercise("swimming", Time(3, 0, 0), 120, 600, Date(23, 2, 2021), Difficulty::Easy);

    StrengthExercise *strengthExercise1 = new StrengthExercise("dead-lift",Time(1, 30, 0),130, 600, Date(20, 1, 2023), Difficulty::Hard, 100, 3, 8, MuscleGroup::Back);
    StrengthExercise *strengthExercise2 = new StrengthExercise("squat",Time(0,50,0), 160, 450,Date(21, 2, 2020), Difficulty::Normal, 150, 2,4, MuscleGroup::Legs);

    CompetitiveExercise competitiveExercise1("running",Time(0,4,0),125,200,Date(23, 2, 2021),Difficulty::Hard,6.9,person1);

    tracker.addExercise(exercise1);
    tracker.addExercise(exercise2);
    tracker.addExercise(exercise3);
    tracker.addExercise(strengthExercise1);
    tracker.addExercise(strengthExercise2);

    cout << "------------------------Ascending Time------------------------" << endl << endl;

    tracker.sort(ascendingTime);
    std::cout << tracker.toString();

    cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;
    cout << "------------------------Ascending Difficulty------------------------" << endl << endl;

    tracker.sort(ascendingDifficulty);
    std::cout << tracker.toString();

    cout << endl << endl << "--------------------------------------------------------------------" << endl << endl;

    Exercise* findAerobic = tracker.find(isAerobicExercise);
    if(findAerobic != nullptr)
        std::cout << findAerobic->toString();
    else
        std::cout << "no aerobic exercise";


    cout << endl << endl;
    cout << "--------------------PrintIfStrengthExercise----------------------------" << endl;

    PrintIfStrengthExercise strength;
    tracker.printExercises(strength);




    tracker.add(3,Date(20,2,2022));
    tracker.add(200,Date(20,2,2022));
    tracker.add(150,Date(20,2,2022));
    tracker.add(70,Date(20,2,2022));

    WeightLog* find100kg = tracker.find([](WeightLog* weights){
        if (weights->getWeight() > 100){
            return true;
        }
    });
    if(find100kg) {
        std::cout << *find100kg;
    }else {
        std::cout << "no weight over 100kg";
    }

    delete person1;

    return 0;
}