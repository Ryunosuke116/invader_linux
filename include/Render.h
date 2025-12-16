#pragma once
#include <vector>
#include <GLFW/glfw3.h>

class Render
{
public:
    void Initialize(const char* path);
    void Update(const char* path);
    void Draw();
    void ResetPosition() {m_positions.clear();}

    void SetPosition(std::vector<GLfloat> objectPos);
    std::vector<GLfloat> GetPosition() {return m_positions;}
    int GetObjectCount() {return m_objectCount;}

private:
    std::vector<GLfloat> m_positions;
    int m_objectCount;

    unsigned char* pixel = NULL;
    unsigned char* pixel_resize = NULL;
    int width = 0;
    int height = 0;
    int bpp = 0;
    int reWidth = 512;

    static constexpr int kSquareVertexValue = 4;    //四角形の頂点数
};