#pragma once
#include "glew.h"
#include <GLFW/glfw3.h>
#include "glm.hpp"

#include "Shader_Loader.h"
#include "Render_Utils.h"

// funkcja renderujaca scene    
void renderScene(GLFWwindow* window, float delta_red, float delta_green, float delta_blue)
{

    // ZADANIE: Przesledz kod i komentarze
    // ZADANIE: Zmien kolor tla sceny, przyjmujac zmiennoprzecinkowy standard RGBA
    
    float red = 1.0+delta_red;
    float green = 1.0+delta_green;
    float blue = 0.2 + delta_blue;
    float alpha = 1.0;

    int k = red;
    red -= k;

    //int l = blue;
    //blue -= l;

    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Powinno byc wywolane po kazdej klatce
    glfwSwapBuffers(window);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void init(GLFWwindow* window) {
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void shutdown(GLFWwindow* window)
{
}

//obsluga wejscia
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// funkcja jest glowna petla
void renderLoop(GLFWwindow* window) {
    float delta_red = 0;
    float delta_green = 0;
    float delta_blue = 0;

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        delta_red += 0.0001;
        delta_green += 0.0002;
        delta_blue += 0.0003;
        renderScene(window, delta_red, delta_green, delta_blue);
        glfwPollEvents();
    }
}
//}