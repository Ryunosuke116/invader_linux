#pragma once
#include<list>
#include<iostream>
#include"CharacterBase.hpp"
 
class Render;
 
class Bullet:public CharacterBase
{
public:
    Bullet();
    ~Bullet();
    void Initialize();
    void Shot(GLfloat x,GLfloat y);
    void Draw(Render& render);
    void Update();
    void ClearBullet();
    
    GLfloat GetBulletPosX() const {return m_posX;}
    GLfloat GetBulletPosY() const {return m_posY;}
    bool GetIsShot() const {return isShot;}
    GLfloat GetSize() const {return obj_2D->GetSizeValue();}
 
private:
    bool isShot;//撃てるかどうか
    float speedX;//X座標速度
    float speedY;//Y座標速度
 
 
 
};
 
