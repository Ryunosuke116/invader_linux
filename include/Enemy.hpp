#pragma once
#include "CharacterBase.hpp"
#include <vector>

struct EnemyData
{
    std::shared_ptr<Object2D> obj_2D;
    bool isActivity;
    GLfloat m_posX;
    GLfloat m_posY;
};

class Enemy : public CharacterBase
{
public:
    Enemy();
    ~Enemy();

    void Initialize() override;
    void Update() override;

    void Move() override;

    void CheckWindowEdge();

    void Shot()override;

    void  Draw() override;

    const std::vector<EnemyData> GetEnemys() const { return vEnemys;}

private:
    static constexpr GLfloat MAX_MOVE_SPEED = 0.01f;
    static constexpr GLfloat kAddPosY = 0.03f;
    static constexpr int kMaxEnemy = 10;

    std::vector<EnemyData> vEnemys;
    bool m_isMovePosY;
};