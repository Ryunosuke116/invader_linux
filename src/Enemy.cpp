#include <iostream>
#include "Enemy.hpp"
Enemy::Enemy()
{
    m_is_right = true;
    m_is_left = false;
}

Enemy::~Enemy()
{
}


void Enemy::Update()
{
    CheckWindowEdge();
    Move();

    obj_2D->SetPointXY(m_posX,m_posY);

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

void Enemy::Shot()
{

}

void Enemy::CheckWindowEdge()
{
    if(m_posX>=800)
    {
        m_is_right = false;
        m_is_left = true;
    }
    if (m_posX<=0)
    {
        m_is_right = true;
        m_is_left = false;
    }

}

void Enemy::Draw()
{

    std::cerr << "pos_X" << (m_posX) << "\n";
}