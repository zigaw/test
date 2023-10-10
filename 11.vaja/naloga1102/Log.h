#include "LogType.h"
#include "iostream"
#include "fstream"
#include "string"
#include "chrono"
#include "exception"
#include "string_view"
#include "experimental/source_location"
#ifndef NALOGA1102_LOG_H
#define NALOGA1102_LOG_H


class Log {
private:
    std::ofstream file;
    std::string fileName = "log.txt";
public:

    Log(LogType type, std::experimental::source_location loc = std::experimental::source_location::current());

    ~Log();

    template<typename T>
    Log& operator<<(const T &msg){
        if (file.is_open()){
            file << msg;
        }
        return *this;
    }

    static std::string logTypeToString(LogType logType);
};


#endif //NALOGA1102_LOG_H
