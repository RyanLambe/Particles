#pragma once

#include <glm/glm.hpp>

#include "Shader.h"

struct Particle {
    glm::vec4 position = glm::vec4(0);
    glm::vec4 velocity = glm::vec4(0);

    Particle() = default;
    explicit Particle(glm::vec4 pos) : position(pos) {};
};

class ParticleSystem {
public:
    ParticleSystem() = delete;
    explicit ParticleSystem(int particleCount);

    void Render() const;

private:
    unsigned int VAO = 0;
    unsigned int ssbo = 0;
    int particleCount;

    Shader drawShader;
    Shader updateShader;
};
