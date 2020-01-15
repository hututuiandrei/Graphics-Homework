#pragma once

#include <include/glm.h>
#include <math.h>

namespace Transform3D
{
	// Translate matrix
	inline glm::mat4 Translate(float tX, float tY, float tZ)
	{
		// TODO implement translate matrix
		return glm::mat4(1, 0, 0, 0,
						 0, 1, 0, 0,
						 0, 0, 1, 0,
						 tX, tY, tZ, 1);
	}

	// Scale matrix
	inline glm::mat4 Scale(float sX, float sY, float sZ)
	{
		// TODO implement scale matrix
		return glm::mat4(sX, 0, 0, 0,
						 0, sY, 0, 0,
						 0, 0, sZ, 0,
						 0, 0, 0, 1);
	}

	// Rotate matrix relative to the OZ axis
	inline glm::mat4 RotateOZ(float radians)
	{
		// TODO implement rotate matrix
		return glm::mat4(cos(radians), sin(radians), 0, 0,
						 -sin(radians), cos(radians), 0, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 1);
	}

	// Rotate matrix relative to the OY axis
	inline glm::mat4 RotateOY(float radians)
	{
		// TODO implement rotate matrix
		return glm::mat4(cos(radians), 0, -sin(radians), 0,
						 0, 1, 0, 0,
						 sin(radians), 0, cos(radians), 0,
						 0, 0, 0, 1);
						
	}

	// Rotate matrix relative to the OX axis
	inline glm::mat4 RotateOX(float radians)
	{
		// TODO implement rotate matrix
		return glm::mat4(1, 0, 0, 0, 
						 0, cos(radians), sin(radians), 0,
						 0, -sin(radians), cos(radians), 0,
						 0, 0, 0, 1);
	}
}
