﻿#pragma once
#include "glew.h"
#include "glm.hpp"
#include "ext.hpp"
#include <iostream>
#include <cmath>
#include <GLFW/glfw3.h>

#include "Shader_Loader.h"
#include "Render_Utils.h"

#include "Box.cpp"
float points[] = {
0.0f,1.0f,0.f,1.f,
0.7818314824680298f,0.6234898018587336f,0.f,1.f,
0.9749279121818236f,-0.22252093395631434f,0.f,1.f,
0.43388373911755823f,-0.900968867902419f,0.f,1.f,
-0.433883739117558f,-0.9009688679024191f,0.f,1.f,
-0.9749279121818236f,-0.2225209339563146f,0.f,1.f,
-0.7818314824680299f,0.6234898018587334f,0.f,1.f,
};
float hues[] = {
	0.0f, 
	0.7142857142857143f, 
	0.42857142857142855f, 
	0.14285714285714285f, 
	0.8571428571428571f, 
	0.5714285714285714f, 
	0.2857142857142857f
};



GLuint program;
Core::Shader_Loader shaderLoader;

unsigned int VAO;

void renderScene(GLFWwindow* window)
{
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// ZADANIE: Powyżej w tablicy points znajdują się wierzchołki 7-kąta foremnego, zadanie polega na narysowaniu gwiazdy siedmioramiennej jak na obrazku zad1b.jpg. Do shadera należy przesłać pozycje wierzchołków i ich odcienie z tablicy hues podobnie jak w zadaniu 1a. 
	// Idealnie rozwiązane zadanie wymaga użycia indeksowania z użyciem Element Buffer Objects oraz trybu rysowania GL_LINE_STRIP
	// (dodatkowe) Jedna krawędź przechodzi przez wszystkie odcienie zamiast z czerwonego do magenty. Co to powoduje? W jaki sposób byś to naprawił?

	glUseProgram(program);




	glUseProgram(0);
	glfwSwapBuffers(window);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void init(GLFWwindow* window)
{
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glEnable(GL_DEPTH_TEST);
	program = shaderLoader.CreateProgram("shaders/shader_2_1b.vert", "shaders/shader_2_1b.frag");

}

void shutdown(GLFWwindow* window)
{
	shaderLoader.DeleteProgram(program);
}

//obsluga wejscia
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// funkcja jest glowna petla
void renderLoop(GLFWwindow* window) {
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		renderScene(window);
		glfwPollEvents();
	}
}
//}