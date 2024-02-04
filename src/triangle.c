#include "triangle.h"

float verticies[] = {
    0.5f,  -0.5f, 0.0f, 
    -0.5f, -0.5f, 0.0f,
    0.5f, 0.5f, 0.0f,  

};

unsigned int VBO;
unsigned int vertex_shader;
unsigned int fragment_shader;
unsigned int shader_program;
unsigned int VAO;


const GLchar* vertex_shader_source = "#version 330 core\n"
                                "layout (location = 0) in vec3 aPos;\n"
                                "void main()\n"
                                "{\n"
                                "   gl_Position = vec4(aPos, 1.0);\n"
                                "}\0";

const GLchar* fragment_shader_source ="#version 330 core\n"
                            "out vec4 FragColor;\n"
                            "uniform vec4 ourColor;\n"
                            "void main()\n"
                            "{\n"
                            "   FragColor = ourColor;\n"
                            "}\n\0";

void init_triangle() {

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, verticies);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
    glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    int vertex_compiled;
    char shader_log[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &vertex_compiled);

    if(!vertex_compiled) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, shader_log);
        printf("ERROR WITH SHADER: %s\n", shader_log);
        exit(1);
    }    

    glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    int compiled_fragment;
    char frag_shader_log[1024];
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &compiled_fragment);
    if(!compiled_fragment) {
        glGetShaderInfoLog(fragment_shader, 1024, NULL, frag_shader_log);
        printf("ERROR WITH FRAGMENT SHADER: %s\n", frag_shader_log);
        exit(1);
    }


    shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    int program_compiled;
    char shader_program_log[1024];

    glGetProgramiv(shader_program, GL_LINK_STATUS, &program_compiled);
    if(!program_compiled) {
        glGetProgramInfoLog(shader_program, 1024, NULL, shader_program_log);
        printf("ERROR WITH SHADER PROGRAM : %s\n", shader_program_log);
        exit(1);
    }

//  generate buffers and arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

// bind buffers and arrays
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    
}

void render_triangle() {
    
    
    glUseProgram(shader_program);

    int uniform = glGetUniformLocation(shader_program, "ui_shader");
    glUniform4f(uniform, 0.0f, 1.0f, 0.0f, 1.0f);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}