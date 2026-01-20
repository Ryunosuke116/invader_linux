#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "triangle.h"
#include "Render.h"
#include "Object2D.h"
#include "CharacterBase.hpp"
#include "Enemy.hpp"
#include "Player.h"
#include "GameScene.hpp"
#include"Bullet.h"
 

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    //glfwの初期化
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLuint vao;
	GLuint vbo;

    GLfloat points[] = { 
        0.5f, 0.5f, 0.0f, 
        0.5f, -0.5f, 0.0f, 
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f };

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //window画面の生成
    GLFWwindow* window = glfwCreateWindow(800, 600, "inverder", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }

    //機能を生成したwindowに適用させる
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    glEnable(GL_DEPTH_TEST); // Viewerに近い部分を表示する（描画の順番ではなくZ座標を考慮する）
	glDepthFunc(GL_LESS);

	// 頂点バッファオブジェクト（Vertex Buffer Object）作成
	// VBOとは頂点データや色データ、indexデータなどをGPUに伝えるための道？みたいなもの（？）
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), points, GL_STATIC_DRAW); //配列pointsの値をGPUに伝える


	//  頂点配列オブジェクト（Vertex Array Object）作成
	// VAOは、VBOから頂点シェーダへの入力変数としてどのデータを使用するかを定義するDescriptorです。
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    GLint shader = makeShader();

    std::shared_ptr<Render> render = std::make_shared<Render>();

    std::shared_ptr<Object2D> object = std::make_shared<Object2D>();
    std::shared_ptr<Object2D> object_1 = std::make_shared<Object2D>();
    std::shared_ptr<Object2D> object_2 = std::make_shared<Object2D>();

    std::shared_ptr<CharacterBase> enemy        = std::make_shared<Enemy>();
    std::shared_ptr<Enemy>         actualEnemy  = std::dynamic_pointer_cast<Enemy>(enemy);

    std::shared_ptr<GameScene> gameScene = std::make_shared<GameScene>();
    //1月13日追加
    std::shared_ptr<CharacterBase> player = std::make_shared<Player>();
    std::shared_ptr<Player> actualPlayer =  std::dynamic_pointer_cast<Player>(player);

    PointXY objectXY = {0.0f,0.0f};
    PointXY objectXY_1 = {0.0f,0.0f};
    PointXY objectXY_2 = {0.0f,0.0f};

    render->Initialize("../png/test.png");
    // GameScene->Initialize();
    
    enemy->Initialize();
    player->Initialize();
 

    //メインループ
    while (!glfwWindowShouldClose(window)) {
        
        glfwPollEvents();//入力の取得するための関数

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shader);
        glBindVertexArray(vao);
        
        enemy->Update();
        actualPlayer->Update(window);
        std::shared_ptr<Bullet> actualBullet = std::dynamic_pointer_cast<Bullet>(actualPlayer->GetBullet());
        actualBullet->Draw(*render);

        //render->SetPosition(enemy->GetPosition());
        render->SetPosition(player->GetPosition());
        for (auto& enemyData : actualEnemy->GetEnemys())
        {
            render->SetPosition(enemyData.obj_2D->GetGLfloat());
        }

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
	    glBufferData(
            GL_ARRAY_BUFFER,
             render->GetPosition().size() * sizeof(GLfloat),
              render->GetPosition().data(), 
              GL_STATIC_DRAW); 

        render->Draw();
        render->ResetPosition();

        gameScene->Update();
        gameScene->Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
 