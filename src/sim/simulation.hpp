#pragma once
#include "drawables/body.hpp"
#include <vector>

class Simulation{
    private:
    std::vector<Body> _bodies{};
    void processPhysics();

    public:
    Simulation();
    ~Simulation();

    void processSimFrame();
};
