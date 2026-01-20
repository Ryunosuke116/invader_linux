#include"Bullet.h"
#include"Object2D.h"
#include"Render.h"
 
Bullet::Bullet()
{
}
Bullet::~Bullet()
{
 
}
void Bullet::Initialize()
{
    CharacterBase::Initialize();
    m_posX=0;
    m_posY=0;
    isShot = true;
    speedX=0;
    speedY=0;
    obj_2D->SetSizeValue(0.02f);
}
void Bullet::Shot(GLfloat x,GLfloat y)//プレイヤーの現在位置を引き数として持ってくるようにする。
{
    if(isShot)
    {
        //プレイヤー座標から球を発射するようにする
        m_posX = x;
        m_posY = y;
        speedY = 0.05f;    //弾の速度を設定する
        isShot = false;   //発射を不可能にする。
    }
 
}
void Bullet::Draw(Render& render)
{
    //描画
     if (m_posY <= 1.0f &&
        m_posY >= -1.0f &&
        m_posX <= 1.0f &&
        m_posX >= -1.0f &&
        !isShot)//画面内のみ描画
    {
        render.SetPosition(GetPosition());
    }
}
void Bullet::Update()
{
    m_posY += speedY;//ポジション更新処理
   
    //球が消えた時にisShotをＴＲＵＥにする処理を追加する
    if(m_posY > 1 ||
        m_posY < -1 ||
        m_posX > 1 ||
        m_posX < -1)//球が枠外に出た時
    {
        ClearBullet();
    }
   
    obj_2D->SetPointXY(m_posX, m_posY);
}
 
void Bullet::ClearBullet()//枠外に行ったとき、衝突したときに呼ぶための関数
{
    isShot=true;
    speedX=0.0f;
    speedY=0.0f;
}
 