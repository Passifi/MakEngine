#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include "Graphic.h"
#include "Camera.h"
class Renderer {
	
	public:
		void render(GLFWwindow* window,Camera& camera);
		std::vector<Graphic*> graphics;	
		
		
};
