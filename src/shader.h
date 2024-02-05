#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "glad.h"

/* 
    Gets the contents of files, Generates vertex and then fragment shader 
    and creates shader program,
    @param vertex_path self explanitory file path for vertex shader
    @param fragment_path self explanitory file path for fragment shader
    @returns the ID of the shader program to use in other functions
*/
int shader_(const char* vertex_path, const char* fragment_path);
/*   Use shader program - 
ONLY USE THIS IN RENDER FUNCTION 
 @param shader_ID get this ID via init_shader()
*/
void use_shader(int shader_ID);
/* set shader uniform to a different value  @param shader_ID @param name name of uniform @param value*/
const void set_shader_bool(int shader_ID,const char* name, bool value);
/* set shader uniform to a different value  @param shader_ID @param name name of uniform @param value*/
const void set_shader_int(int shader_ID ,const char* name, int value);
/* set shader uniform to a different value  @param shader_ID @param name name of uniform @param value*/
const void set_shader_float(int shader_ID ,const char* name, float value);

