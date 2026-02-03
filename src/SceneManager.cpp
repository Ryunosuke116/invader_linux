#include "Render.h"
#include "SceneManager.hpp"

SceneManager::SceneManager()
{

}

void SceneManager::Initialize()
{
    nowScene->Initialize();
}

void SceneManager::Update(GLFWwindow* window, Render& render)
{
    nowScene->Update(window, render);
}

void SceneManager::Draw()
{
    nowScene->Draw();
}

void SceneManager::ChangeScene(std::string sceneName)
{
    nowScene = umScenes[sceneName];
    nowScene->Initialize();
}