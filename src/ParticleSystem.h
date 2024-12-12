#pragma once

#include <glm/glm.hpp>

#include "Shader.h"

struct Particle {
    glm::vec3 position = glm::vec3(0);
    glm::vec3 velocity = glm::vec3(0);

    Particle() = default;
    explicit Particle(glm::vec3 pos) : position(pos) {};
};

class ParticleSystem {
public:
    ParticleSystem() = delete;
    explicit ParticleSystem(int particleCount);

    void Render() const;

private:
    unsigned int VAO = 0;
    unsigned int particleBuffer = 0;
    int particleCount;

    Shader shader;
};
