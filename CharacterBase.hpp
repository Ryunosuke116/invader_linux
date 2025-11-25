class CharacterBase
{
    public:
    CharacterBase()
    virtual~CharacterBase() = default;

    virtual void Create();

    virtual void Initialize();

    virtual void Update() abstruct;

    virtual void Move() abstruct;
    virtual void Shot() abstruct;
    virtual void Draw() abstruct;

    private:
    static constexpr int MAX_HP = 3;
    int m_posX;
    int m_posY;
    int m_velocity;
    int m_hp;
    bool m_isActive;
    bool m_isShot;

}