#pragma once

#include <vector>

#include <Component/SimpleScene.h>
#include <Core/Engine.h>
#include "Camera.h"

#define numClouds 300
#define numObstacles 80
#define numTetras 15
#define PI 3.14159265

class Tema2 : public SimpleScene {

public:
	Tema2();
	~Tema2();

	void Init() override;

private:

	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, int objCode);

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	//void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	//void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	//void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;

	float map(float inp, float iLowest, float iHighest, float oLowest, float oHighest) {

		return (inp - iLowest) / (iHighest - iLowest) * (oHighest - oLowest) + oLowest;
	}

	bool intersect(glm::vec3 sphere, glm::vec3 other, float radSp, float radOt) {
		// we are using multiplications because it's faster than calling Math.pow
		float distance = sqrt((sphere.x - other.x) * (sphere.x - other.x) +
			(sphere.y - other.y) * (sphere.y - other.y) +
			(sphere.z - other.z) * (sphere.z - other.z));

		return distance < (radSp + radOt);
	}

protected:

	float oceanRadius = 70;
	float angle = PI;
	float oceanX = 0;
	float oceanY = 0;
	float oceanZ = 0;

	float planeDistance = oceanRadius + 20;
	float planeSeeked = oceanRadius + 5;
	float angleSeeked;
	float planeAcc = 5;
	float planeSpeed = 0.2f;
	float planeAngle = PI - PI/36;
	float lowestAltitude = oceanRadius;
	float highestAltitude = oceanRadius + 20;
	float minAcc = (lowestAltitude - highestAltitude) / 2;
	float maxAcc = -minAcc;
	float propellerAngle = 0;
	float planeX = 0;
	float planeY = 0;
	float planeZ = -25;
	bool planeDead = false;
	bool planeHit = false;
	bool planeImmune = true;
	float planeFuel = 100;
	float fuelConsumption = 5;
	float cameraDistanceDead;

	int playerLifes = 3;

	float frameCounter = 0;

	float lightDistance = 450 + oceanRadius;
	float lightX;
	float lightY;
	float lightZ = 150 + oceanRadius;
	float lightAngle = PI + PI/24;

	float cameraDistance = planeDistance + 5;
	float cameraAngle = PI;
	float cameraX;
	float cameraY;
	float cameraZ;
	bool firstPerson = false;

	float renderDistance = PI / 3;
	float renderAngle1 = cameraAngle - renderDistance;
	float renderAngle2 = cameraAngle + renderDistance;

	float numOfClouds = numClouds;
	float cloudPositions[numClouds];
	float cloudDistances[numClouds];
	float cloudDepths[numClouds];
	float cloudScalings[numClouds * 4];
	float cloudAngle = 0;

	float numOfObstacles = numObstacles;
	float obstPositions[numObstacles];
	float obstDistances[numObstacles];
	float obstDepths[numObstacles / 2];

	float numOfTetras = numTetras;
	float tetraPositions[numTetras];
	float tetraDistances[numTetras];

	glm::vec3 lightPosition;
	glm::vec3 lightDirection;
	unsigned int materialShininess;
	float materialKd;
	float materialKs;

	Cam::Camera * camera;
	glm::mat4 projectionMatrix;

	GLenum cullFace;
	GLenum polygonMode;
	glm::mat3 modelMatrix;

};
