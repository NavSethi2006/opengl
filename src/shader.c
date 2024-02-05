#include "shader.h"



int shader_(const char* vertex_path, const char* fragment_path) {
    
    File vertex_file = file_read("../src/shaders/vertex.glsl");
    File fragment_file = file_read("../src/shaders/fragment.glsl");

    unsigned int vertex;
    int vertex_success;
    char info_log_vertex[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertex_file.data, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &vertex_success);
    if(!vertex_success) {
        glGetShaderInfoLog(vertex, 512, NULL, info_log_vertex);
        printf("ERROR WITH COMPILEING VERTEX SHADER %s\n", info_log_vertex);
    }

    unsigned int fragment;
    int fragment_success;
    char info_log_fragment[512];

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragment_file.data, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &fragment_success);
    if(!fragment_success) {
        glGetShaderInfoLog(fragment, 512, NULL, info_log_fragment);
        printf("ERROR WITH COMPILEING FRAGMENT SHADER %s\n", info_log_fragment);
    }

    int ID;

    int program_success;
    char info_log[512];

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &program_success);
    if(!program_success) {
        glGetProgramInfoLog(ID, 512, NULL, info_log);
        printf("ERROR WITH CREATEING SHADER PROGRAM : %s\n", info_log);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return ID;
} 

void use_shader(int shader_ID){
    glUseProgram(shader_ID);
}
const void set_shader_bool(int shader_ID, const char* name, bool value){glUniform1i(glGetUniformLocation(shader_ID, name), (int)value);}
const void set_shader_int(int shader_ID, const char* name, int value){glUniform1i(glGetUniformLocation(shader_ID, name), value);}
const void set_shader_float(int shader_ID, const char* name, float value){glUniform1i(glGetUniformLocation(shader_ID, name), value);}  
