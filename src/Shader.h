#pragma once

#include <filesystem>

class Shader {
public:
    Shader() = delete;
    Shader(const std::filesystem::path& vertexShader, const std::filesystem::path& fragmentShader);

private:
    unsigned int vertexShader;
    unsigned int fragmentShader;

    static void LoadShader(unsigned int shader, const std::filesystem::path& file);

};
