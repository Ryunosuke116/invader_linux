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

         actualCollision = std::make_shared<CollisionSystem>();
        actualBullet = std::dynamic_pointer_cast<Bullet>(actualPlayer->GetBullet());
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

    for (auto& enemyData : actualEnemy->GetEnemysRef())
    {
        actualCollision->Update(actualBullet, enemyData);
        
        // 敵が当たられていない場合のみ描画とゲームオーバーチェック
        if(!enemyData.isHit)
        {
            render.SetPosition(enemyData.obj_2D->GetGLfloat());
            
            //特定の座標に達した場合、ゲームオーバー
            if (enemyData.m_posY <= kGameOverPosY)
            {
                ChangeScene("Result");
            }
        }
    }

    //敵が全滅した場合、ゲームクリア
    int activeEnemies = 0;
    for (const auto& enemyData : actualEnemy->GetEnemysRef())
    {
        if (!enemyData.isHit)
        {
            activeEnemies++;
        }
    }
    
    if(activeEnemies == 0)
    {
        ChangeScene("Result");
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