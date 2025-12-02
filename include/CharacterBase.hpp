#pragma once
#include <vector>

class CharacterBase
{
public:
    CharacterBase();
    ~CharacterBase() = default;

    virtual void Create(){};

    virtual void Initialize();

    virtual void Update() =0;

    virtual void Move() = 0;
    virtual void Shot() {};
    virtual void Draw() =0;

protected:
    static constexpr int MAX_HP = 3;
    static constexpr int BULLET_NUM = 6;

    int m_posX;
    int m_posY;
    int m_velocity;
    int m_hp;
    bool m_isActive;
    bool m_is_right;
    bool m_is_left;
    bool m_isShot[BULLET_NUM];

};