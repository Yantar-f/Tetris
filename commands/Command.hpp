#ifndef TETRIS_COMMAND_HPP
#define TETRIS_COMMAND_HPP

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif //TETRIS_COMMAND_HPP
