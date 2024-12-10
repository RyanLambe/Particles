cmake_minimum_required(VERSION 3.16)
project(Particles)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE})
set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_executable(Particles src/main.cpp)

target_include_directories(Particles PUBLIC OpenGL::GL OpenGL::GLU GLUT::GLUT ${GLEW_INCLUDE_DIRS} external)

target_link_libraries (Particles ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} glfw GLEW::GLEW)