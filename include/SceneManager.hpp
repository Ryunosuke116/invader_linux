#pragma once
#include <iostream>
#include <memory>
#include <unordered_map>
#include "SceneBase.h"
#include <GLFW/glfw3.h>

class Render;

class SceneManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    template <typename Scene>
    void AddScene(std::string sceneName)
    {
        if (umScenes.find(sceneName) == umScenes.end())
        {
           umScenes[sceneName] = new Scene{*this};
           
           if (nowScene == nullptr)
           {
                nowScene = umScenes[sceneName];
                nowScene->Initialize();
           }
        }
    }
    void ChangeScene(std::string sceneName);
    void Initialize();
    void Update(GLFWwindow* window, Render& render);
    void Draw();
private:

    std::unordered_map<std::string, SceneBase*> umScenes;
    SceneBase* nowScene;
};