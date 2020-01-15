#include <iostream>

#include "Model.h"
#define PI 3.14159265

using namespace std;

Model::Model() {}

Model::~Model() {}


vector<VertexFormat> Model::getVertices() {

	return vertices;
}
vector<unsigned short> Model::getIndices() {

	return indices;
}
void Model::loadCube(float x, float y, float z, float h, float w, float d, glm::vec3 color, float trap) {

	glm::vec3 RGB_color = color;

	int offset = vertices.size();

	float off1 = 0;
	float off2 = 0;

	if (trap == 1) {

		off1 = 0.75f;
		off2 = 0.25f;
	}

	int counter = 0;

	glm::vec3 cube000 = glm::vec3(x, y + off1, z - off2);
	glm::vec3 cube100 = glm::vec3(x + h, y, z);
	glm::vec3 cube110 = glm::vec3(x + h, y + w, z);
	glm::vec3 cube010 = glm::vec3(x, y + w, z - off2);

	glm::vec3 cube001 = glm::vec3(x, y + off1, z - d + off2);
	glm::vec3 cube101 = glm::vec3(x + h, y, z - d);
	glm::vec3 cube111 = glm::vec3(x + h, y + w, z - d);
	glm::vec3 cube011 = glm::vec3(x, y + w, z - d + off2);

	glm::vec3 norm = glm::normalize(glm::cross(cube100 - cube000, cube110 - cube000));

	vertices.push_back(VertexFormat(cube000, RGB_color, norm));
	vertices.push_back(VertexFormat(cube100, RGB_color, norm));
	vertices.push_back(VertexFormat(cube110, RGB_color, norm));
	vertices.push_back(VertexFormat(cube010, RGB_color, norm));

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 1);
	indices.push_back(offset + counter + 2);

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 2);
	indices.push_back(offset + counter + 3);

	counter += 4;

	norm = glm::normalize(glm::cross(cube111 - cube001, cube101 - cube001));

	vertices.push_back(VertexFormat(cube001, RGB_color, norm));
	vertices.push_back(VertexFormat(cube101, RGB_color, norm));
	vertices.push_back(VertexFormat(cube111, RGB_color, norm));
	vertices.push_back(VertexFormat(cube011, RGB_color, norm));

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 2);
	indices.push_back(offset + counter + 1);

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 3);
	indices.push_back(offset + counter + 2);

	
	counter += 4;

	norm = glm::normalize(glm::cross(cube101 - cube100, cube111 - cube100));

	vertices.push_back(VertexFormat(cube100, RGB_color, norm));
	vertices.push_back(VertexFormat(cube101, RGB_color, norm));
	vertices.push_back(VertexFormat(cube111, RGB_color, norm));
	vertices.push_back(VertexFormat(cube110, RGB_color, norm));

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 1);
	indices.push_back(offset + counter + 2);

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 2);
	indices.push_back(offset + counter + 3);

	counter += 4;

	norm = glm::normalize(glm::cross(cube011 - cube000, cube001 - cube000));

	vertices.push_back(VertexFormat(cube000, RGB_color, norm));
	vertices.push_back(VertexFormat(cube001, RGB_color, norm));
	vertices.push_back(VertexFormat(cube011, RGB_color, norm));
	vertices.push_back(VertexFormat(cube010, RGB_color, norm));

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 2);
	indices.push_back(offset + counter + 1);

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 3);
	indices.push_back(offset + counter + 2);

	counter += 4;

	norm = glm::normalize(glm::cross(cube110 - cube010, cube111 - cube010));

	vertices.push_back(VertexFormat(cube010, RGB_color, norm));
	vertices.push_back(VertexFormat(cube110, RGB_color, norm));
	vertices.push_back(VertexFormat(cube111, RGB_color, norm));
	vertices.push_back(VertexFormat(cube011, RGB_color, norm));

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 1);
	indices.push_back(offset + counter + 2);

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 2);
	indices.push_back(offset + counter + 3);

	counter += 4;

	norm = glm::normalize(glm::cross(cube101 - cube000, cube100 - cube000));

	vertices.push_back(VertexFormat(cube000, RGB_color, norm));
	vertices.push_back(VertexFormat(cube100, RGB_color, norm));
	vertices.push_back(VertexFormat(cube101, RGB_color, norm));
	vertices.push_back(VertexFormat(cube001, RGB_color, norm));

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 2);
	indices.push_back(offset + counter + 1);

	indices.push_back(offset + counter);
	indices.push_back(offset + counter + 3);
	indices.push_back(offset + counter + 2);

	
}

void Model::loadBasicCube() {

	loadCube(-0, 0, 0, 1, 1, 1, glm::vec3(0.81, 0.85, 0.92), 0);
}

