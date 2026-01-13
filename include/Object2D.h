#pragma once
#include <GLFW/glfw3.h>
#include <vector>

struct PointXY
    {
        GLfloat x = 0.0f;
        GLfloat y = 0.0f;
    };

class Object2D
{
public:
    Object2D();
    ~Object2D();

    void Update(GLfloat x);
    void SetPointXY(GLfloat x, GLfloat y);
    void SetSizeValue(GLfloat setSizeValue) { sizeValue = setSizeValue; }

    const std::vector<GLfloat> GetGLfloat() const { return m_position; }

private:
    PointXY m_pointXY = { 0.0f, 0.0f };

    GLfloat sizeValue = 0.1f;

    std::vector<GLfloat> m_position = 
    { 
        sizeValue, sizeValue, 0.0f, 
        sizeValue, -sizeValue, 0.0f, 
        -sizeValue, -sizeValue, 0.0f,
        -sizeValue, sizeValue, 0.0f 
    };
};