#include "triangle.h"

float vertici[] = {
    0.5f,  -0.5f, 0.0f, 
    -0.5f, -0.5f, 0.0f,
    0.5f, 0.5f, 0.0f,  
};

unsigned int VBO;
unsigned int VAO;
int triangle_shader;

void triangle_() {

    triangle_shader = shader_("../src/shaders/tri_vertex.glsl","../src/shaders/tri_frag.glsl");

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertici), vertici, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);


}

void render_triangle() {
    
    use_shader(triangle_shader);
    set_shader_float(triangle_shader, "ourColor", 1.0f);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
