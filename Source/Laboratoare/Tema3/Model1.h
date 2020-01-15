#pragma once
#include <vector>
#include <Core/Engine.h>

using namespace std;

class Model1 {

private:

	vector<glm::vec3> vertices;
	vector<unsigned short> indices;
	vector<glm::vec3> normals;
	vector<glm::vec2> tex_coords;

public:

	Model1();
	~Model1();
	void loadTerrain(int minh, int maxh, int minw, int maxw);
	vector<glm::vec3> getVertices();
	vector<unsigned short> getIndices();
	vector<glm::vec3> getNormals();
	vector<glm::vec2> getTexCoords();
	void clearMesh();
};

