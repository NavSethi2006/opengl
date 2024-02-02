#include "window.h"

GLFWwindow* _window;

void window_init() {
    _window = glfwCreateWindow(800, 600, "fucking-around", NULL, NULL);
    if(_window == NULL) {
        perror("glfw window could not be made");
        exit(1);
    }
    glfwMakeContextCurrent(_window);
    glViewport(0,0,800,600);

    glfwSetFramebufferSizeCallback(_window, resize_callback);

}

void resize_callback(GLFWwindow* window, int width, int height) {
    glViewport(0,0,width,height);
}

void window_update_prev() {

    if(glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        exit(0);

    glfwSwapBuffers(_window);
    glfwPollEvents();
}

void window_update_after() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
} 

GLFWwindow *window() {
    return _window;
}