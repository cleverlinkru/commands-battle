#include "Commands.h"

Commands::Commands(int commandsCount)
{
    if (commandsCount < 1) {
        return;
    }

    this->commandsCount = commandsCount;
}

int Commands::current()
{
    return this->currentCommandIndex;
}

void Commands::set(int index)
{
    if (index < 1 || index > commandsCount) {
        return;
    }

    currentCommandIndex = index;
}

void Commands::clear()
{
    this->currentCommandIndex = 0;
}
