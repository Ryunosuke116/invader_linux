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
        position[0]+= x;
        position[3]+= x;
        position[6]+= x;
        position[9]+= x;
}