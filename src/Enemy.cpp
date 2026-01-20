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

void Enemy::Initialize()
{
    CharacterBase::Initialize();
    m_isMovePosY = false;
    GLfloat interval = 0.02f;
    GLfloat startPointX = -0.9f;
    GLfloat addPosY = 1.0f;

    for (int j = 0; j < kMaxEnemyY; j++)
    {
        for (int i = 0; i < kMaxEnemyX; i++)
        {
            EnemyData enemyData;
            enemyData.obj_2D = std::make_shared<Object2D>();
            enemyData.isActivity = true;
            enemyData.m_posX = startPointX;
            enemyData.m_posY = addPosY - 0.05f;
    
            enemyData.obj_2D->SetPointXY(enemyData.m_posX, enemyData.m_posY);
            startPointX += 0.15f;
            enemyData.obj_2D->SetSizeValue(0.05f);
    
            vEnemys.push_back(enemyData);
        }
        startPointX = -0.9f;
        addPosY -= 0.2f;
    }
}

void Enemy::Update()
{
    CheckWindowEdge();
    Move();

    for (auto& enemyData : vEnemys)
    {
        enemyData.obj_2D->SetPointXY(enemyData.m_posX, enemyData.m_posY);
    }
}

void Enemy::Move()
{
    if(m_is_right)
    {
        for (auto& enemyData : vEnemys)
        {
            if(m_isMovePosY)
            {
                enemyData.m_posY -= kAddPosY;
            }
            enemyData.m_posX += MAX_MOVE_SPEED;
        }
    }
    else if(m_is_left)
    {
         for (auto& enemyData : vEnemys)
        {
            if(m_isMovePosY)
            {
                enemyData.m_posY -= kAddPosY;
            }
            enemyData.m_posX -= MAX_MOVE_SPEED;
        }
    }

    if (m_isMovePosY)
    {
        m_isMovePosY = false;
    }
}

void Enemy::Shot()
{

}

void Enemy::CheckWindowEdge()
{
    for (auto& enemyData : vEnemys)
    {
        if (enemyData.m_posX >= 1.0f - enemyData.obj_2D->GetSizeValue())
        {
            m_is_right = false;
            m_is_left = true;
            m_isMovePosY = true;
        }
        else if (enemyData.m_posX <= -1.0f + enemyData.obj_2D->GetSizeValue())
        {
            m_is_right = true;
            m_is_left = false;
            m_isMovePosY = true;
        }
    }
}

void Enemy::Draw()
{

    std::cerr << "pos_X" << (m_posX) << "\n";
}