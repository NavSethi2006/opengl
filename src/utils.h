#include <stdlib.h>
#include <stdio.h>
#include "glad.h"

const GLchar* read_shader(char *file_name) {
    FILE* shader_file = fopen(file_name, "r");
    int file_size;
    char *vertex_shader;
    fseek(shader_file, 0, SEEK_END);
    file_size = ftell(shader_file);

    vertex_shader = (char*)malloc(sizeof(char) * (file_size+1));
    fread(vertex_shader, sizeof(char), file_size, shader_file);
    vertex_shader[file_size] = '\0';
    
    return (const GLchar*)vertex_shader;
}