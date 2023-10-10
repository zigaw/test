#include "StrengthExercise.h"
#include "ExerciseTracker.h"
#include "CompetitiveExercise.h"
using namespace std;

int main() {

    Person *person1 = new Person("Chris", "Bumstead", 28, 120, 190);

    ExerciseTracker exerciseTracker1(person1);

    Exercise *exercise1 = new Exercise("jumping", Time(2, 0, 0), 140, 500, Date(20, 1, 2023), Difficulty::Hard);
    Exercise *exercise2 = new Exercise("running", Time(1, 0, 0), 160, 100, Date(21, 2, 2020), Difficulty::Normal);
    Exercise *exercise3 = new Exercise("swimming", Time(3, 0, 0), 120, 600, Date(23, 2, 2021), Difficulty::Easy);

    StrengthExercise *strengthExercise1 = new StrengthExercise("dead-lift",Time(1, 30, 0),130, 600, Date(20, 1, 2023), Difficulty::Hard, 100, 3, 8, MuscleGroup::Back);
    StrengthExercise *strengthExercise2 = new StrengthExercise("squat",Time(0,50,0), 160, 450,Date(21, 2, 2020), Difficulty::Normal, 150, 2,4, MuscleGroup::Legs);

    CompetitiveExercise competitiveExercise1("running",Time(0,4,0),125,200,Date(23, 2, 2021),Difficulty::Hard,6.9,person1);

    exerciseTracker1.addExercise(exercise1);
    exerciseTracker1.addExercise(exercise2);
    exerciseTracker1.addExercise(exercise3);
    exerciseTracker1.addExercise(strengthExercise1);
    exerciseTracker1.addExercise(strengthExercise2);

    exercise1->print();
    cout<< endl;
    strengthExercise2->print();

    cout << endl << exerciseTracker1.toString() << endl;
    competitiveExercise1.print();

    delete person1;
    return 0;
}