#pragma once
#include "SceneBase.h"
#include "SceneManager.hpp"
#include  "CollisionSystem.hpp"
#include "CharacterBase.hpp"
#include "Enemy.hpp"
#include "Player.h"

class Game : public SceneBase
{
public:
    Game(SceneManager& sceneManager);
    ~Game();

    void Initialize();
    void Update(GLFWwindow* window, Render& render) override;
    void Draw();

    void ChangeResult(GLFWwindow* window);
private:
    std::shared_ptr<CharacterBase> enemy        = NULL;
    std::shared_ptr<Enemy>         actualEnemy  = NULL;

    std::shared_ptr<CharacterBase> player = NULL;
    std::shared_ptr<Player> actualPlayer = NULL;

    std::shared_ptr<CollisionSystem> actualCollision = NULL;
 std::shared_ptr<Bullet> actualBullet = NULL;

    static constexpr GLfloat kGameOverPosY = -0.8f;
};