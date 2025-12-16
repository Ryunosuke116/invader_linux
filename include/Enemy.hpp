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

    void  Draw() override;

    private:
    static constexpr float MAX_MOVE_SPEED = 2.0f;
    bool m_is_right;
    bool m_is_left;

};