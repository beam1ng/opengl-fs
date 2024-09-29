#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shader_utils.h"

char* read_shader_source(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filepath);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Failed to allocate memory for file: %s\n", filepath);
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';

    fclose(file);
    return buffer;
}

unsigned int compile_shader(const char* source, GLenum shader_type) {
    unsigned int shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    int success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        printf("Shader compilation failed: %s\n", info_log);
        return 0;
    }

    return shader;
}

unsigned int create_shader_program(const char* vertex_filepath, const char* fragment_filepath) {
    char* vertex_source = read_shader_source(vertex_filepath);
    char* fragment_source = read_shader_source(fragment_filepath);

    if (vertex_source == NULL || fragment_source == NULL) {
        free(vertex_source);
        free(fragment_source);
        return 0;
    }

    unsigned int vertex_shader = compile_shader(vertex_source, GL_VERTEX_SHADER);
    unsigned int fragment_shader = compile_shader(fragment_source, GL_FRAGMENT_SHADER);

    free(vertex_source);
    free(fragment_source);

    if (vertex_shader == 0 || fragment_shader == 0) {
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
        return 0;
    }

    unsigned int shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    int success;
    char info_log[512];
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, info_log);
        printf("Shader program linking failed: %s\n", info_log);
        glDeleteProgram(shader_program);
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
        return 0;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return shader_program;
}

void use_shader_program(unsigned int shader_program) {
    glUseProgram(shader_program);
}

void set_bool(unsigned int shader_program, const char* name, bool value) {
    glUniform1i(glGetUniformLocation(shader_program, name), (int)value);
}

void set_int(unsigned int shader_program, const char* name, int value) {
    glUniform1i(glGetUniformLocation(shader_program, name), value);
}

void set_float(unsigned int shader_program, const char* name, float value) {
    glUniform1f(glGetUniformLocation(shader_program, name), value);
}
