// #pragma once
// #include<list>
// #include<iostream>
// class Bullet;
// struct Vector3
// {
//     float mX;
//     float mY;
//     float mZ;
// };

// class BulletManager
// {
//     private:
//     std::list<Bullet*>mpBullet;
//     public:
//     BulletManager();
//     ~BulletManager();

//     void Initialize();//初期化
//     void Update();//弾の更新
//     void Draw();//弾の描画
//     void Finalize();//弾の終了処理
//     void Shot();//弾を発射する
//     private:
//     void DeleteBullet();


// };

// class Bullet
// {
//     private:
//     Vector3 mPos;
//     float mSpeedX;
//     float mSpeedY;
//     bool mActive;

//     public:
//     Bullet();
//     ~Bullet();
//     void Initialize(float startX=0. float startY,float speedX,float speedY=-5);
//     void Update();
//     void Draw();
//     void Finalize();


//     Vector3 GetPos const {return mPos}
//     bool IsActive()const {return mActive}
//     void SetActive(bool flag){mactive=flag} 

// };
