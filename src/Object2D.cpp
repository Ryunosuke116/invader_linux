#include <GLFW/glfw3.h>
#include "Object2D.h"


Object2D::Object2D()
{

}

Object2D::~Object2D()
{

}


void Object2D::Update(GLfloat x)
{
        m_position[0]+= x;
        m_position[3]+= x;
        m_position[6]+= x;
        m_position[9]+= x;
}

void Object2D::SetPointXY(GLfloat x, GLfloat y)
{
        m_pointXY.x = x;
        m_pointXY.y = y;

        m_position[0] = (x + 0.1f); 
        m_position[3] = (x + 0.1f);
        m_position[6] = (x - 0.1f);  
        m_position[9] = (x - 0.1f); 

        m_position[1] = (y + 0.1f); 
        m_position[4] = (y - 0.1f);
        m_position[7] = (y - 0.1f);  
        m_position[10] = (y + 0.1f); 
}