#pragma once
#include "CharacterBase.hpp"
#include <GLFW/glfw3.h>
class CharacterBase;

class Player : public CharacterBase
{
    public:
    Player();
    ~Player();
    void Draw();
    
    void Update(GLFWwindow * window);
    
    void Move(GLFWwindow * window);
   
    void Shot(GLFWwindow * window);

    bool IsColliding();

    private:



};