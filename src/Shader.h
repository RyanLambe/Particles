#pragma once

#include <filesystem>
#include <vector>

class Shader {
public:
    Shader() = default;

    void AddVertexShader(const std::filesystem::path& vertexShaderFile);
    void AddFragmentShader(const std::filesystem::path& fragmentShaderFile);
    void AddComputeShader(const std::filesystem::path& computeShaderFile);

    void Compile();
    void Enable() const;

private:
    unsigned int shaderProgram = 0;
    std::vector<unsigned int> shaders = {};
    bool isCompiled = false;

    static void LoadShader(unsigned int shader, const std::filesystem::path& file);

};
