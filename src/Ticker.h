#pragma once
#include "Engine.h"

class Ticker
{
    public:
        static const int StatusPause = 1;
        static const int StatusStep = 2;
        static const int StatusPlay = 3;

        Ticker(Engine* engine);
        bool update();
        void buttonEventHandler(int event);

    private:
        Engine* engine;
        int status = StatusPause;
        bool needStep = false;

        void setStatus(int val);
};
