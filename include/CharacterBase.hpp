#pragma once
#include <vector>
#include <memory>
#include <GLFW/glfw3.h>
#include "Object2D.h"



class CharacterBase
{
public:
    CharacterBase();
    ~CharacterBase() = default;

    virtual void Create(){};

    virtual void Initialize();

    virtual void Update() {};

    virtual void Move() {};
    virtual void Shot() {};
    virtual void Draw() {};

    const std::vector<GLfloat> GetPosition() const ;

protected:
    static constexpr int MAX_HP = 1;
    static constexpr int BULLET_NUM = 6;
    GLfloat m_posX;
    GLfloat m_posY;
    GLfloat m_bulletPos;
    GLfloat m_velocity;
    int m_hp;
    bool m_isActive;
    bool m_is_right;
    bool m_is_left;
    bool m_is_down;
    bool m_isShot[BULLET_NUM];

    std::shared_ptr<Object2D> obj_2D = std::make_shared<Object2D>(); 


};