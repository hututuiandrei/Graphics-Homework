#pragma once
#include <vector>
#include <Core/Engine.h>

using namespace std;

class Model {

private:

	vector<VertexFormat> vertices;
	vector<unsigned short> indices;

public:

	Model();
	~Model();
	void loadCube(float x, float y, float z, float h, float w, float d, glm::vec3 color, float trap);
	void loadBasicCube();
	void loadPlaneBody();
	void loadPlanePropeller();
	void loadOcean(float oceanRadius);
	void loadTetra();
	vector<VertexFormat> getVertices();
	vector<unsigned short> getIndices();
	void clearMesh();
};

