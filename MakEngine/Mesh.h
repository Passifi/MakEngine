#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

enum MeshType {
	Indices,
	Vertices
};

class Mesh {
	public:
	Mesh(std::vector<float> vertices);
	Mesh(std::vector<float> vertices, std::vector<int> indices);
	bool initialize();
	void use();

	private:
			
	int ID;
	int eboId,vboId;	
	MeshType type;
	std::vector<float> vertices;
	std::vector<int> indices;
};
