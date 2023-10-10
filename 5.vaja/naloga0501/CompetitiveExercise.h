#ifndef INC_5_VAJA_COMPETITIVEEXERCISE_H
#define INC_5_VAJA_COMPETITIVEEXERCISE_H
#include "Exercise.h"
class CompetitiveExercise : public Exercise {
private:
    double points;
    Person* competitor;
public:
   CompetitiveExercise(std::string name, Time duration, int avgHeartRate,
                       int caloriesBurned, Date date,
                       Difficulty difficulty, double points, Person *competitor);





    std::string toString() override;

    void print() override;





};

#endif //INC_5_VAJA_COMPETITIVEEXERCISE_H
