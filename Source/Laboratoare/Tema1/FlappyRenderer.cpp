#include "FlappyRenderer.h"

using namespace std;

FlappyRenderer::FlappyRenderer(vector<glm::vec3> palette) {

	this->palette = palette;
}

FlappyRenderer::~FlappyRenderer() {}

void FlappyRenderer::loadFlyingFlappy() {

	glm::vec3 RGB_black = palette.at(0);
	glm::vec3 RGB_gold = palette.at(1);
	glm::vec3 RGB_tomato = palette.at(2);
	glm::vec3 RGB_yellow = palette.at(3);
	glm::vec3 RGB_lightyellow = palette.at(4);
	glm::vec3 RGB_white = palette.at(5);

	// ROW 1
	vertices.push_back(VertexFormat(glm::vec3(5, 0, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 0, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 1, 0), RGB_black));
	// ROW 2
	vertices.push_back(VertexFormat(glm::vec3(3, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 2, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(5, 1, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(10, 1, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(5, 2, 0), RGB_gold));

	vertices.push_back(VertexFormat(glm::vec3(10, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_black));
	//ROW 3
	vertices.push_back(VertexFormat(glm::vec3(2, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 3, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(3, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(9, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(3, 3, 0), RGB_gold));

	vertices.push_back(VertexFormat(glm::vec3(9, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(15, 2, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(15, 3, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_tomato));

	vertices.push_back(VertexFormat(glm::vec3(15, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 3, 0), RGB_black));
	//ROW 4 
	vertices.push_back(VertexFormat(glm::vec3(2, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 4, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(5, 3, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(8, 3, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(8, 4, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(5, 4, 0), RGB_gold));

	vertices.push_back(VertexFormat(glm::vec3(8, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 4, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_tomato));

	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_black));
	// ROW 5
	vertices.push_back(VertexFormat(glm::vec3(1, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(2, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(5, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(5, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(2, 5, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(5, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 5, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(6, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 5, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(16, 4, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(16, 5, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_tomato));

	vertices.push_back(VertexFormat(glm::vec3(16, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(17, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(17, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 5, 0), RGB_black));
	// ROW 6
	vertices.push_back(VertexFormat(glm::vec3(0, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 6, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(2, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(2, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(1, 6, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(2, 5, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(5, 5, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(5, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(2, 6, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(5, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(5, 6, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(7, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(7, 6, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_black));
	// ROW 7
	vertices.push_back(VertexFormat(glm::vec3(0, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 7, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(1, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(6, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(1, 7, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 7, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(7, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(7, 7, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(9, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(10, 7, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(14, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_black));
	// ROW 8
	vertices.push_back(VertexFormat(glm::vec3(0, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 8, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(1, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(5, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(5, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(1, 8, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(5, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 8, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(6, 7, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 7, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 8, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(8, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(12, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(13, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_black));
	// ROW 9
	vertices.push_back(VertexFormat(glm::vec3(1, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 9, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(5, 8, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(5, 9, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 9, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 9, 0), RGB_black));
	// ROW 10
	vertices.push_back(VertexFormat(glm::vec3(3, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(4, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(4, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 10, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(4, 9, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 9, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(4, 10, 0), RGB_lightyellow));

	vertices.push_back(VertexFormat(glm::vec3(6, 9, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 10, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 10, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 10, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 10, 0), RGB_black));
	// ROW 11
	vertices.push_back(VertexFormat(glm::vec3(4, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(4, 11, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 11, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 11, 0), RGB_lightyellow));

	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 11, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(10, 10, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 10, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 11, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(10, 11, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(12, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 11, 0), RGB_black));
	// ROW 12
	vertices.push_back(VertexFormat(glm::vec3(6, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 12, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 12, 0), RGB_black));

	for (int i = 0; i < 252; i += 4) {

		indices.push_back(i);
		indices.push_back(i + 1);
		indices.push_back(i + 2);

		indices.push_back(i);
		indices.push_back(i + 2);
		indices.push_back(i + 3);
	}
}

void FlappyRenderer::loadFloatingFlappy() {
	glm::vec3 RGB_black = palette.at(0);
	glm::vec3 RGB_gold = palette.at(1);
	glm::vec3 RGB_tomato = palette.at(2);
	glm::vec3 RGB_yellow = palette.at(3);
	glm::vec3 RGB_lightyellow = palette.at(4);
	glm::vec3 RGB_white = palette.at(5);

	// ROW 1
	vertices.push_back(VertexFormat(glm::vec3(5, 0, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 0, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 1, 0), RGB_black));
	// ROW 2
	vertices.push_back(VertexFormat(glm::vec3(3, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 2, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(5, 1, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(10, 1, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(5, 2, 0), RGB_gold));

	vertices.push_back(VertexFormat(glm::vec3(10, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_black));
	//ROW 3
	vertices.push_back(VertexFormat(glm::vec3(2, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 3, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(3, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(9, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(3, 3, 0), RGB_gold));

	vertices.push_back(VertexFormat(glm::vec3(9, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(15, 2, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(15, 3, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_tomato));

	vertices.push_back(VertexFormat(glm::vec3(15, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 3, 0), RGB_black));
	//ROW 4 
	vertices.push_back(VertexFormat(glm::vec3(1, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 4, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(6, 3, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(8, 3, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(8, 4, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(6, 4, 0), RGB_gold));

	vertices.push_back(VertexFormat(glm::vec3(8, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 4, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_tomato));

	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_black));
	// ROW 5
	vertices.push_back(VertexFormat(glm::vec3(0, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 5, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(1, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(2, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(2, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(2, 4, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(5, 4, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(5, 5, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(2, 5, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(5, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(5, 5, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(6, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 5, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(7, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(7, 5, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(16, 4, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(16, 5, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_tomato));

	vertices.push_back(VertexFormat(glm::vec3(16, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(17, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(17, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 5, 0), RGB_black));

	
	// ROW 6
	vertices.push_back(VertexFormat(glm::vec3(0, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 6, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(1, 6, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(7, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(7, 6, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_black));
	// ROW 7
	vertices.push_back(VertexFormat(glm::vec3(1, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 7, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 7, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(9, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(10, 7, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(14, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_black));
	
	// ROW 8
	vertices.push_back(VertexFormat(glm::vec3(1, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 8, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(2, 7, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 7, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(2, 8, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(8, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(12, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(13, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_black));

	// ROW 9
	vertices.push_back(VertexFormat(glm::vec3(2, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 9, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(3, 8, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(4, 8, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(4, 9, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(3, 9, 0), RGB_lightyellow));

	vertices.push_back(VertexFormat(glm::vec3(4, 8, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(4, 9, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 9, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 9, 0), RGB_black));
	
	// ROW 10
	vertices.push_back(VertexFormat(glm::vec3(3, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(4, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(4, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 10, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(4, 9, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 9, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(4, 10, 0), RGB_lightyellow));

	vertices.push_back(VertexFormat(glm::vec3(6, 9, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 10, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 10, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 10, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 10, 0), RGB_black));
	// ROW 11
	vertices.push_back(VertexFormat(glm::vec3(4, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(4, 11, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 11, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 11, 0), RGB_lightyellow));

	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 11, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(10, 10, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 10, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 11, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(10, 11, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(12, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 11, 0), RGB_black));
	// ROW 12
	vertices.push_back(VertexFormat(glm::vec3(6, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 12, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 12, 0), RGB_black));

	for (int i = 0; i < 252; i += 4) {

		indices.push_back(i);
		indices.push_back(i + 1);
		indices.push_back(i + 2);

		indices.push_back(i);
		indices.push_back(i + 2);
		indices.push_back(i + 3);
	}
}

void FlappyRenderer::loadFallingFlappy() {

	glm::vec3 RGB_black = palette.at(0);
	glm::vec3 RGB_gold = palette.at(1);
	glm::vec3 RGB_tomato = palette.at(2);
	glm::vec3 RGB_yellow = palette.at(3);
	glm::vec3 RGB_lightyellow = palette.at(4);
	glm::vec3 RGB_white = palette.at(5);

	// ROW 1
	vertices.push_back(VertexFormat(glm::vec3(5, 0, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 0, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 1, 0), RGB_black));
	// ROW 2
	vertices.push_back(VertexFormat(glm::vec3(1, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 2, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(5, 1, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(10, 1, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(5, 2, 0), RGB_gold));

	vertices.push_back(VertexFormat(glm::vec3(10, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 1, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_black));
	//ROW 3
	vertices.push_back(VertexFormat(glm::vec3(0, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 3, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(1, 2, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(3, 2, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(3, 3, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(1, 3, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(3, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(4, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(4, 3, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(3, 3, 0), RGB_gold));

	vertices.push_back(VertexFormat(glm::vec3(4, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(4, 3, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(5, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(9, 2, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(5, 3, 0), RGB_gold));

	vertices.push_back(VertexFormat(glm::vec3(9, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(10, 2, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(15, 2, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(15, 3, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_tomato));

	vertices.push_back(VertexFormat(glm::vec3(15, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 2, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 3, 0), RGB_black));
	
	//ROW 4 
	vertices.push_back(VertexFormat(glm::vec3(0, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 4, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(1, 3, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(5, 3, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(5, 4, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(1, 4, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(5, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(5, 4, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(6, 3, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(8, 3, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(8, 4, 0), RGB_gold));
	vertices.push_back(VertexFormat(glm::vec3(6, 4, 0), RGB_gold));

	vertices.push_back(VertexFormat(glm::vec3(8, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 4, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 3, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_tomato));

	vertices.push_back(VertexFormat(glm::vec3(10, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 3, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_black));
	
	// ROW 5
	vertices.push_back(VertexFormat(glm::vec3(0, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 5, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(1, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(2, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(2, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(2, 4, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(5, 4, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(5, 5, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(2, 5, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(5, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(5, 5, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(6, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 5, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(7, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 4, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(7, 5, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(10, 4, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(16, 4, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(16, 5, 0), RGB_tomato));
	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_tomato));

	vertices.push_back(VertexFormat(glm::vec3(16, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(17, 4, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(17, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 5, 0), RGB_black));

	// ROW 6
	vertices.push_back(VertexFormat(glm::vec3(0, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 6, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(1, 5, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(1, 6, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(6, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(7, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(7, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(7, 6, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(10, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 5, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(16, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_black));
	// ROW 7
	vertices.push_back(VertexFormat(glm::vec3(1, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 7, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(6, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 6, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 7, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(9, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(10, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 6, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(10, 7, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(14, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 6, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_black));

	// ROW 8
	vertices.push_back(VertexFormat(glm::vec3(1, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 8, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(2, 7, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 7, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(2, 8, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(8, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(12, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(13, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(14, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 7, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_black));

	// ROW 9
	vertices.push_back(VertexFormat(glm::vec3(2, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(2, 9, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(3, 8, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(4, 8, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(4, 9, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(3, 9, 0), RGB_lightyellow));

	vertices.push_back(VertexFormat(glm::vec3(4, 8, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(4, 9, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(8, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(12, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 9, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(13, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(14, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(14, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 8, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(15, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 9, 0), RGB_black));

	// ROW 10
	vertices.push_back(VertexFormat(glm::vec3(3, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(4, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(4, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(3, 10, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(4, 9, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 9, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(4, 10, 0), RGB_lightyellow));

	vertices.push_back(VertexFormat(glm::vec3(6, 9, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(8, 10, 0), RGB_yellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_yellow));

	vertices.push_back(VertexFormat(glm::vec3(8, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(8, 10, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(9, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(13, 10, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(13, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 9, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(14, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 10, 0), RGB_black));
	// ROW 11
	vertices.push_back(VertexFormat(glm::vec3(4, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(4, 11, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(6, 10, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(9, 11, 0), RGB_lightyellow));
	vertices.push_back(VertexFormat(glm::vec3(6, 11, 0), RGB_lightyellow));

	vertices.push_back(VertexFormat(glm::vec3(9, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(10, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(9, 11, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(10, 10, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 10, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(12, 11, 0), RGB_white));
	vertices.push_back(VertexFormat(glm::vec3(10, 11, 0), RGB_white));

	vertices.push_back(VertexFormat(glm::vec3(12, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 10, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(13, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 11, 0), RGB_black));
	// ROW 12
	vertices.push_back(VertexFormat(glm::vec3(6, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 11, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(12, 12, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(6, 12, 0), RGB_black));

	for (int i = 0; i < 260; i += 4) {

		indices.push_back(i);
		indices.push_back(i + 1);
		indices.push_back(i + 2);

		indices.push_back(i);
		indices.push_back(i + 2);
		indices.push_back(i + 3);
	}
}

void FlappyRenderer::loadPipe() {

	glm::vec3 RGB_black = glm::vec3(0, 0, 0);
	glm::vec3 RGB_lightgreen = glm::vec3(0.56f, 0.93f, 0.56f);
	glm::vec3 RGB_lime = glm::vec3(0, 1, 0);
	glm::vec3 RGB_limegreen = glm::vec3(0.2f, 0.8f, 0.2f);

	vertices.push_back(VertexFormat(glm::vec3(0, 0, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 0, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(1, 100, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 100, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(1, 0, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(5, 0, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(5, 100, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(1, 100, 0), RGB_lightgreen));

	vertices.push_back(VertexFormat(glm::vec3(5, 0, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(6, 0, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(6, 100, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(5, 100, 0), RGB_lime));

	vertices.push_back(VertexFormat(glm::vec3(6, 0, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(7, 0, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(7, 100, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(6, 100, 0), RGB_lightgreen));

	vertices.push_back(VertexFormat(glm::vec3(7, 0, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(17, 0, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(17, 100, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(7, 100, 0), RGB_lime));

	vertices.push_back(VertexFormat(glm::vec3(17, 0, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(18, 0, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(18, 100, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(17, 100, 0), RGB_limegreen));

	vertices.push_back(VertexFormat(glm::vec3(18, 0, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(19, 0, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(19, 100, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(18, 100, 0), RGB_lightgreen));

	vertices.push_back(VertexFormat(glm::vec3(18, 0, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(20, 0, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(20, 100, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(18, 100, 0), RGB_limegreen));

	vertices.push_back(VertexFormat(glm::vec3(20, 0, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(21, 0, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(21, 100, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(20, 100, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(0, 100, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(21, 100, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(21, 101, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 101, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(0, 101, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(21, 101, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(21, 102, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(0, 102, 0), RGB_limegreen));

	vertices.push_back(VertexFormat(glm::vec3(-1, 100, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 100, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 110, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(-1, 110, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(21, 100, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(22, 100, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(22, 110, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(21, 110, 0), RGB_black));

	vertices.push_back(VertexFormat(glm::vec3(0, 109, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(21, 109, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(21, 110, 0), RGB_black));
	vertices.push_back(VertexFormat(glm::vec3(0, 110, 0), RGB_black));

	//////

	vertices.push_back(VertexFormat(glm::vec3(0, 102, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(4, 102, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(4, 108, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(0, 108, 0), RGB_lightgreen));

	vertices.push_back(VertexFormat(glm::vec3(4, 102, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(5, 102, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(5, 108, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(4, 108, 0), RGB_lime));

	vertices.push_back(VertexFormat(glm::vec3(5, 102, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(6, 102, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(6, 108, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(5, 108, 0), RGB_lightgreen));

	vertices.push_back(VertexFormat(glm::vec3(6, 102, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(18, 102, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(18, 108, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(6, 108, 0), RGB_lime));

	vertices.push_back(VertexFormat(glm::vec3(18, 102, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(19, 102, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(19, 108, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(18, 108, 0), RGB_limegreen));

	vertices.push_back(VertexFormat(glm::vec3(19, 102, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(20, 102, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(20, 108, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(19, 108, 0), RGB_lightgreen));

	vertices.push_back(VertexFormat(glm::vec3(20, 102, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(21, 102, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(21, 108, 0), RGB_limegreen));
	vertices.push_back(VertexFormat(glm::vec3(20, 108, 0), RGB_limegreen));

	vertices.push_back(VertexFormat(glm::vec3(0, 108, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(16, 108, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(16, 109, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(0, 109, 0), RGB_lightgreen));

	vertices.push_back(VertexFormat(glm::vec3(16, 108, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(17, 108, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(17, 109, 0), RGB_lime));
	vertices.push_back(VertexFormat(glm::vec3(16, 109, 0), RGB_lime));

	vertices.push_back(VertexFormat(glm::vec3(17, 108, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(21, 108, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(21, 109, 0), RGB_lightgreen));
	vertices.push_back(VertexFormat(glm::vec3(17, 109, 0), RGB_lightgreen));

	for (int i = 0; i < 260; i += 4) {

		indices.push_back(i);
		indices.push_back(i + 1);
		indices.push_back(i + 2);

		indices.push_back(i);
		indices.push_back(i + 2);
		indices.push_back(i + 3);
	}
}

void FlappyRenderer::loadGround() {

	glm::vec3 RGB_grass = glm::vec3(0.376, 0.502, 0.22);
	glm::vec3 RGB_sand = glm::vec3(0.761, 0.698, 0.502);

	vertices.push_back(VertexFormat(glm::vec3(0, 0, 0), RGB_sand));
	vertices.push_back(VertexFormat(glm::vec3(400, 0, 0), RGB_sand));
	vertices.push_back(VertexFormat(glm::vec3(400, 20, 0), RGB_sand));
	vertices.push_back(VertexFormat(glm::vec3(0, 20, 0), RGB_sand));

	vertices.push_back(VertexFormat(glm::vec3(0, 20, 0), RGB_grass));
	vertices.push_back(VertexFormat(glm::vec3(400, 20, 0), RGB_grass));
	vertices.push_back(VertexFormat(glm::vec3(400, 22, 0), RGB_grass));
	vertices.push_back(VertexFormat(glm::vec3(0, 22, 0), RGB_grass));

	for (int i = 0; i < 8; i += 4) {

		indices.push_back(i);
		indices.push_back(i + 1);
		indices.push_back(i + 2);

		indices.push_back(i);
		indices.push_back(i + 2);
		indices.push_back(i + 3);
	}
}

vector<VertexFormat> FlappyRenderer::getVertices() {

	return vertices;
}
vector<unsigned short> FlappyRenderer::getIndices() {

	return indices;

}
void FlappyRenderer::clearMesh() {

	vertices.clear();
	indices.clear();
}
