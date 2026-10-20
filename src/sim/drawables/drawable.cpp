#include "drawable.hpp"
#include <cmath>

Drawable::Drawable(){
    generateCircleVertexBuffer(NUM_VERTICES);
    generateCircleIndexBuffer(NUM_VERTICES);
    createIndexArrays();
}

Drawable::~Drawable(){
    glDeleteBuffers(1, &vertexBufferID);
    glDeleteBuffers(1, &indexBufferID);
}

void Drawable::generateCircleVertexBuffer(int numVertices){
    unsigned int size;
    const int SCALE = 100; // TEMP until I sort out MVP matricies
    const double PI = 3.141592;

    float angleIncrement = 2*PI / (numVertices - 1);
    for (int i = 0; i < numVertices - 1; i++){
        float angle = angleIncrement * i;

        float coordX = SCALE * cos(angle);
        float coordY = SCALE * sin(angle);
        vertexData[2 * i] = coordX;
        vertexData[2 * i + 1] = coordY;
    }
    size = sizeof(vertexData);

    glGenBuffers(1, &vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, size, &vertexData, GL_STATIC_DRAW);
}

void Drawable::generateCircleIndexBuffer(int numVertices){
    unsigned int size;
    const int SCALE = 100; // TEMP until I sort out MVP matricies
    const double PI = 3.141592;

    float angleIncrement = 2*PI / (numVertices - 1);
    for (int i = 0; i < numVertices - 1; i++){
        float angle = angleIncrement * i;

        float coordX = SCALE * cos(angle);
        float coordY = SCALE * sin(angle);
        indexData[2 * i] = coordX;
        indexData[2 * i + 1] = coordY;
    }
    size = sizeof(indexData);

    glGenBuffers(1, &indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &indexData, GL_STATIC_DRAW);
}

void createVertexArrays(){

}

void Drawable::Draw(){

}
