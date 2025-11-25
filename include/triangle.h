#pragma once
#include <GLFW/glfw3.h>

GLint makeShader() {
	// 頂点シェーダ作成（vertexshader.shaderみたいに別ファイルを作って読み込む方法もある)
	// シェーダーの言語はGLSLというらしい
	const char* vertex_shader =
		"#version 400\n" //GLSLのバージョン
		"in vec3 vp;" //入力
		"void main() {" //拡張店ごとにmain()関数が実行される
		"  gl_Position = vec4(vp, 1.0);" //gl_Positionは4変数ベクトルで、（x,y,z,w）となる（wはとりあえず1にしておけばいい。それ以外の場合は、x = x/wのようになる）
		"}";
	
	//フラグメントシェーダ作成
	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;" //出力値はその場所の色（R,G,B,A)を表す。それぞれ　0.0（透明or色なし）～1.0（不透明or色あり）の小数点で設定する
		"void main() {"
		"  frag_colour = vec4(0.5, 1.0, 0.5, 1.0);" //
		"}";

	GLuint vs, fs;
	GLuint shader_programme;


	//上のシェーダープログラムをコンパイルする。
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);
	shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	return shader_programme;
}
