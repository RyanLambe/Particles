cmake_minimum_required(VERSION 3.25)
project(imgui)

include_directories(imgui)
add_library(imgui STATIC
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp

        imgui/backends/imgui_impl_glfw.cpp
        imgui/backends/imgui_impl_opengl3.cpp

        imgui/misc/cpp/imgui_stdlib.cpp
)

target_include_directories(imgui PUBLIC ../glfw/include)
target_link_libraries(imgui glfw)