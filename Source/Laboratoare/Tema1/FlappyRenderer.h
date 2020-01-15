#pragma once
#include <vector>
#include <Core/Engine.h>

using namespace std;

class FlappyRenderer {

private:

	vector<glm::vec3> palette;
	vector<VertexFormat> vertices;
	vector<unsigned short> indices;

public:

	FlappyRenderer(vector<glm::vec3> palette);
	~FlappyRenderer();
	void loadFlyingFlappy();
	void loadFloatingFlappy();
	void loadFallingFlappy();
	void loadPipe();
	void loadGround();
	vector<VertexFormat> getVertices();
	vector<unsigned short> getIndices();
	void clearMesh();
};

