#pragma once

#include <filesystem>

class Shader {
public:
    Shader() = delete;
    Shader(const std::filesystem::path& vertexShader, const std::filesystem::path& fragmentShader);

    void AddVertexShader(const std::filesystem::path& vertexShader);
    void AddFragmentShader(const std::filesystem::path& fragmentShader);

    void Enable() const;

private:
    unsigned int shaderProgram = 0;

    static void LoadShader(unsigned int shader, const std::filesystem::path& file);

};
