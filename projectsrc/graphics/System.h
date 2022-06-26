#pragma once
#include "api.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class _API System {
	void init(int &w, int &h, const char* &title);
	void setVersion();
	void loadGlad();
	void Crash();
	void (*m_error_callback)(int, const char*);
	void (*loop)(void);
	void (*input)(GLFWwindow*);
	GLFWwindow* win;
	int width, height;
	const char* title;
public:
	System(int w, int h, const char* title);
	~System();
	void setGlErrorCallback(void (*error_callback)(int, const char*));
	void setLoop(void (*ploop)(void));
	void setInput(void (*pinput)(GLFWwindow*));
};

namespace Callbacks {
	void framebuff_callback(GLFWwindow* window, int width, int height);
};