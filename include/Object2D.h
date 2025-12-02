#pragma once
#include <GLFW/glfw3.h>

class Object2D
{
public:
    Object2D();
    ~Object2D();

    void Update(GLfloat x);

    const GLfloat* GetGLfloat() const { return position; }

private:
    GLfloat position[12] = 
    { 
        0.1f, 0.1f, 0.0f, 
        0.1f, -0.1f, 0.0f, 
        -0.1f, -0.1f, 0.0f,
        -0.1f, 0.1f, 0.0f 
    };
};