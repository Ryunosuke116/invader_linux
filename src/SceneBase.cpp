#include "SceneBase.h"
#include "SceneManager.hpp"

void SceneBase::ChangeScene(std::string name)
{
    sceneManager.ChangeScene(name);
}