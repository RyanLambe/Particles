cmake_minimum_required(VERSION 3.25)
project(Particles)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE})
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external)

add_executable(Particles
        src/main.cpp
)

target_include_directories(Particles PUBLIC external/glfw/include)
target_link_libraries(Particles glfw)