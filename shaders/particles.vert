#version 430 core
layout (location = 0) in vec3 aPos;

struct Particle {
    vec4 pos;
    vec4 vel;
};

layout(std430, binding=3) readonly buffer Particles
{
    Particle particles[];
};

void main()
{
    gl_Position = vec4(particles[gl_VertexID].pos.xyz, 1);
}