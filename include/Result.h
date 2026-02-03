#pragma once
#include "SceneBase.h"
#include "SceneManager.hpp"
#include "Player.h"
#include "CharacterBase.hpp"

class Result : public SceneBase
{
public:
    Result(SceneManager& sceneManager);
    ~Result();

    void Initialize();
    void Update(GLFWwindow* window, Render& render) override;
    void Draw();

    void ChangeGame(GLFWwindow* window);

private:
    std::shared_ptr<CharacterBase> player = NULL;
    std::shared_ptr<Player> actualPlayer = NULL;
};