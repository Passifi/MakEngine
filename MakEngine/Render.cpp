#include "Render.h"

void Renderer::render(GLFWwindow* window, Camera& camera)
{
	glClearColor(0.0f,0.0f,0.0f,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto el : graphics) {
		el->draw();
	}
}
