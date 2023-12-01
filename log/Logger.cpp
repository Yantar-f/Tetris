#include "Logger.hpp"

#include <iostream>
#include <ctime>

void Logger::log(Logger::Level level, const char* file, int line, const std::string& message) {
    time_t now = time(nullptr);
    tm* gmt = gmtime(&now);

    std::cout << "[" << logLevelMap[level] << "]:[" << file << ":" << line <<"]:["
              << 1900 + gmt->tm_year << "-"
              << gmt->tm_mon << "-"
              << gmt->tm_mday << "T"
              << gmt->tm_hour << ":"
              << gmt->tm_min << ":"
              << gmt->tm_sec
              << "] ---> " << message << std::endl;
}
