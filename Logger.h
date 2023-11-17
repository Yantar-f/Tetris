//
// Created by Yantar on 17/11/2023.
//

#ifndef TETRIS_LOGGER_H
#define TETRIS_LOGGER_H


#include <string>

class Logger {
private:
    std::string actor_name;
    std::string info_prefix;
    std::string warn_prefix;
    std::string error_prefix;
    std::string fatal_prefix;
public:
    explicit Logger(const char* actor_name);
    void log_info(const char* message);
    void log_warn(const char* message);
    void log_error(const char* message);
    void log_fatal(const char* message);
private:
    void print(std::string& log_prefix, const char* message);
};


#endif //TETRIS_LOGGER_H
