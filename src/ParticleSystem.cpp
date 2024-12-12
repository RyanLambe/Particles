#include "ParticleSystem.h"

#include <glad/glad.h>

ParticleSystem::ParticleSystem(int particleCount) : particleCount(particleCount), shader("./shaders/particles.vert", "./shaders/particles.frag") {

    std::vector<Particle> particles;
    int particleGridSize = ceil(sqrt(particleCount));
    for(int i = 0; i < particleCount; i++)
    {
        glm::vec3 pos = glm::vec3((i % particleGridSize), (i / particleGridSize), 0);
        particles.emplace_back(pos);
    }
    for (int i = 0; i < particleGridSize; ++i) {
        for (int j = 0; j < particleGridSize; ++j) {
            particles.emplace_back(glm::vec3(i, j, 0));
        }
    }

    // gen and fill buffers
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &particleBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, particleBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Particle) * particleCount, &particles[0], GL_STATIC_DRAW);

    // vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, position));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, velocity));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void ParticleSystem::Render() const
{
    shader.Enable();
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, 1024);
    //glBindVertexArray(0);
}
