#include "Shader.h"

#include <glad/glad.h>
#include <fstream>
#include <iostream>

void Shader::AddVertexShader(const std::filesystem::path &vertexShaderFile) {
    unsigned int shader;
    shader = glCreateShader(GL_VERTEX_SHADER);
    LoadShader(shader, vertexShaderFile);
    shaders.push_back(shader);
}

void Shader::AddFragmentShader(const std::filesystem::path &fragmentShaderFile) {
    unsigned int shader;
    shader = glCreateShader(GL_FRAGMENT_SHADER);
    LoadShader(shader, fragmentShaderFile);
    shaders.push_back(shader);
}

void Shader::AddComputeShader(const std::filesystem::path &computeShaderFile) {
    unsigned int shader;
    shader = glCreateShader(GL_COMPUTE_SHADER);
    LoadShader(shader, computeShaderFile);
    shaders.push_back(shader);
}

void Shader::Compile() {
    if (isCompiled) {
        std::cout << "ERROR: Shader already compiled" << std::endl;
        return;
    }

    shaderProgram = glCreateProgram();
    for (const auto &shader : shaders) {
        glAttachShader(shaderProgram, shader);
    }
    glLinkProgram(shaderProgram);

    int  success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR: Failed to compile shader program\n" << infoLog << std::endl;
        return;
    }
    glUseProgram(shaderProgram);

    for (const auto &shader : shaders) {
        glDeleteShader(shader);
    }
    shaders = {};
    isCompiled = true;
}

void Shader::Enable() const {
    if (!isCompiled) {
        std::cout << "ERROR: Shader not compiled" << std::endl;
        return;
    }
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

