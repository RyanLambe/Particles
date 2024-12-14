cmake_minimum_required(VERSION 3.25)
project(Particles)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE}/temp)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Particles
        src/main.cpp
        src/Application.h
        src/Application.cpp
        src/Shader.h
        src/Shader.cpp
        src/ParticleSystem.cpp
        src/ParticleSystem.h
)

target_include_directories(Particles PUBLIC external/glfw/include)
target_include_directories(Particles PUBLIC external/glad/include)
target_include_directories(Particles PUBLIC external/glm)
target_include_directories(Particles PUBLIC external/imgui/imgui external/imgui/imgui/backends)
target_link_libraries(Particles glfw glad imgui)

add_custom_target(copy_assets COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/shaders" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shaders")
add_dependencies(Particles copy_assets)