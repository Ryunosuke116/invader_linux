#pragma once
#include <GLFW/glfw3.h>
#include <vector>

class Object2D
{
public:
    Object2D();
    ~Object2D();

    void Update(GLfloat x);

    const std::vector<GLfloat> GetGLfloat() const { return position; }

private:
    std::vector<GLfloat> position = 
    { 
        0.1f, 0.1f, 0.0f, 
        0.1f, -0.1f, 0.0f, 
        -0.1f, -0.1f, 0.0f,
        -0.1f, 0.1f, 0.0f 
    };
};