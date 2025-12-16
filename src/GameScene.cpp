#include "GameScene.hpp"
#include "CharacterBase.hpp"
#include "Enemy.hpp"

GameScene::GameScene()
{
    enemy = std::make_shared<CharacterBase>();
}
GameScene::~GameScene()
{

}

void GameScene::Initialize()
{
    enemy->Initialize();
}

void GameScene::Update()
{
    enemy->Update();
}

void GameScene::Draw()
{
    enemy->Draw();
}