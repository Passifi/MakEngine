#include "Mesh.h"
#include <iostream>

Mesh::Mesh(std::vector<float> vertices)
{
	type = MeshType::Vertices;
	this->vertices = vertices;
	this->indices = {};
	this->ID = 0;
	this->eboId = 0;
	this->vboId = 0;
}

Mesh::Mesh(std::vector<float> vertices, std::vector<int> indices) : vertices(vertices), indices(indices) {
	type = MeshType::Indices;
	this->ID = 0;
	this->eboId = 0;
	this->vboId = 0;

}

bool Mesh::initialize() {
	
	
	bool success = true;
	if (vertices.size() == 0) {
		std::cout << "No vertex data present. Please provide Vertex Data" << std::endl;
		return false;
	}
	
	if(type == MeshType::Indices) {
		unsigned int vbo,vao,ebo;
		glGenBuffers(1,&vbo);
		glGenBuffers(1,&ebo);
		glCreateBuffers(1,&vao);

		glBindBuffer(GL_DRAW_BUFFER,vbo);
		glBindBuffer(GL_VERTEX_ARRAY,vao);
			
		glBufferData(GL_DRAW_BUFFER,vertices.size()*sizeof(float),vertices.data(),0);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()*sizeof(int),indices.data(),0);
		// todo binding vertex attrib pointers


	}
	
	return success;

}
