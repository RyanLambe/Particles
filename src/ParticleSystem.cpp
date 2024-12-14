#include "ParticleSystem.h"

#include <glad/glad.h>

ParticleSystem::ParticleSystem(int particleCount) : particleCount(particleCount) {

    // generate particles
    std::vector<Particle> particles;
    int particleGridSize = ceil(sqrt(particleCount));
    for(int i = 0; i < particleCount; i++)
    {
        glm::vec4 pos = glm::vec4((float)(i % particleGridSize) / (float)particleGridSize, (float)(i / particleGridSize) / (float)particleGridSize, 0, 0);
        particles.emplace_back(pos - glm::vec4(0.5, 0.5, 0, 0));
        particles.back().velocity = glm::vec4(0, (float)i / (float)particleCount, 0, 0);
    }

    // create and fill buffers
    glGenVertexArrays(1, &VAO);

    glGenBuffers(1, &ssbo);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(Particle) * particleCount, &particles[0], GL_DYNAMIC_COPY);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 3, ssbo);

    // create shaders
    drawShader.AddVertexShader("./shaders/particles.vert");
    drawShader.AddFragmentShader("./shaders/particles.frag");
    drawShader.Compile();

    updateShader.AddComputeShader("./shaders/updateParticles.glsl");
    updateShader.Compile();
}

void ParticleSystem::Render() const
{
    updateShader.Enable();
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
    glDispatchCompute(particleCount, 1, 1);
    glMemoryBarrier(GL_ALL_BARRIER_BITS);

    drawShader.Enable();
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, particleCount);
    glBindVertexArray(0);
}
