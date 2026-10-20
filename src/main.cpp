#include "main.h"
#include "UI/uiHandler.hpp"
#include "sim/simulation.hpp"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 760, "Three Body", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f); // Clear to a dark grey background

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
