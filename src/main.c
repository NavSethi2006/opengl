#include <stdio.h>
#include <stdlib.h>
#include "glad.h"
#include <GLFW/glfw3.h>
#include "window.h"
#include "triangle.h"

int main() {

    if(!glfwInit()) {
        perror("glfw could not initilize\n");
        exit(1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);    

    window_init();

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        perror("could not initilize GLAD");
        exit(1);
    }  

    triangle_();

    while(!glfwWindowShouldClose(window)) {
        window_update_prev();
        
        render_triangle();

        window_update_after();
    }

    
    glfwTerminate();
    return 0;
}
