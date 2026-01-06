#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define Screen_Width 1200
#define Screen_Height 800

void frameBufferResizeCallback(GLFWwindow* window, int width, int height);

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(Screen_Width,Screen_Height,"LearnOpenGL",NULL,NULL);
	
	if (window == nullptr) {
		std::cout << "Failed to create a window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	
	glViewport(0,0, Screen_Width,Screen_Height);
	glfwSetFramebufferSizeCallback(window,frameBufferResizeCallback);
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}

void frameBufferResizeCallback(GLFWwindow* window, int width, int height)
{

	glViewport(0,0,width,height);

}
