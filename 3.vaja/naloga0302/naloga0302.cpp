#include "TextUtility.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

    string string1 = "Abcdef12345!!";
    string string2 = "Lorem ipsum dolor sit magna aliqua ligula.";
    string string3 = "De232 ipsum dolor 14 heuas baliqua.";


    if (TextUtility::isAlphanumeric(string1) == true) {
        cout << "Text is alphanumeric!" << endl;
    } else {
        cout << "Text isn't alphanumeric!" << endl;
    }

    cout << TextUtility::difference(string2, string3) << endl;

    cout << TextUtility::replace("Lorem ipsum dolor sit amet consumetur sed sumeiusmod", "sum", "aaaaaaa") << endl;

    cout << TextUtility::countLowerCase(string3) << endl;

    cout << TextUtility::capitalize("lorem? ipsum! dolor consumetur. sed! sumeiusmod");


    return 0;
}