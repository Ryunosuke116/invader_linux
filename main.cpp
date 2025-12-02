#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <memory>
#include "triangle.h"
#include "Render.h"

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

    GLfloat points[] = { 0.5f, 0.5f, 0.3f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f };

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
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), points, GL_STATIC_DRAW); //配列pointsの値をGPUに伝える


	//  頂点配列オブジェクト（Vertex Array Object）作成
	// VAOは、VBOから頂点シェーダへの入力変数としてどのデータを使用するかを定義するDescriptorです。
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    GLint shader = makeShader();
    std::shared_ptr<Render> render = std::make_shared<Render>();
    render->Initialize("png/free-png-4.png");
    
    //メインループ
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shader);
        glBindVertexArray(vao);

        // 現在選択されているシェーダーで、VAO上のオブジェクトを描画する
		// VBOに格納されたpointsデータの0番目から描画し、3頂点分だけ描画する
		glDrawArrays(GL_TRIANGLES, 0, 3);

        render->Update("png/free-png-4.png");

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}