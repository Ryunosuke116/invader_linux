#pragma once
#include <memory>
class CharacterBase;
class Enemy;

class GameScene
{
    public:
    GameScene();
    ~GameScene();

    void Initialize(); 

    void Update();

    void Draw();

    private:
    std::shared_ptr<CharacterBase> enemy = nullptr;

};