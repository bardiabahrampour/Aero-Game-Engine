#include "AlphaRender.h"

//--------- Error Handler ------------------------
void Alpha::Renderer::Error(int code, const char* description) {

	std::cout << "FATAL ERROR: Renderer Error: " << description << "Code: " << code << "\n";

	exit(code);
}




// -------- Init Function-------------------------
void Alpha::Renderer::Init() {


	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}


//---------------- DeInit-------------------------
void Alpha::Renderer::DeInit() {



	glfwTerminate();

}

//----------- Init Window ------------------------
void Alpha::Window::InitWindow(GLFWwindow* window) {

	window = glfwCreateWindow(width, height, Ptitle, NULL, NULL);
	
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, width, height);


	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	if (window == NULL) {

		Error(-10, "Failed to Initialize Window ");

	}
	while (!glfwWindowShouldClose(window)) {

		isOpen = true;
		MainLoop(window);

	}

	isOpen = false;
}

//---------------- Deinit Window------------------
void Alpha::Window::DeInitWindow(GLFWwindow* window) {

	isOpen = false;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	glfwDestroyWindow(window);

}

//---------------- Window Errror-------------------
void Alpha::Window::Error(int code, const char* description) {

	std::cout << "FATAL ERROR: Renderer Error: " << description << "Code: " << code << "\n";

	exit(code);
}

//------------- Main Loop -------------------------
void Alpha::Window::MainLoop(GLFWwindow* window) {

	glfwPollEvents();
	ClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glfwSwapBuffers(window);
}

//------------ Clear Color ------------------------
void Alpha::Window::ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat transparency) {

	glClearColor(r, g, b, transparency);
	glClear(GL_COLOR_BUFFER_BIT);
}

//----------- Set Title --------------------------
void Alpha::Window::SetTitle(const char* title) {

	Ptitle = title;

}

//------ Set Window Width -----------------------
void Alpha::Window::SetWidth(unsigned int w) {

	width = w;

}