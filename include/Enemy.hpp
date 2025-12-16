#pragma once
#include "CharacterBase.hpp"

class Enemy : public CharacterBase
{
    public:
    Enemy();
    ~Enemy();

    void Update() override;

    void Move() override;

    void CheckWindowEdge();

    void Shot()override;

    void  Draw() override;

    private:
    static constexpr GLfloat MAX_MOVE_SPEED = 0.01f;

};