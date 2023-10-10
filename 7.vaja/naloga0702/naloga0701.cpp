#include "VectorUtil.h"
#include "StrengthExercise.h"
#include "ExerciseTracker.h"
#include "CompetitiveExercise.h"

using namespace std;

int main() {
    using namespace std::string_literals;
    system(("chcp "s + std::to_string(65001)).c_str());

    vector<Point> list;
    cout << "Default generator of 3 objects" << endl;
    fillDefault(list, 3);
    print(list);

    vector<float> list2 = {1.1f, 1.2f, 1.3f};
    vector<float> list3 = reverse(list2);
    cout << "Reverse:" << endl;
    print(list3);

    vector<vector<float>> listOfLists = {list2, list3};
    cout << "Merge vectors:" << endl;
    print(mergeVectors(listOfLists));

    vector<int> listInt;
    cout << "Default generator of 3 objects" << endl;
    fillDefault(listInt, 3);
    print(listInt);

    vector<int> listGreen;
    cout << "print 3 green objects" << endl;
    fillDefault(listGreen, 3);
    printColor(listGreen);

    vector<int> listRed;
    cout << "print 3 red objects" << endl;
    fillDefault(listRed, 3);
    printColor(listRed,ColorCode::Red);

   vector<int> list6 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
     cout << "slice remainder is 0" << endl;
       print(slice(list6,6));

    cout << "slice remainder is 3" << endl;
    print(slice(list6,5));

    vector<int> list7 = {1,2,2,4,5,6,2,8,9,10,10,12,12,12,13,14,15,16,12,17,18};
    cout << "remove duplicates" << endl;
    print(removeDuplicates(list7));

    vector<float> list9 = {{1.1f, 1.2f, 1.3f, 1.4f, 1.5f, 1.6f, 1.7f, 1.8f, 1.9f, 2.0f, 2.1f, 2.2f, 2.3f, 2.4f, 2.5f, 2.6f, 2.7f, 2.8f, 2.9f, 3.0f}};
    cout << "sort by first decimal part" << endl;
    print(sortByDecimal(list9));


    vector<int> list10 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> list11 = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    vector<int> list12 = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    vector<int> list13 = {31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
    vector<int> list14 = {41, 42, 43, 44, 45, 46, 47, 48, 49, 50};

    vector<vector<int>> listOfLists2 = {list10, list11,list12,list13,list14};
    cout << "remove multipliers of 5 from listOfLists2" << endl;
    print(removeMultipliersOfN(listOfLists2,5));


    vector<vector<int>> listOfLists3 = {list10, list11,list12,list13,list14};
    cout << "remove multipliers of 4 from listOfLists2" << endl;
    print(removeMultipliersOfN(listOfLists2,4));



    Person *person1 = new Person("Chris", "Bumstead", 28, 120, 190);

    ExerciseTracker exerciseTracker1(person1);

    Exercise *exercise1 = new Exercise("jumping", Time(2, 0, 0), 140, 500, Date(20, 1, 2023), Difficulty::Hard);
    Exercise *exercise2 = new Exercise("running", Time(1, 0, 0), 160, 100, Date(21, 2, 2020), Difficulty::Normal);
    Exercise *exercise3 = new Exercise("swimming", Time(3, 0, 0), 120, 600, Date(23, 2, 2021), Difficulty::Easy);

    StrengthExercise *strengthExercise1 = new StrengthExercise("dead-lift",Time(1, 30, 0),130, 600, Date(20, 1, 2023), Difficulty::Hard, 100, 3, 8, MuscleGroup::Back);
    StrengthExercise *strengthExercise2 = new StrengthExercise("squat",Time(0,50,0), 160, 450,Date(21, 2, 2020), Difficulty::Normal, 150, 2,4, MuscleGroup::Legs);

    CompetitiveExercise *competitiveExercise1 = new CompetitiveExercise("running",Time(0,4,0),125,200,Date(23, 2, 2021),Difficulty::Hard,6.9,person1);


    exerciseTracker1.addExercise(exercise1);
    exerciseTracker1.addExercise(exercise2);
    exerciseTracker1.addExercise(exercise3);
    exerciseTracker1.addExercise(strengthExercise1);
    exerciseTracker1.addExercise(strengthExercise2);

    vector<Exercise*> exercises = {strengthExercise1, strengthExercise2, exercise1, competitiveExercise1};


    cout << "countType" << endl;
    cout<< countType<Exercise, StrengthExercise>(exercises) << endl;

    cout << "countType" << endl;
    cout<< countType<>(exercises) << endl;

    cout << "countType" << endl;
    cout<< countType<Exercise, CompetitiveExercise>(exercises) << endl;














    delete person1;

    return 0;


}