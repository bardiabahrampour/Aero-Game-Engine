#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <Windows.h>
#ifdef F
void glerror(int error, const char* description) {
	MessageBoxA(nullptr, "Fatal Error", "Error: " + *description, MB_OK | MB_ICONERROR | MB_TASKMODAL);
}

void framebuff_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int _stdcall wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "The Battle of Kings", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuff_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		OutputDebugStringA("well damn...\n");
		return 2;
	}

	while (!glfwWindowShouldClose(window)) {
		process_input(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
#else
#include "../graphics/System.h"

void input(GLFWwindow* win, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		
	}
}

void glerror(int error, const char* description) {
	MessageBoxA(nullptr, "Fatal Error", "Error: " + *description, MB_OK | MB_ICONERROR | MB_TASKMODAL);
}

void loop(void) {
	OutputDebugStringA("loop running\n");
}

int _stdcall wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd) 
{
	System sys(800,600,"Test");
	sys.setInput(process_input);
	sys.setGlErrorCallback(glerror);
	sys.setLoop(loop);
	sys.init();
}
#endif
