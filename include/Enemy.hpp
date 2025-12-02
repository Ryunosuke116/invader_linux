#pragma once
#include "CharacterBase.hpp"

class Enemy : public CharacterBase
{
    public:
    Enemy();
    ~Enemy();

    void Update() override;

    void  Draw() override;

    private:

};