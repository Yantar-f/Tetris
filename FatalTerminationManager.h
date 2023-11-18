//
// Created by Yantar on 18/11/2023.
//

#ifndef TETRIS_FATALTERMINATIONMANAGER_H
#define TETRIS_FATALTERMINATIONMANAGER_H

#pragma once
#include <string>

class FatalTerminationManager {
public:
    static void terminateApp(const std::string& message, int statusCode);
    static void terminateApp(int statusCode);
};


#endif //TETRIS_FATALTERMINATIONMANAGER_H
