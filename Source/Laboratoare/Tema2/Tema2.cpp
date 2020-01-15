#include "Tema2.h"

#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>

#include <Core/Engine.h>
#include "Model.h"
#include "Transform3D.h"

#define PI 3.14159265

#define OBJ_OCEAN 0
#define OBJ_PLANE 1
#define OBJ_CLOUD 2
#define OBJ_OBST 3
#define OBJ_OBST_INO 4
#define OBJ_TETRA 5

using namespace std;

Tema2::Tema2() {}

Tema2::~Tema2() {}

void Tema2::Init() {

	camera = new Cam::Camera();

	projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

	vector<VertexFormat> vertices;
	vector<unsigned short> indices;
	Model* render = new Model();

	{
		render->loadPlaneBody();
		vertices = render->getVertices();
		indices = render->getIndices();

		meshes["plane_body"] = new Mesh("generated plane_body");
		meshes["plane_body"]->InitFromData(vertices, indices);
		render->clearMesh();
	}

	{
		render->loadPlanePropeller();
		vertices = render->getVertices();
		indices = render->getIndices();

		meshes["plane_propeller"] = new Mesh("generated plane_propeller");
		meshes["plane_propeller"]->InitFromData(vertices, indices);
		render->clearMesh();
	}

	{
		render->loadOcean(oceanRadius);
		vertices = render->getVertices();
		indices = render->getIndices();

		meshes["ocean"] = new Mesh("generated ocean");
		meshes["ocean"]->InitFromData(vertices, indices);
		render->clearMesh();
	}

	{
		render->loadBasicCube();
		vertices = render->getVertices();
		indices = render->getIndices();

		meshes["cloud_cube"] = new Mesh("generated cloud_cube");
		meshes["cloud_cube"]->InitFromData(vertices, indices);
		render->clearMesh();
	}

	{
		render->loadTetra();
		vertices = render->getVertices();
		indices = render->getIndices();

		meshes["tetra"] = new Mesh("generated tetra");
		meshes["tetra"]->InitFromData(vertices, indices);
		render->clearMesh();
	}

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}


	// Create a shader program for drawing face polygon with the color of the normal
	{
		Shader* shader = new Shader("Shaders");
		shader->AddShader("Source/Laboratoare/Tema2/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Tema2/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	//Light & material properties
	{
		materialShininess = 30;
		materialKd = 1;
		materialKs = 1;
	}

	{
		for (int i = 0; i < numOfClouds; i++) {

			cloudPositions[i] = (float)rand() / RAND_MAX;
			cloudDistances[i] = (float)rand() / RAND_MAX;
			cloudDepths[i] = (float)rand() / RAND_MAX;
		}	

		for (int i = 0; i < 4 * numOfClouds; i++) {

			cloudScalings[i] = (float)rand() / RAND_MAX;
		}

		for (int i = 0; i < numOfObstacles; i++) {

			obstPositions[i] = (float)rand() / RAND_MAX;
			obstDistances[i] = (float)rand() / RAND_MAX;
		}
		for (int i = 0; i < numOfObstacles / 2; i++) {

			obstDepths[i] = (float)rand() / RAND_MAX;
		}
		for (int i = 0; i < numOfTetras; i++) {

			tetraPositions[i] = (float)rand() / RAND_MAX;
			tetraDistances[i] = (float)rand() / RAND_MAX;
		}
	}

	cullFace = GL_BACK;
	polygonMode = GL_FILL;
}

void Tema2::FrameStart() {

	//Set background colour
	glClearColor(0.52f, 0.81f, 0.98f, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Get screen dimensions
	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::Update(float deltaTimeSeconds) {

	glEnable(GL_CULL_FACE);

	if(!planeDead)
	planeDistance += planeAcc * (planeSeeked - planeDistance) * deltaTimeSeconds;

	propellerAngle += 20 * planeSpeed * deltaTimeSeconds;

	planeAngle += planeSpeed * deltaTimeSeconds;

	if (planeAngle >= 2 * PI) {

		planeAngle -= 2 * PI;
	}
	
	cameraAngle += planeSpeed * deltaTimeSeconds;

	if (cameraAngle >= 2 * PI) {

		cameraAngle -= 2 * PI;
	}

	renderAngle1 += planeSpeed * deltaTimeSeconds;

	if (renderAngle1 >= 2 * PI) {

		renderAngle1 -= 2 * PI;
	}

	renderAngle2 += planeSpeed * deltaTimeSeconds;

	if (renderAngle2 >= 2 * PI) {

		renderAngle2 -= 2 * PI;
	}
	//cout << cameraAngle << endl;

	lightAngle += planeSpeed * deltaTimeSeconds;

	if (lightAngle >= 2 * PI) {

		lightAngle -= 2 * PI;
	}

	cameraDistance = map(planeDistance, lowestAltitude, highestAltitude, lowestAltitude + 5, highestAltitude - 5);

	if (planeDead) {

		cameraDistance = cameraDistanceDead;
	}

	cameraX = oceanX + sin(cameraAngle) * cameraDistance;
	cameraY = oceanY + cos(cameraAngle) * cameraDistance;
	cameraZ = planeZ;

	planeX = oceanX + sin(planeAngle) * planeDistance;
	planeY = oceanY + cos(planeAngle) * planeDistance;

	lightX = oceanX + sin(lightAngle) * lightDistance;
	lightY = oceanY + cos(lightAngle) * lightDistance;

	lightPosition = glm::vec3(lightX, lightY, lightZ);
	
	if (firstPerson) {

		float thirdCameraX = oceanX + sin(planeAngle + 0.05f) * cameraDistance;
		float thirdCameraY = oceanY + cos(planeAngle + 0.05f) * cameraDistance;

		camera->Set(glm::vec3(thirdCameraX, thirdCameraY, planeZ), glm::vec3(cameraX, cameraY, cameraZ),
			glm::vec3(sin(cameraAngle), cos(cameraAngle), 0));
	}
	else {

		camera->Set(glm::vec3(cameraX, cameraY, cameraZ + 20), glm::vec3(cameraX, cameraY, cameraZ),
		glm::vec3(sin(cameraAngle), cos(cameraAngle), 0));
	}

	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(planeX, planeY, planeZ);

		modelMatrix *= Transform3D::RotateOZ(-planeAngle);

		modelMatrix *= Transform3D::RotateOZ(map(planeSeeked - planeDistance, minAcc, maxAcc, -PI / 3, PI / 3));
		RenderSimpleMesh(meshes["plane_body"], shaders["Shaders"], modelMatrix, OBJ_PLANE);
		modelMatrix *= Transform3D::Translate(0, 0.5f, -0.5f);
		modelMatrix *= Transform3D::RotateOX(propellerAngle);
		modelMatrix *= Transform3D::Translate(0, -0.5f, 0.5f);


		RenderSimpleMesh(meshes["plane_propeller"], shaders["Shaders"], modelMatrix, OBJ_PLANE);
	}
	
	{

		glm::mat4 modelMatrix = glm::mat4(1);

		modelMatrix *= Transform3D::RotateOX(PI / 2);

		RenderSimpleMesh(meshes["ocean"], shaders["Shaders"], modelMatrix, OBJ_OCEAN);
	}
	
	{

		for (int i = 0; i < numOfClouds; i++) {

			float cloudAngle = map(cloudPositions[i], 0, 1, 0, 2 * PI);
			float cloudDistance = map(cloudDistances[i], 0, 1, lowestAltitude + 10, highestAltitude - 5);
			float cloudDepth = map(cloudDepths[i], 0, 1, 15, -80);

			for (int j = 0; j < 4; j++) {

				float cloudX = oceanX + sin(cloudAngle + (float)j / 200) * cloudDistance;
				float cloudY = oceanY + cos(cloudAngle + (float)j / 200) * cloudDistance;

				if ((cloudAngle > renderAngle1 && cloudAngle < renderAngle2) || 
					(renderAngle1 > renderAngle2 && (cloudAngle > renderAngle1 || cloudAngle < renderAngle2))) {

					float cloudRotationOX = map(cloudPositions[i] + cloudPositions[j], 0, 2, -PI / 2, PI / 2);
					float cloudRotationOY = map(cloudDistances[i] + cloudPositions[j], 0, 2, -PI / 2, PI / 2);
					float cloudRotationOZ = map(cloudDepths[i] + cloudPositions[j], 0, 2, -PI / 2, PI / 2);

					glm::mat4 modelMatrix = glm::mat4(1);

					modelMatrix *= Transform3D::Translate(cloudX, cloudY, planeZ + cloudDepth);

					if (j == 1) {
						modelMatrix *= Transform3D::RotateOX(planeAngle);
						modelMatrix *= Transform3D::RotateOY(planeAngle);
						modelMatrix *= Transform3D::RotateOZ(planeAngle);
					}
					else {
						modelMatrix *= Transform3D::RotateOX(cloudRotationOX);
						modelMatrix *= Transform3D::RotateOY(cloudRotationOY);
						modelMatrix *= Transform3D::RotateOZ(cloudRotationOZ);
					}

					modelMatrix *= Transform3D::Scale(cloudScalings[4 * i + j], cloudScalings[4 * i + j], cloudScalings[4 * i + j]);

					RenderSimpleMesh(meshes["cloud_cube"], shaders["Shaders"], modelMatrix, OBJ_CLOUD);
				}
			}
		}

		planeFuel -= deltaTimeSeconds * fuelConsumption;
	
		if (planeFuel <= 0) {

			planeFuel = 0;
			planeDead = true;
			cameraDistanceDead = cameraDistance;
			cout << "GAME OVER" << endl;
		}

		if (planeImmune) {

			frameCounter += deltaTimeSeconds;

			planeSeeked = lowestAltitude + 10;

			if (frameCounter >= 1) {

				planeHit = false;
				planeImmune = false;
				frameCounter = 0;
			}
		}
		if (planeDead) {

			if (planeDistance >= 0) {

				planeDistance -= 10 * deltaTimeSeconds;
			}
		}

		{
			for (int i = 0; i < numOfObstacles; i++) {

				float obstAngle = map(obstPositions[i], 0, 1, 0, 2 * PI);
				float obstDistance = map(obstDistances[i], 0, 1, lowestAltitude + 5, highestAltitude);

				int index = i - numOfObstacles / 2;
				float obstDepth = map(obstDepths[index], 0, 1, -30, -80);

				float obstX = oceanX + sin(obstAngle) * obstDistance;
				float obstY = oceanY + cos(obstAngle) * obstDistance;
				float obstZ = planeZ;

				if ((obstAngle > renderAngle1 && obstAngle < renderAngle2) ||
					(renderAngle1 > renderAngle2 && (obstAngle > renderAngle1 || obstAngle < renderAngle2))) {

					glm::mat4 modelMatrix = glm::mat4(1);

					if (i < numOfObstacles / 2) {

						modelMatrix *= Transform3D::Translate(obstX, obstY, planeZ);
						modelMatrix *= Transform3D::Scale(2, 2, 2);

						RenderSimpleMesh(meshes["sphere"], shaders["Shaders"], modelMatrix, OBJ_OBST);

						
						if (!planeImmune) {

							if (intersect(glm::vec3(planeX, planeY, planeZ),
								glm::vec3(obstX, obstY, obstZ), 1, 1)) {

								if (playerLifes != 0) {

									planeHit = true;
									planeImmune = true;
									playerLifes--;
									cout << "LIVES : " << playerLifes << endl;

								}
								else {

									planeDead = true;
									cameraDistanceDead = cameraDistance;
									cout << "GAME OVER" << endl;
								}
							}
						}
					}
					else {

						modelMatrix *= Transform3D::Translate(obstX, obstY, obstDepth);
						modelMatrix *= Transform3D::Scale(2, 2, 2);

						RenderSimpleMesh(meshes["sphere"], shaders["Shaders"], modelMatrix, OBJ_OBST_INO);
					}
				}
			}
		}

		{

			for (int i = 0; i < numOfTetras; i++) {

				float tetraAngle = map(tetraPositions[i], 0, 1, 0, 2 * PI);
				float tetraDistance = map(tetraDistances[i], 0, 1, lowestAltitude + 5, highestAltitude);

				float tetraX = oceanX + sin(tetraAngle) * tetraDistance;
				float tetraY = oceanY + cos(tetraAngle) * tetraDistance;
				float tetraZ = planeZ;

				glm::mat4 modelMatrix = glm::mat4(1);

				modelMatrix *= Transform3D::Translate(tetraX, tetraY, tetraZ);

				RenderSimpleMesh(meshes["tetra"], shaders["Shaders"], modelMatrix, OBJ_TETRA);

				if (intersect(glm::vec3(planeX, planeY, planeZ),
					glm::vec3(tetraX, tetraY, tetraZ), 1, 0.5f)) {

					tetraPositions[i] = map(tetraAngle + PI / 2, 0, 2 * PI, 0, 1);

					cout << "PLANE FUEL : " << planeFuel << endl;
					planeFuel += 15;
					if (planeFuel > 100) planeFuel = 100;
				}
			}
		}
	}

	glDisable(GL_CULL_FACE);
}


void Tema2::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, int objCode)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// Set shader uniforms for light & material properties
	// TODO: Set light position uniform✓
	int light_position = glGetUniformLocation(shader->program, "light_position");
	glUniform3f(light_position, lightPosition.x, lightPosition.y, lightPosition.z);

	int light_direction = glGetUniformLocation(shader->program, "light_direction");
	glUniform3f(light_direction, lightDirection.x, lightDirection.y, lightDirection.z);

	// TODO: Set eye position (camera position) uniform✓
	glm::vec3 eyePosition = camera->position;
	int eye_position = glGetUniformLocation(shader->program, "eye_position");
	glUniform3f(eye_position, eyePosition.x, eyePosition.y, eyePosition.z);

	int obj_code = glGetUniformLocation(shader->program, "obj_code");
	glUniform1i(obj_code, objCode);

	// TODO: Set material property uniforms (shininess, kd, ks, object color)✓
	int material_shininess = glGetUniformLocation(shader->program, "material_shininess");
	glUniform1i(material_shininess, materialShininess);

	int material_kd = glGetUniformLocation(shader->program, "material_kd");
	glUniform1f(material_kd, materialKd);

	int material_ks = glGetUniformLocation(shader->program, "material_ks");
	glUniform1f(material_ks, materialKs);

	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Bind view matrix
	glm::mat4 viewMatrix = camera->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

void Tema2::FrameEnd() {

	//DrawCoordinatSystem();
}

void Tema2::OnInputUpdate(float deltaTime, int mods) {}

void Tema2::OnKeyPress(int key, int mods) {

	if (key == GLFW_KEY_T) {

		if (firstPerson) {

			firstPerson = false;
		}
		else {

			firstPerson = true;
		}
	}
}

void Tema2::OnKeyRelease(int key, int mods) {}

void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) {

	if (!planeHit && !planeDead) {
		planeSeeked =
			highestAltitude -
			map(mouseY, 0, window->GetResolution().y, lowestAltitude, highestAltitude) +
			lowestAltitude;
	}
	// TODO : translate the camera forward
}

//void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) {}

//void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) {}

//void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) {}

void Tema2::OnWindowResize(int width, int height) {}
