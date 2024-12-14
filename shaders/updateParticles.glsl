#version 430
layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;

struct Particle {
    vec4 pos;
    vec4 vel;
};

layout(std430, binding=3) buffer Particles
{
    Particle particles[];
};

void main()
{
    particles[gl_GlobalInvocationID.x].pos += particles[gl_GlobalInvocationID.x].vel * 0.01;
}