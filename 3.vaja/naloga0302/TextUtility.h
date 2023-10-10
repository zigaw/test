#ifndef TEXTUTILITY_H
#define TEXTUTILITY_H

#include <iostream>

using namespace std;

class TextUtility {
private:
    TextUtility();

public:
    static bool isAlphanumeric(const string &str);

    static std::string difference(const string &str1, const string &str2);

    static std::string replace(const string &str, const string &searchStr, const string &replaceStr);

    static unsigned int countLowerCase(string &str);

    static std::string capitalize(const std::string &str);
};

#endif // TEXTUTILITY_H