void Model::loadPlaneBody() {

	loadCube(-0.95f, 0.45f, -0.55f, 0.1f, 0.5f, 0.1f, glm::vec3(1, 0, 0), 0);
	loadCube(-0.95f, 0.45f, -0.35f, 0.1f, 0.5f, 0.1f, glm::vec3(1, 0, 0), 0);
	loadCube(-1, 0.4f, -0.45f, 0.2f, 0.2f, 0.1f, glm::vec3(0, 1, 0), 0);
	loadCube(-1.2f, 1, - 0.45f, 0.4f, 0.4f, 0.1f, glm::vec3(1, 1, 0), 0);
	loadCube(-1, 0, 0, 1, 1, 1, glm::vec3(1, 0, 0), 1);

	loadCube(-0.5f, 0.9f, 1, 0.75f, 0.1f, 3, glm::vec3(1, 0, 0), 0);

	loadCube(0.66f, 0, 0, 0.34f, 1, 1, glm::vec3(1, 1, 1), 0);
	loadCube(0, 0, 0, 0.66f, 1, 1, glm::vec3(1, 0, 0), 0);
	loadCube(0, -0.3f, -0.1f, 0.66f, 0.3f, 0.1f, glm::vec3(0, 1, 0), 0);
	loadCube(0, -0.3f, -0.8f, 0.66f, 0.3f, 0.1f, glm::vec3(0, 1, 0), 0);

	loadCube(1, 0.45f, -0.45f, 0.1f, 0.1f, 0.1f, glm::vec3(0, 1, 0), 0);
}

void Model::loadPlanePropeller() {

	loadCube(1.1f, -0.2f, -0.45f, 0.02f, 1.4f, 0.1f, glm::vec3(0, 1, 0), 0);
	loadCube(1.1f, 0.45f, 0.2f, 0.02f, 0.1f, 1.4f, glm::vec3(0, 1, 0), 0);
}

void Model::loadTetra() {

	glm::vec3 RGB_Color = glm::vec3(0, 0.6, 0);

	glm::vec3 lb = glm::vec3(0, 0, 0);
	glm::vec3 rb = glm::vec3(1, 0, 0);
	glm::vec3 t = glm::vec3(0.5f, 1, 0);
	glm::vec3 h = glm::vec3(0.5f, 0.5f, 1);

	glm::vec3 norm = glm::normalize(glm::cross(rb - lb, t - lb));

	vertices.push_back(VertexFormat(lb, RGB_Color, norm));
	vertices.push_back(VertexFormat(rb, RGB_Color, norm));
	vertices.push_back(VertexFormat(h, RGB_Color, norm));

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	norm = glm::normalize(glm::cross(t - rb, h - rb));

	vertices.push_back(VertexFormat(rb, RGB_Color, norm));
	vertices.push_back(VertexFormat(t, RGB_Color, norm));
	vertices.push_back(VertexFormat(h, RGB_Color, norm));

	indices.push_back(3);
	indices.push_back(4);
	indices.push_back(5);

	norm = glm::normalize(glm::cross(h - lb, t - lb));

	vertices.push_back(VertexFormat(lb, RGB_Color, norm));
	vertices.push_back(VertexFormat(t, RGB_Color, norm));
	vertices.push_back(VertexFormat(h, RGB_Color, norm));

	indices.push_back(6);
	indices.push_back(8);
	indices.push_back(7);
}

void Model::loadOcean(float oceanRadius) {

	glm::vec3 RGB_Water = glm::vec3(0, 0.46f, 0.74f);

	int sides = 20;
	int n = 10;

	int counter = 0;

	for (int i = 0; i < sides; i++) {

		for (int j = 0; j < n; j++) {

			float vertX, vertY, vertZ;

			glm::vec3 lb, rb, lt, rt;

			vertX = oceanRadius * sin(2 * i * PI / sides);
			vertY = -j * 10;
			vertZ = oceanRadius * cos(2 * i * PI / sides);

			lb = glm::vec3(vertX, vertY, vertZ);

			vertX = oceanRadius * sin(2 * (i + 1) * PI / sides);
			vertY = -j * 10;
			vertZ = oceanRadius * cos(2 * (i + 1) * PI / sides);
	
			rb = glm::vec3(vertX, vertY, vertZ);

			vertX = oceanRadius * sin(2 * i * PI / sides);
			vertY = - (j + 1) * 10;
			vertZ = oceanRadius * cos(2 * i * PI / sides);

			lt = glm::vec3(vertX, vertY, vertZ);

			vertX = oceanRadius * sin(2 * (i + 1) * PI / sides);
			vertY = -(j + 1) * 10;
			vertZ = oceanRadius * cos(2 * (i + 1) * PI / sides);

			rt = glm::vec3(vertX, vertY, vertZ);

			glm::vec3 norm = glm::normalize(glm::cross(rt - lb, rb - lb));

			vertices.push_back(VertexFormat(lb, RGB_Water, norm));
			vertices.push_back(VertexFormat(rb, RGB_Water, norm));
			vertices.push_back(VertexFormat(lt, RGB_Water, norm));
			vertices.push_back(VertexFormat(rt, RGB_Water, norm));

			indices.push_back(counter);
			indices.push_back(counter + 3);
			indices.push_back(counter + 1);
			
			indices.push_back(counter);
			indices.push_back(counter + 2);
			indices.push_back(counter + 3);			

			counter += 4;
		}
	}
	
}

void Model::clearMesh() {

	vertices.clear();
	indices.clear();
}
