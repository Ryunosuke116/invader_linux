// #include"Bullet.h"
// ///////////////////////////////////////////////
// //次やること
// //弾のポジション　移動処理
// //
// //
// //
// //
// ///////////////////////////////////////////////
// BulletManager::BulletManager():mpBullet()
// {

// }

// BulletManager::~BulletManager()
// {

// }

// void BulletManager::Initialize()
// {

// }

// void BulletManager::Update()
// {
// for (std::list<Bullet*>::iterator itr = mpBullet.begin(); itr != mpBullet.end();itr++)
// {
//     if((*itr) != nullptr)
//     {
//         (*itr)->Update();
//     }
// }
//  DeleteBullet();
// }


// void BulletManager::Finalize()
// {
//     for(std::list<Bullet*>::iterator itr = mpBullet.begin(); itr != mpBullet.end(); itr++)
//     {
//         if((*itr)== nullptr)
//         {
//             continue;
//         }

//         (*itr)->Finalize();
//         delete (*itr);
//     }
//     mpBullet.clear();
// }


// void BulletManager::Shot()
// {
//     mpBullet.push_back(new Bullet());
//     std::list<Bullet*>::iterator itr =mpBullet.end();
//     itr--;
//     (*itr)->Initialize();
// }

// void BulletManager::DeleteBullet()
// {
//     for(std::list<Bullet*>::iterator itr = mpBullet.begin(); itr != mpBullet.end();)
//     {
//         if((*itr) == nullptr)
//         {
//             itr++;
//             continue;
//         }
  
//     if(
//          (*itr)->GetPos().mX < -50 ||
//             (*itr)->GetPos().mX > 850 ||
//             (*itr)->GetPos().mY < -50 ||
//             (*itr)->GetPos().mY > 600)
//             {
//                 (*itr)->Finalize();
//                 delete (*itr);
//                 (*itr)= nullptr;
//                 itr = mpBullet.erase(itr);
//                 continue;
//             }
//             itr++;
//     }
// }
// Bullet::Draw()
// {

// }