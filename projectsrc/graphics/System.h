#pragma once
#include "api.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class _API System {
	void setVersion();
	void loadGlad();
	void Crash();
	void (*m_error_callback)(int, const char*) = nullptr;
	void (*loop)(void) = nullptr;
	void (*input)(GLFWwindow*,int,int,int,int) = nullptr;
	GLFWwindow* win = nullptr;
	int width = 0, height = 0;
	const char* title;
public:
	System(int w, int h, const char* title);
	~System();
	void setGlErrorCallback(void (*error_callback)(int, const char*));
	void setLoop(void (*ploop)(void));
	void setInput(void (*pinput)(GLFWwindow*,int,int,int,int));
	GLFWwindow* getWindow();
	void init();
	void exit();
};

namespace Callbacks {
	void framebuff_callback(GLFWwindow* window, int width, int height);
};