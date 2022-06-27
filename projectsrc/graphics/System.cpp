#include "pch.h"
#include "System.h"

/*
==========================================
Error Callback MUST call System::Crash
so that the glfw context is terminated
or it will cause a memmory leak.
==========================================
Input Manager is setup before the graphics
and should set it's callback to the base
graphics system.
==========================================

*/



System::System(int w, int h, const char* title) :
	width(w),
	height(h),
	title(title)
{

}

void System::init() {
	glfwInit();
	glfwSetErrorCallback(m_error_callback);
	this->setVersion();
	this->win =
		glfwCreateWindow(this->width, this->height, this->title, nullptr, nullptr);
	if (win == nullptr) {
		m_error_callback(1, "Failed to create window");
		this->Crash();
	}
	glfwMakeContextCurrent(this->win);
	glfwSetFramebufferSizeCallback(this->win, Callbacks::framebuff_callback);
	glfwSetKeyCallback(this->win, this->input);
	this->loadGlad();

	while (!glfwWindowShouldClose(this->win)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		this->loop();
		glfwSwapBuffers(this->win);
		glfwPollEvents();
	}
}

void System::setVersion() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void System::loadGlad() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		m_error_callback(2, "Glad failed to initialize");
		this->Crash();
	}
}

void System::setGlErrorCallback(void (*error_callback)(int, const char*)) {
	m_error_callback = error_callback;
	glfwSetErrorCallback(m_error_callback);
}

void Callbacks::framebuff_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

System::~System() {
	glfwTerminate();
}

void System::Crash() {
	glfwTerminate();
}

void System::setLoop(void (*ploop)(void)) {
	this->loop = ploop;
}

void System::setInput(void (*pinput)(GLFWwindow*,int,int,int,int)) {
	this->input = pinput;
}

void System::exit() {
	glfwSetWindowShouldClose(this->win, true);
}

GLFWwindow* System::getWindow() {
	return this->win;
}