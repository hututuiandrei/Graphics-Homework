#pragma once

#include <include/glm.h>
#include <math.h>

namespace Transform2D {

	// Translate matrix
	inline glm::mat3 Translate(float tX, float tY) {

		return glm::mat3(
			1, 0, 0,
			0, 1, 0,
			tX, tY, 1);
	}

	// Scale matrix
	inline glm::mat3 Scale(float sX, float sY) {

		return glm::mat3(
			sX, 0, 0,
			0, sY, 0,
			0, 0, 1);
	}

	// Rotate matrix
	inline glm::mat3 Rotate(float radians) {

		return glm::mat3(
			cos(radians), sin(radians), 0,
			-sin(radians), cos(radians), 0,
			0, 0, 1);
	}
}