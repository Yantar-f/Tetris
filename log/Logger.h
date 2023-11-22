#ifndef TETRIS_LOGGER_H
#define TETRIS_LOGGER_H

#include <string>

class Logger {
public:
    enum Level {
        INFO,
        WARN,
        ERROR,
        FATAL
    };

public:
    static void log(Level, const char* file, int line, const std::string& message);


private:
    inline static const std::string logLevelMap[] = {"INFO", "WARN", "ERROR", "FATAL"};
};

#define LOG_INFO(message) Logger::log(Logger::Level::INFO, __FILE_NAME__, __LINE__, message)
#define LOG_WARN(message) Logger::log(Logger::Level::WARN, __FILE_NAME__, __LINE__, message)
#define LOG_ERROR(message) Logger::log(Logger::Level::ERROR, __FILE_NAME__, __LINE__, message)
#define LOG_FATAL(message) Logger::log(Logger::Level::FATAL, __FILE_NAME__, __LINE__, message)

#endif //TETRIS_LOGGER_H
