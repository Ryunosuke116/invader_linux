#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

class SceneManager;
class Render;

class SceneBase
{
public:
    SceneBase(SceneManager& sceneManager):
    sceneManager(sceneManager)
    {

    }
    ~SceneBase() = default;

    virtual void Initialize() {};
    virtual void Update(GLFWwindow* window, Render& render) {};
    virtual void Draw() {};

protected:
    void ChangeScene(std::string name);

private:
    SceneManager& sceneManager;
};