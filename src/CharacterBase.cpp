#include "CharacterBase.hpp"
#include "Object2D.h"

CharacterBase::CharacterBase()
:m_hp(0),
m_isActive(false),
m_is_left(false),
m_is_right(false),
m_posX(0),
m_posY(0),
m_velocity(0)
{

};

void CharacterBase::Initialize()
{
    m_isActive = true;
    m_is_down = false;
    m_is_left = false;
    m_is_right = true;
    for(int i = 0; i < BULLET_NUM; i++)
    {
        m_isShot[i] = false;
    }
    m_hp       = MAX_HP;
    m_bulletPos= 0;
    m_posX     = 0;
    m_posY     = 0;
}

const std::vector<GLfloat> CharacterBase::GetPosition() const
{
    return obj_2D->GetGLfloat(); 
}
