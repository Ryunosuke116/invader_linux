#include <GLFW/glfw3.h>
#include "Render.h"
#include "Bullet.h"
#include "SceneManager.hpp"
#include "Result.h"

Result::Result(SceneManager& sceneManager) : 
    SceneBase(sceneManager)
{

}

Result::~Result()
{

}

void Result::Initialize()
{
    if(player == NULL)
    {
        player          = std::make_shared<Player>();
        actualPlayer    =  std::dynamic_pointer_cast<Player>(player);    
    }

    player->Initialize();
}

void Result::Update(GLFWwindow* window, Render& render)
{
    actualPlayer->Update(window);
    std::shared_ptr<Bullet> actualBullet = std::dynamic_pointer_cast<Bullet>(actualPlayer->GetBullet());
    actualBullet->Draw(render);

    render.SetPosition(player->GetPosition());

    ChangeGame(window);
}

void Result::Draw()
{
    
}

void Result::ChangeGame(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        ChangeScene("Game");
    }
}