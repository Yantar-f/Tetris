#ifndef TETRIS_STATESTACK_H
#define TETRIS_STATESTACK_H

#include <memory>
#include <vector>
#include <functional>
#include <unordered_map>
#include "states/State.h"
#include "CommonDefinitions.h"
#include "StateName.h"
#include "Commands/Command.h"
#include "Log/Logger.h"
#include "Context.h"

class State;

class StateStack {
public:
    explicit StateStack(Context&);
    void handleEvent(sf::Event);
    void update(TimePointMs);
    void draw();
    bool isEmpty() const;

    template<typename StateToCreate>
    void registerState(StateName);

    void pushState(StateName);
    void popState();
    void clearStates();

private:
    void executePendingCommands();

private:
    Context& context;
    std::vector<std::unique_ptr<State>> stack;
    std::vector<std::unique_ptr<Command>> pendingCommands;
    std::unordered_map<StateName, std::function<std::unique_ptr<State>()>> stateFactory;
};

template<typename StateToCreate>
void StateStack::registerState(StateName stateName) {
    LOG_INFO(std::string("Registering state: id = ").append(std::to_string(stateName)));
    stateFactory[stateName] = [this] () { return std::unique_ptr<State> (new StateToCreate(*this, context));};
}

#endif //TETRIS_STATESTACK_H
