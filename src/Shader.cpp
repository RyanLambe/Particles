#include "Shader.h"

#include <glad/glad.h>
#include <fstream>
#include <iostream>

Shader::Shader(const std::filesystem::path& vertexShaderFile, const std::filesystem::path& fragmentShaderFile) {

    unsigned int vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    LoadShader(vertexShader, vertexShaderFile);
    LoadShader(fragmentShader, fragmentShaderFile);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int  success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR: Failed to compile shader program\n" << infoLog << std::endl;
    }

    glUseProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::AddVertexShader(const std::filesystem::path &vertexShader) {

}

void Shader::AddFragmentShader(const std::filesystem::path &fragmentShader) {

}

void Shader::Enable() const {
    glUseProgram(shaderProgram);
}

void Shader::LoadShader(unsigned int shader, const std::filesystem::path& file) {
    std::ostringstream oss;
    std::ifstream fs(file);
    if(!fs.is_open()){
        std::cout << "cannot open\n";
        return;
    }
    oss << fs.rdbuf();
    const std::string str(oss.str());
    const char* ptr = str.c_str();

    glShaderSource(shader, 1, &ptr, NULL);
    glCompileShader(shader);

    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR: Shader Compilation failed: " << file << "\n" << infoLog << std::endl;
    }
}

