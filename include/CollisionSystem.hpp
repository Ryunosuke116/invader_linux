#pragma once 
#include <memory>

class CharacterBase;
class Bullet;
struct EnemyData;

class  CollisionSystem
{
    public:
    CollisionSystem();
    ~CollisionSystem();

    void Update(const std::shared_ptr<CharacterBase>& bullets, EnemyData& enemy);
    
    private:
};