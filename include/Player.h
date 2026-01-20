#pragma once
#include "CharacterBase.hpp"
#include <GLFW/glfw3.h>
class Bullet;

class Player : public CharacterBase
{
    public:
    Player();
    ~Player();

    void Update(GLFWwindow * window);
    
    void Move(GLFWwindow * window);
   
    void Shot(GLFWwindow * window);

    bool IsColliding();
 
    void Initialize() override;
    std::shared_ptr<CharacterBase> GetBullet(){return bullet;}

    private:
    //1月20日追加弾クラス
    std::shared_ptr<CharacterBase> bullet ;
    std::shared_ptr<Bullet> actualBullet ;


};