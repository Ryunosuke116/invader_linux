cmake_minimum_required(VERSION 3.10)
project(OpenGL_GLFW_Demo)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/glad)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad ${OPENGL_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE external/glad/include)