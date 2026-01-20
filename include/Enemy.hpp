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

    std::vector<EnemyData> vEnemys;
};