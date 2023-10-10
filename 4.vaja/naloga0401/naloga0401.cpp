#include "ExerciseTracker.h"

using namespace std;

int main() {


    Exercise exercise1("swimming", Time(2, 13, 0), 200, 600, Date(20, 10, 2000), Difficulty::Hard);
    Exercise exercise2("cycling", Time(1, 0, 0), 140, 300, Date(20, 11, 2010), Difficulty::Normal);
    Exercise exercise3("bench-press", Time(16, 30, 0), 120, 230, Date(20, 10, 2013), Difficulty::Easy);

    Exercise exercise4("running", Time(0, 20, 0), 150, 333, Date(20, 10, 2000), Difficulty::Easy);
    Exercise exercise5("pull-ups", Time(0, 35, 0), 120, 113, Date(20, 10, 2000), Difficulty::Normal);
    Exercise exercise6("squat", Time(1, 20, 0), 164, 440, Date(20, 10, 2000), Difficulty::Hard);

    Person *person1 = new Person("Chris", "Bumstead", 28, 119.5, 185);

    ExerciseTracker *tracker1 = new ExerciseTracker(person1);
    ExerciseTracker *tracker2 = new ExerciseTracker(person1);

    tracker1->addExercise(exercise1);
    tracker1->addExercise(exercise2);
    tracker1->addExercise(exercise3);

    tracker2->addExercise(exercise4);
    tracker2->addExercise(exercise5);
    tracker2->addExercise(exercise6);

    cout << tracker1->toString();
    cout << tracker2->toString();
    Time time1(0, 0, 0);
    Time time2(15, 0, 0);
    vector<Exercise> tmp = tracker1->getExercisesBetweenDurations(time1, time2);
    cout << endl << endl << endl;
    for (int i = 0; i < tmp.size(); i++) {
        cout << tmp[i].toString();
    }

    delete person1;
    delete tracker1;
    delete tracker2;

    return 0;
}