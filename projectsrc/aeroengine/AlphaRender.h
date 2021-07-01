#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
namespace Alpha {


	class Renderer
	{
	public:

// ------- Public Functions ---
		void Init();
		void Error(int code,const  char* description);
		void DeInit();
	};


	class Window {
	private:

// ------ Dimensions-----------
		
		const char* Ptitle{ };
		
		const char* vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"	gl_Position = vec4(aPos.x, aPos.y , aPos.z, 1.0);\n"
			"}\0";
		
		const char* fragmentShaderSource = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"	FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
			"}\n\0";
		
		GLfloat vertices[9] =
		{
			-0.5f , -0.5f * float(sqrt(3)) / 3, 0.0f,
			0.5f , -0.5f * float(sqrt(3)) / 3,  0.0f,
			0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
		};

		GLuint vertexShader;
		GLuint fragmentShader;
		GLuint shaderProgram;
		GLuint VAO, VBO;

	public:

//	------ Variables ----------

		bool isOpen        {false};
		unsigned int width { 800 };
		unsigned int height{ 600 };

//  ------ OpenGL Window ------
		GLFWwindow* window{};

		void InitWindow  (GLFWwindow* window);
		void DeInitWindow(GLFWwindow* window);
		void MainLoop    (GLFWwindow* window);
		void ClearColor  (GLfloat r, GLfloat g, GLfloat b, GLfloat transparency);
		void SetTitle    (const char* title);
		void SetWidth    (unsigned int w);
		void Error       (int code, const char* description);
	};

}
