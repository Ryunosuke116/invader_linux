#include"Player.h"
Player::Player()
{

}
Player::~Player()
{

}
void Player::Update(GLFWwindow* window)
{
   //プレイヤー描画関数
   
   //入力待ち関数
   Shot(window);
   Move(window);
   
}
void Player::Draw()  //描画関数
{

}

void Player::Move(GLFWwindow* window)
{
   
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        m_posX--;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        m_posX++;
    }
   
}

void Player::Shot(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        //球を発射する関数を呼び出す

    }
}

bool Player::IsColliding()
{
    return 0;
}
//次やること
//弾の制御
//弾とエネミーの当たり判定を返す