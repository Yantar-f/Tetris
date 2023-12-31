#ifndef TETRIS_COMMONDEFINITIONS_HPP
#define TETRIS_COMMONDEFINITIONS_HPP

#include <chrono>

typedef std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds> TimePointMs;

#define TIME_POINT std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now())
#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600
#define DEFAULT_WINDOW_TITLE "Tetris"
#define DEFAULT_WINDOW_STYLE sf::Style::Close
#define DEFAULT_RESOURCE_PATH "../resources"

#endif //TETRIS_COMMONDEFINITIONS_HPP
