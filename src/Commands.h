#pragma once
#include <vector>

class Commands
{
    public:
        Commands(int commandsCount);
        int current();
        void set(int index);
        void clear();

    private:
        int commandsCount;
        int currentCommandIndex = 0;
};
