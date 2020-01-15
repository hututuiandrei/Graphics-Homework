#pragma once

#include <Component/SimpleScene.h>
#include <Core/Engine.h>

#define NUMP 4
#define GODMOD 0

class Tema1 : public SimpleScene {
	
public:
	Tema1();
	~Tema1();

	void Init() override;

private:
	Mesh* CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;

protected:

	float groundLevel = 80;
	float safeSpace = 50;
	float frameCounter = 0;
	float scalingFactor = 4;
	float hitboxNarrower = 12;
	int dayLength = 20;

	float gameSpeed = 1;
	float gameAcc = 0.001f;
	bool isRunning = false;
	int score = 0;

	int numPipes = NUMP;
	float pipeWidth = 21;
	float pipeHeight = 110;
	float pipeX[NUMP];
	float pipeY = groundLevel;
	float pipeSpeed = 400;

	float screenWidth;
	float screenHeight;
	int rngOffset[NUMP];
	float animationsInterval = 0.1f;
	float flappyWidth = 16;
	float flappyHeight = 12;
	float posX;
	float posY;
	float speed = 0;
	float acc = 2000;
	float angle = 0;
	float topSpeed;
	float initialTopSpeed = 600;
	bool isAlive = true;
	bool isPassing[NUMP];
	float slidingPipeY = 0;

	float daynight_speed = 0.2f;
	float ccolor = 0.01f;

	GLenum cullFace;
	GLenum polygonMode;
	glm::mat3 modelMatrix;
};