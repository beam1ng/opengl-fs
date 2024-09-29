#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>

// Function to read shader source from a file
char* read_shader_source(const char* filepath);

// Function to compile a shader
unsigned int compile_shader(const char* source, GLenum shader_type);

// Function to create a shader program
unsigned int create_shader_program(const char* vertex_filepath, const char* fragment_filepath);

// Function to use a shader program
void use_shader_program(unsigned int shader_program);

// Function to set a boolean uniform
void set_bool(unsigned int shader_program, const char* name, bool value);

// Function to set an integer uniform
void set_int(unsigned int shader_program, const char* name, int value);

// Function to set a float uniform
void set_float(unsigned int shader_program, const char* name, float value);

#endif // SHADER_UTILS_H
