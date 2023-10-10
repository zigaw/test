#include "TextUtility.h"
#include <string>
#include <sstream>

using namespace std;

TextUtility::TextUtility() = default;

bool TextUtility::isAlphanumeric(const string &str) {
    for (char character: str) {
        if (!isalnum(character)) {
            return false;
        }
    }
    return true;
}

string TextUtility::difference(const string &str1, const string &str2) {
    stringstream result;
    unsigned int len1 = str1.length();
    unsigned int len2 = str2.length();
    unsigned int maxLen = max(len1, len2);
    for (int i = 0; i < maxLen; i++) {
        if (i < len1 && i < len2) {
            if (str1[i] == str2[i]) {
                result << str2[i];
            } else {
                result << "-";
            }
        } else {
            result << "-";
        }
    }
    return result.str();
}

string TextUtility::replace(const string &str, const string &searchStr, const string &replaceStr) {
    string result;
    int i = 0;

    while (i < str.length()) {
        if (str.substr(i, searchStr.length()) == searchStr) {
            result += replaceStr;
            i += searchStr.length();
        } else {
            result += str[i];
            i++;
        }
    }

    return result;
}

unsigned int TextUtility::countLowerCase(string &str) {
    int count = 0;
    for (char charachter: str) {
        if (std::islower(charachter)) {
            count++;
        }
    }
    return count;
}

std::string TextUtility::capitalize(const std::string &str) {
    std::string result = str;
    result[0] = toupper(result[0]);
    for (size_t i = 0; i < result.length() - 2; i++) {
        if (result[i] == '.' || result[i] == '!' || result[i] == '?') {
            result[i + 2] = toupper(result[i + 2]);
        }
    }
    return result;
}









