#include "Tema1.h"

#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>

#include <Core/Engine.h>
#include "FlappyRenderer.h"
#include "Transform2D.h"

#define PI 3.14159265

using namespace std;

Tema1::Tema1() {}

Tema1::~Tema1() {}

void Tema1::Init() {

	//Set camera
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 160));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	//Set screen dimensions
	screenWidth = (float) resolution.x;
	screenHeight = (float) resolution.y;

	//Set bird starting position
	posX = screenWidth / 4;
	posY = screenHeight / 2;

	cullFace = GL_BACK;
	polygonMode = GL_FILL;

	vector<VertexFormat> vertices;
	vector<unsigned short> indices;

	//Used colours
	glm::vec3 RGB_black = glm::vec3(0, 0, 0);
	glm::vec3 RGB_gold = glm::vec3(1, 0.84f, 0);
	glm::vec3 RGB_tomato = glm::vec3(1, 0.39f, 0.28f);
	glm::vec3 RGB_yellow = glm::vec3(1, 1, 0);
	glm::vec3 RGB_lightyellow = glm::vec3(1, 1, 0.5f);
	glm::vec3 RGB_white = glm::vec3(1, 1, 1);
	glm::vec3 RGB_pink = glm::vec3(1, 0.75f, 0.8f);
	glm::vec3 RGB_hotpink = glm::vec3(1, 0.41f, 0.7f);
	glm::vec3 RGB_blue = glm::vec3(0, 0, 1);
	glm::vec3 RGB_dodgerblue = glm::vec3(0.137f, 0.56f, 1);

	//Flappy skins
	vector<glm::vec3> paletteClassic = { RGB_black, RGB_gold, RGB_tomato, RGB_yellow, RGB_lightyellow, RGB_white };
	vector<glm::vec3> palettePinkBoy = { RGB_black, RGB_pink, RGB_tomato, RGB_hotpink, RGB_pink, RGB_white };
	vector<glm::vec3> paletteGhostBirb = { RGB_white, RGB_black, RGB_black, RGB_black, RGB_black, RGB_white };
	vector<glm::vec3> paletteSeaFlap = { RGB_black, RGB_dodgerblue, RGB_tomato, RGB_blue, RGB_dodgerblue, RGB_white };

	//Render objects
	FlappyRenderer *render = new FlappyRenderer(paletteSeaFlap);

	render->loadFlyingFlappy();
	vertices = render->getVertices();
	indices = render->getIndices();

	meshes["flying_flappy"] = new Mesh("generated flying_flappy");
	meshes["flying_flappy"]->InitFromData(vertices, indices);
	render->clearMesh();

	render->loadFloatingFlappy();
	vertices = render->getVertices();
	indices = render->getIndices();

	meshes["floating_flappy"] = new Mesh("generated floating_flappy");
	meshes["floating_flappy"]->InitFromData(vertices, indices);
	render->clearMesh();

	render->loadFallingFlappy();
	vertices = render->getVertices();
	indices = render->getIndices();

	meshes["falling_flappy"] = new Mesh("generated falling_flappy");
	meshes["falling_flappy"]->InitFromData(vertices, indices);
	render->clearMesh();

	render->loadPipe();
	vertices = render->getVertices();
	indices = render->getIndices();

	meshes["pipe"] = new Mesh("pipe");
	meshes["pipe"]->InitFromData(vertices, indices);
	render->clearMesh();

	render->loadGround();
	vertices = render->getVertices();
	indices = render->getIndices();

	meshes["ground"] = new Mesh("ground");
	meshes["ground"]->InitFromData(vertices, indices);
	render->clearMesh();

	delete render;

	//Set pipes initial position
	for (int i = 0; i < numPipes; i++) {

		rngOffset[i] = rand() % (int)ceil(scalingFactor * pipeHeight);
		pipeX[i] = ((float) i / numPipes) * (screenWidth + pipeWidth * scalingFactor) + screenWidth;
	}

	cout << "PRESS SPACE TO START" << endl;
	
}

