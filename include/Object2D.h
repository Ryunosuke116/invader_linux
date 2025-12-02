#pragma once

class Object2D
{
public:
    Object2D();
    ~Object2D();

    void Initialize();
    void Update();
    void Draw();

private:
    GLfloat position[] = 
    { 
        0.1f, 0.1f, 0.0f, 
        0.1f, -0.1f, 0.0f, 
        -0.1f, -0.1f, 0.0f,
        -0.1f, 0.1f, 0.0f 
    };
}