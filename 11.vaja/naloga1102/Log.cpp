#include "Log.h"

Log::Log(LogType type, std::experimental::source_location loc) {
    file.open(fileName, std::ios::app);

    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* currentTimeTM = std::localtime(&currentTimeT);

    char timeBuffer[20];
    std::strftime(timeBuffer, sizeof(timeBuffer), "%m/%d/%y %H:%M:%S", currentTimeTM);

    std::string line = std::string(timeBuffer) + ' ';
    line += logTypeToString(type) + " [" + loc.function_name() + "#" + std::to_string(loc.line()) + "] ";

    file << line;
}


Log::~Log() {
    if (file.is_open()) {
        file.close();
    }
}



std::string Log:: logTypeToString(LogType logType){
    switch (logType) {
        case LogType::DEBUG:
            return "DEBUG";
        case LogType::INFO:
            return "INFO";
        case LogType::WARN:
            return "WARN";
        case LogType::ERROR:
            return "ERROR";
        default:
            return "unknown type";
    }
}