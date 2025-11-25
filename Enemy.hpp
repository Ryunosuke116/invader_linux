
#include "CharacterBase.hpp"

class CharacterBase;

class Enemy : public CharacterBase
{
    public:
    Enemy();
    ~Enemy()override;

    void Update() override;

    void  Draw() override;

    private:

}