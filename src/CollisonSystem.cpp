#include "CollisionSystem.hpp"
#include "CharacterBase.hpp"
#include "Enemy.hpp"
#include "Bullet.h"
#include <memory>

CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::Update(const std::shared_ptr<CharacterBase>& bullets,EnemyData& enemy)
{
    auto Bullets = bullets;
    auto bulletCast = std::dynamic_pointer_cast<Bullet>(bullets);
    
    // 敵が既に当たられているか、弾が発射されていない場合はチェック不要
    if (enemy.isHit || !bulletCast || bulletCast->GetIsShot())
    {
        return;
    }
    
    auto bulletPos = Bullets->GetPosition();
    
    // 弾が画面内かチェック
    bool isInScreen = (bulletPos[0] >= -1.0f && bulletPos[0] <= 1.0f &&
                       bulletPos[1] >= -1.0f && bulletPos[1] <= 1.0f);
    
    if (!isInScreen)
    {
        return;
    }
    
    // AABB当たり判定
    if (bulletPos[0] - bulletCast->GetSize()/2 < enemy.m_posX + enemy.obj_2D->GetSizeValue() &&
        bulletPos[0] + bulletCast->GetSize()/2 > enemy.m_posX - enemy.obj_2D->GetSizeValue() &&
        bulletPos[1] - bulletCast->GetSize()/2 < enemy.m_posY + enemy.obj_2D->GetSizeValue() &&
        bulletPos[1] + bulletCast->GetSize()/2 > enemy.m_posY - enemy.obj_2D->GetSizeValue())
    {
        enemy.isHit = true;
        bulletCast->ClearBullet();  // 弾をリセット
    }
}