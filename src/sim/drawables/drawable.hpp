#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include "utils.h"

class Drawable{
    private:
    // Variables for vertex buffers etc
    unsigned int vertexBufferID;
    unsigned int indexBufferID;
    unsigned int indexArrayID;
    static const unsigned int NUM_VERTICES = 64;

    float vertexData[NUM_VERTICES * 2];
    int indexData[NUM_VERTICES * 3];

    protected:
    double scale = 1;
    glm::vec3 position{};

    public:
    Drawable();
    ~Drawable();

    void generateCircleVertexBuffer(int numVertices);
    void generateCircleIndexBuffer(int numVertices);
    void createIndexArrays();

    void Draw();
};
