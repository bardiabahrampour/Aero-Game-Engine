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
		void Error(int code, const char* description);

	public:

//	------ Variables ----------

		bool isOpen{ false };
		unsigned int width{ 800 };
		unsigned int height{ 600 };

//  ------ OpenGL Window ------
		GLFWwindow* window{};

		void InitWindow(GLFWwindow* window);
		void DeInitWindow(GLFWwindow* window);
		void MainLoop(GLFWwindow* window);
		void ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat transparency);
		void SetTitle(const char* title);
		void SetWidth(unsigned int w);
	};

}
