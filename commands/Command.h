#ifndef TETRIS_COMMAND_H
#define TETRIS_COMMAND_H

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif //TETRIS_COMMAND_H
