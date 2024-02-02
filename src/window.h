#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <stdbool.h>

void window_init();

void window_update_prev();

void window_update_after();

GLFWwindow *window();

void resize_callback(GLFWwindow* window, int width, int height);