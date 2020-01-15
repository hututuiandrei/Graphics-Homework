#pragma once
#include <include/glm.h>
#include <include/math.h>

namespace Cam
{
	class CameraLab7
	{
	public:
		CameraLab7()
		{
			position = glm::vec3(0, 2, 5);
			forward = glm::vec3(0, 0, -1);
			up = glm::vec3(0, 1, 0);
			right = glm::vec3(1, 0, 0);
			distanceToTarget = 2;
		}

		CameraLab7(const glm::vec3 & position, const glm::vec3 & center, const glm::vec3 & up)
		{
			Set(position, center, up);
		}

		~CameraLab7()
		{ }


		// Update CameraLab7
		void Set(const glm::vec3 & position, const glm::vec3 & center, const glm::vec3 & up)
		{
			this->position = position;
			forward = glm::normalize(center - position);
			right = glm::cross(forward, up);
			this->up = glm::cross(right, forward);
		}

		void MoveForward(float distance)
		{
			glm::vec3 dir = glm::normalize(glm::vec3(forward.x, 0, forward.z));

			position += dir * distance;
			// movement will keep the CameraLab7 at the same height always
			// Example: If you rotate up/down your head and walk forward you will still keep the same relative distance (height) to the ground!
			// Translate the CameraLab7 using the DIR vector computed from forward
		}


		void TranslateForward(float distance)
		{
			position += glm::normalize(forward) * distance;
			// TODO : Translate the CameraLab7 using the "forward" vector
		}

		void TranslateUpword(float distance)
		{
			// TODO : Translate the CameraLab7 using the up vector
			position += glm::normalize(up) * distance;
		}

		void TranslateRight(float distance)
		{

			position += glm::normalize(right) * distance;
			// TODO
			// Translate the CameraLab7 using the "right" vector
			// Usually translation using CameraLab7 "right' is not very useful because if the CameraLab7 is rotated around the "forward" vector 
			// translation over the right direction will have an undesired effect; the CameraLab7 will get closer or farther from the ground
			// Using the projected right vector (onto the ground plane) makes more sense because we will keep the same distance from the ground plane
		}

		void RotateFirstPerson_OX(float angle)
		{

			forward = glm::rotate(glm::mat4(1), angle, glm::vec3(right)) * glm::vec4(forward, 0);
			forward = glm::normalize(forward);

			up = glm::cross(right, forward);
			// TODO
			// Compute the new "forward" and "up" vectors
			// Attention! Don't forget to normalize the vectors
			// Use glm::rotate()
		}

		void RotateFirstPerson_OY(float angle)
		{
			forward = glm::rotate(glm::mat4(1), angle, glm::vec3(0, 1, 0)) * glm::vec4(forward, 0);
			forward = glm::normalize(forward);

			right = glm::rotate(glm::mat4(1), angle, glm::vec3(0, 1, 0)) * glm::vec4(right, 0);
			right = glm::normalize(right);

			up = glm::cross(right, forward);
			// TODO
			// Compute the new "forward", "up" and "right" vectors
			// Don't forget to normalize the vectors
			// Use glm::rotate()
		}

		void RotateFirstPerson_OZ(float angle)
		{

			right = glm::rotate(glm::mat4(1), angle, forward) * glm::vec4(right, 0);
			right = glm::normalize(right);

			up = glm::cross(right, forward);
			//up = glm::normalize(up);
			// TODO
			// Compute the new Right and Up, Forward stays the same
			// Don't forget to normalize the vectors
		}

		void RotateThirdPerson_OX(float angle)
		{
			TranslateForward(distanceToTarget);
			RotateFirstPerson_OX(angle);
			TranslateForward(-distanceToTarget);
			// TODO
			// Rotate the CameraLab7 in Third Person mode - OX axis
			// Use distanceToTarget as translation distance
		}

		void RotateThirdPerson_OY(float angle)
		{
			TranslateRight(distanceToTarget);
			RotateFirstPerson_OY(angle);
			TranslateRight(-distanceToTarget);
			// TODO
			// Rotate the CameraLab7 in Third Person mode - OY axis
		}

		void RotateThirdPerson_OZ(float angle)
		{
			TranslateUpword(distanceToTarget);
			RotateFirstPerson_OZ(angle);
			TranslateUpword(-distanceToTarget);
			// TODO
			// Rotate the CameraLab7 in Third Person mode - OZ axis
		}

		glm::mat4 GetViewMatrix()
		{
			// Returns the View Matrix
			return glm::lookAt(position, position + forward, up);
		}

		glm::vec3 GetTargetPosition()
		{
			return position + forward * distanceToTarget;
		}


	public:
		float distanceToTarget;
		glm::vec3 position;
		glm::vec3 forward;
		glm::vec3 right;
		glm::vec3 up;
	};
}