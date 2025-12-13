#pragma once
#include <tuple>
#include "Camera.h"

class Wall
{
    public:
        Wall(Camera* camera, long x, long y, long w, long h);
        std::tuple<long, long, long, long> getBaseParams();
        void draw();

    private:
        long x, y, w, h;
        Camera* camera;
};
