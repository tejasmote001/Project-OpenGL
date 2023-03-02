/**
 * Operating System: macOS Ventura 13.2.1 (22D68)
 * Hardware: Apple silicon M1
 * OpenGL version: 4.1 Metal - 83
 * OpenGL renderer: Apple M1
 */
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "basic_functions.hpp"

int main(void) {
    if (!glfwInit()) {
        std::cerr << "Unable to initialize the glfw library" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    
    if (window == nullptr) {
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    
    if (glewInit() != GLEW_OK) {
        std::cerr << "Unable to initialize the glew library" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::cout << "OpenGL version:\t\t" << glGetString(GL_VERSION) << std::endl;
    std::cout << "OpenGL renderer:\t" << glGetString(GL_RENDERER) << std::endl;
    
    static const GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSetKeyCallback(window, key_callback);
        glfwSwapBuffers(window);
        
        glClearBufferfv(GL_COLOR, 0, red);
    }
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
