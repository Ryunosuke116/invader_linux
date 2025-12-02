#include "CharacterBase.hpp"

CharacterBase::CharacterBase()
:m_hp(0),
m_isActive(false),
m_is_left(false),
m_is_right(false),
m_posX(0),
m_posY(0),
m_velocity(0)
{};

void CharacterBase::Initialize()
{
    m_isActive = true;
    for(int i = 0; i < BULLET_NUM; i++)
    {
        m_isShot[i] = false;
    }
    m_hp       = MAX_HP;
    m_posX     = 0;
    m_posY     = 0;
}

