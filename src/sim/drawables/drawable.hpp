#pragma once
#include <glm/vec3.hpp>

class Drawable{
    private:
    // Variables for vertex buffers etc


    protected:
    double scale = 1;
    glm::vec3 position{};

    public:
    Drawable();
    ~Drawable();

    void Draw();
};
