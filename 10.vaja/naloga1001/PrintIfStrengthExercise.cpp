#include "PrintIfStrengthExercise.h"

void PrintIfStrengthExercise:: operator()(Exercise* exercise) {
    if (dynamic_cast<StrengthExercise*>(exercise) != nullptr) {
        std::cout << exercise->toString() << std::endl;
    }
}
