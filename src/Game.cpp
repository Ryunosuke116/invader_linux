#include <GLFW/glfw3.h>
#include "Render.h"
#include "Bullet.h"
#include "SceneManager.hpp"
#include "Game.h"

Game::Game(SceneManager& sceneManager) : 
    SceneBase(sceneManager)
{

}

Game::~Game()
{

}

void Game::Initialize()
{
    if(enemy == NULL)
    {
        enemy        = std::make_shared<Enemy>();
        actualEnemy  = std::dynamic_pointer_cast<Enemy>(enemy);
        
        player          = std::make_shared<Player>();
        actualPlayer    =  std::dynamic_pointer_cast<Player>(player);    
    }

    enemy->Initialize();
    player->Initialize();
}

void Game::Update(GLFWwindow* window, Render& render)
{
    enemy->Update();
    actualPlayer->Update(window);
    std::shared_ptr<Bullet> actualBullet = std::dynamic_pointer_cast<Bullet>(actualPlayer->GetBullet());
    actualBullet->Draw(render);

    render.SetPosition(player->GetPosition());
    for (auto& enemyData : actualEnemy->GetEnemys())
    {
        render.SetPosition(enemyData.obj_2D->GetGLfloat());
    }

    ChangeResult(window);
}

void Game::Draw()
{
    
}

void Game::ChangeResult(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
    {
        ChangeScene("Result");
    }
}