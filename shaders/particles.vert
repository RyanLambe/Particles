#version 330 core
layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos.x/32.0 - 0.5, aPos.y/32.0 - 0.5, aPos.z, 1.0);
}