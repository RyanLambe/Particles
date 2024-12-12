#include <iostream>

#include "Application.h"
#include "ParticleSystem.h"

int main() {

    Application app;
    ParticleSystem particles(1024);
    while(app.Update()){
        // draw UI
        //ImGui::ShowDemoWindow();
        app.RenderImGui();

        // draw OpenGL
        particles.Render();
    }

    return 0;
}
