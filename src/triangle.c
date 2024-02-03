#include "triangle.h"

float verticies[] = {
    -0.5, -0.5, 0,
    0.5, -0.5, 0,
    0, -0,5, 0

};

unsigned int VBO;
unsigned int vertex_shader;
unsigned int fragment_shader;
unsigned int shader_program;
unsigned int VAO;


void init_triangle() {

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, verticies);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
    glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, read_shader("shaders/vertex.glsl"), NULL);
    glCompileShader(vertex_shader);
    int compiled;
    char shader_log[1024];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &compiled);

    if(!compiled) {
        glGetShaderInfoLog(vertex_shader, 1024, NULL, shader_log);
        printf("ERROR WITH SHADER: %s", shader_log);
    }

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, read_shader("shaders/fragment.glsl"), NULL);
    glCompileShader(fragment_shader);

    shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);
    int program_compiled;
    char shader_program_log[1024];

    glGetProgramiv(shader_program, GL_LINK_STATUS, &program_compiled);
    if(!program_compiled) {
        glGetProgramInfoLog(shader_program, 1024, NULL, shader_program_log);
        printf("ERROR WITH SHADER PROGRAM : %s", shader_program_log);
    }

    glUseProgram(shader_program);


    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

}

void render_triangle() {

}