Mesh* Tema1::CreateMesh(const char* name, const std::vector<VertexFormat> & vertices, const std::vector<unsigned short> & indices) {

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	unsigned int IBO;
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	// TODO: Send indices data into the IBO buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// ========================================================================
	// This section describes how the GPU Shader Vertex Shader program receives data
	// It will be learned later, when GLSL shaders will be introduced
	// For the moment just think that each property value from our vertex format needs to be send to a certain channel
	// in order to know how to receive it in the GLSL vertex shader

	// set vertex position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

	// set vertex normal attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

	// set texture coordinate attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

	// set vertex color attribute
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
	// ========================================================================

	glBindVertexArray(0);

	// Check for OpenGL errors
	CheckOpenGLError();

	// Mesh information is saved into a Mesh object
	meshes[name] = new Mesh(name);
	meshes[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	return meshes[name];
}

void Tema1::FrameStart() {
	
	//Set background colour
	glClearColor(ccolor, ccolor, ccolor, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Get screen dimensions
	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);

	//Set game details
	gameSpeed = gameAcc * score;
	topSpeed = initialTopSpeed * (1 + gameSpeed / 2);
}

void Tema1::Update(float deltaTimeSeconds) {

	glEnable(GL_CULL_FACE);

	//Transform ground matrix
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Scale(scalingFactor, scalingFactor);
	modelMatrix *= Transform2D::Translate(0, 0);
	RenderMesh2D(meshes["ground"], shaders["VertexColor"], modelMatrix);

	/*
	Running game stance
	isAlive - reffering to the bird
	isRunning - reffering to the state of the game
	*/
	if (isAlive && isRunning) {

		//Day-Night cicle
		if (score/dayLength % 2 == 1) {

			if (ccolor < 1) {
				ccolor += daynight_speed * deltaTimeSeconds;
			}
		}
		else {

			if (ccolor > 0) {
				ccolor -= daynight_speed * deltaTimeSeconds;
			}
		}

		//Bird behaviour (felt gravity, angle of rotation)
		posY += deltaTimeSeconds * speed ;
		speed -= deltaTimeSeconds * acc * (1 + gameSpeed);
		angle = (((float) PI / 2) * (speed / topSpeed)) / 2;

		if (angle <= -PI / 2) {

			angle = (float) -PI / 2;
		}

		if (angle >= PI / 6) {

			angle = (float) PI / 6;
		}

		//If bird hit the ground it dies
		if (posY <= groundLevel) {

			if (GODMOD == 0) {

				isAlive = false;
				cout << "YOU DIED !!!" << endl << "FINAL SCORE : " << score << endl;
				cout << "PRESS R TO TRY AGAIN" << endl;
			}
			else {

				posY = groundLevel;
			}
		}

		//Bird cant fly above the top of the screen
		if (posY >= screenHeight - flappyHeight) {

			posY = screenHeight - flappyHeight;
		}

		//Apply computed behaviours on transformation matrices
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(posX, posY);
		modelMatrix *= Transform2D::Scale(scalingFactor, scalingFactor);
		modelMatrix *= Transform2D::Translate(flappyWidth / 2, flappyHeight / 2);
		modelMatrix *= Transform2D::Rotate(angle);
		modelMatrix *= Transform2D::Translate(-flappyWidth / 2, -flappyHeight / 2);

		//Alternate bird meshes to create a 3 frame animation
		frameCounter += deltaTimeSeconds;

		if (frameCounter >= 0 && frameCounter < animationsInterval) {
			RenderMesh2D(meshes["floating_flappy"], shaders["VertexColor"], modelMatrix);
		}
		if (frameCounter >= animationsInterval && frameCounter < 2 * animationsInterval) {
			RenderMesh2D(meshes["flying_flappy"], shaders["VertexColor"], modelMatrix);
		}
		if (frameCounter >= 2 * animationsInterval && frameCounter < 3 * animationsInterval) {
			RenderMesh2D(meshes["floating_flappy"], shaders["VertexColor"], modelMatrix);
		}
		if (frameCounter >= 3 * animationsInterval && frameCounter < 4 * animationsInterval) {

			RenderMesh2D(meshes["falling_flappy"], shaders["VertexColor"], modelMatrix);
		}
		if (frameCounter >= 4 * animationsInterval) {

			RenderMesh2D(meshes["floating_flappy"], shaders["VertexColor"], modelMatrix);
			frameCounter = 0;
		}

		//Pipes behaviour
		for (int i = 0; i < numPipes; i++) {

			pipeX[i] -= deltaTimeSeconds * pipeSpeed * (1 + gameSpeed);
			
			//After passing the left screen limit the pipes are positioned over the right 
			//screen limit at a random height
			if (pipeX[i] <= - scalingFactor * pipeWidth) {

				pipeX[i] = screenWidth;
				rngOffset[i] = rand() % (int)ceil(scalingFactor * pipeHeight);
			}
			
			float pipeY = groundLevel - rngOffset[i];

			//Bottom pipes transformations
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(pipeX[i], pipeY);
			modelMatrix *= Transform2D::Scale(scalingFactor, scalingFactor);
			RenderMesh2D(meshes["pipe"], shaders["VertexColor"], modelMatrix);
			
			//Top pipes transformations (the same pipe rotated 180 degrees)
			modelMatrix *= Transform2D::Rotate((float) -PI);			
			modelMatrix *= Transform2D::Translate(- pipeWidth, - (2 * pipeHeight + safeSpace));
			RenderMesh2D(meshes["pipe"], shaders["VertexColor"], modelMatrix);
	
			//Collision detection algorithm (all hitboxes are rectangles)
			if (posX + scalingFactor * flappyWidth >= pipeX[i] + hitboxNarrower
				&& posX <= pipeX[i] + scalingFactor * pipeWidth - hitboxNarrower) {

				//Bird hits the bottom or the top pipe
				if (posY <= pipeY + scalingFactor * pipeHeight - hitboxNarrower ||
					posY + scalingFactor * flappyHeight >= pipeY + scalingFactor * pipeHeight + scalingFactor * safeSpace + hitboxNarrower) {

					if (GODMOD == 0) {
						isAlive = false;
						cout << "YOU DIED !!!" << endl << "FINAL SCORE : " << score << endl;
						cout << "PRESS R TO TRY AGAIN" << endl;
					}
				}
				//Bird flies above the bottom pipe and below the top one
				else {

					//If the bird passed the gap increment the score  
					if (isPassing[i]) {

						score++;
						cout << "SCORE : " << score << endl;
					}
					isPassing[i] = false;
				}
			}
			else {

				isPassing[i] = true;
			}					
		}
	}

	/*Dead bird game stance : 

	Scene is still rendered untill the player resets the game; 
	Player loses control of the bird (gravity still affects it);
	Pipes stop moving.
	*/
	else {

		if (isRunning) {
			
			posY += deltaTimeSeconds * speed;
			speed -= deltaTimeSeconds * acc * (1 + gameSpeed);
			angle = ((float) PI / 2) * (speed / topSpeed);
			if (posY <= groundLevel) {

				posY = groundLevel;
			}
			if (angle <= -PI / 2) {

				angle = (float) -PI / 2;
			}
		}
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(posX, posY);
		modelMatrix *= Transform2D::Scale(scalingFactor, scalingFactor);
		modelMatrix *= Transform2D::Translate(flappyWidth / 2, flappyHeight / 2);
		modelMatrix *= Transform2D::Rotate(angle);
		modelMatrix *= Transform2D::Translate(-flappyWidth / 2, -flappyHeight / 2);
		RenderMesh2D(meshes["floating_flappy"], shaders["VertexColor"], modelMatrix);

		for (int i = 0; i < numPipes; i++) {
	
			float pipeY = groundLevel - rngOffset[i];

			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(pipeX[i], pipeY);
			modelMatrix *= Transform2D::Scale(scalingFactor, scalingFactor);
			RenderMesh2D(meshes["pipe"], shaders["VertexColor"], modelMatrix);
			modelMatrix *= Transform2D::Rotate((float) -PI);
			modelMatrix *= Transform2D::Translate(-pipeWidth, -(2 * pipeHeight + safeSpace));
			RenderMesh2D(meshes["pipe"], shaders["VertexColor"], modelMatrix);
		}
	}
	glDisable(GL_CULL_FACE);
}

void Tema1::FrameEnd() {}

void Tema1::OnInputUpdate(float deltaTime, int mods) {}

void Tema1::OnKeyPress(int key, int mods) {

	//Pressing space starts the game and make the bird jump

	if (key == GLFW_KEY_SPACE) {

		if (isAlive) {

			speed = topSpeed;
			isRunning = true;
		}
	}
	
	//Pressing R resets the game and player progress only if the player dies

	if (key == GLFW_KEY_R && !isAlive) {

		cout << "PRESS SPACE TO START" << endl;

		ccolor = 0.01f;
		isRunning = false;
		isAlive = true;
		posX = screenWidth / 4;
		posY = screenHeight / 2;
		speed = 0;
		angle = 0;
		score = 0;

		for (int i = 0; i < numPipes; i++) {
			rngOffset[i] = rand() % (int)ceil(4 * pipeHeight);

			pipeX[i] = ((float) i / numPipes) * (screenWidth + pipeWidth * scalingFactor) + screenWidth;
		}
	}
}

void Tema1::OnKeyRelease(int key, int mods) {}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) {}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) {}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) {}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) {}

void Tema1::OnWindowResize(int width, int height) {}
