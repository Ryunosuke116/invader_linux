#include"Player.h"

Player::Player()
{

}
Player::~Player()
{

}
void Player::Update(GLFWwindow* window)
{
   //入力待ち関数
   Shot(window);
   Move(window);

   obj_2D->SetPointXY(m_posX,m_posY);
}

void Player::Move(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        m_posX -= 0.01f;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        m_posX += 0.01f;
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