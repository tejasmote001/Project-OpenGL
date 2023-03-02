//
//  basic_functions.cpp
//  HelloWorld
//
//  Created by Tejas Mote on 03/03/23.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "basic_functions.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    // When a user presses the escape key, we set the WindowShouldClose property to true,
    // closing the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
