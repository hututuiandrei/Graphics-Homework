#include <iostream>

#include "Model1.h"
#define PI 3.14159265

using namespace std;

Model1::Model1() {}

Model1::~Model1() {}


vector<glm::vec3> Model1::getVertices() {

	return vertices;
}
vector<unsigned short> Model1::getIndices() {

	return indices;
}

vector<glm::vec3> Model1::getNormals() {

	return normals;
}

vector<glm::vec2> Model1::getTexCoords() {

	return tex_coords;
}


void Model1::loadTerrain(int minHeight, int maxHeight, int minWidth, int maxWidth) {

	int counter = 0;

	for (int j = minHeight; j < maxHeight; j++) {

		for (int i = minWidth; i < maxWidth; i++) {

			vertices.push_back(glm::vec3(i, 0, j));
			vertices.push_back(glm::vec3(1 + i, 0, j));
			vertices.push_back(glm::vec3(1 + i, 0, 1 + j));
			vertices.push_back(glm::vec3(i, 0, 1 + j));

			indices.push_back(0 + counter);
			indices.push_back(1 + counter);
			indices.push_back(2 + counter);

			indices.push_back(2 + counter);
			indices.push_back(3 + counter);
			indices.push_back(0 + counter);

			counter += 4;

			normals.push_back(glm::vec3(0, 1, 1));
			normals.push_back(glm::vec3(1, 0, 1));
			normals.push_back(glm::vec3(1, 0, 0));
			normals.push_back(glm::vec3(0, 1, 0));

			tex_coords.push_back(glm::vec2(0, 0));
			tex_coords.push_back(glm::vec2(0, 1));
			tex_coords.push_back(glm::vec2(1, 1));
			tex_coords.push_back(glm::vec2(1, 0));
		}
	}
}


void Model1::clearMesh() {

	vertices.clear();
	indices.clear();
	normals.clear();
	tex_coords.clear();
}
