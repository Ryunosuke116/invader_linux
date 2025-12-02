#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}


void Enemy::Update()
{
    
}

void Enemy::Move()
{
    if(m_is_right)
    {
        m_posX += MAX_MOVE_SPEED;
    }
    else if(m_is_left)
    {
        m_posX -= MAX_MOVE_SPEED;
    }

}

void Enemy::Draw()
{
    std::cerr << "pos_X" << (m_posX) << "\n";
}