#include "Laborator7.h"

#include <vector>
#include <string>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

Laborator7::Laborator7()
{
}

Laborator7::~Laborator7()
{
}

void Laborator7::Init()
{

	camera = new Cam::CameraLab7();
	camera->Set(glm::vec3(0, 3, 3.5f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));

	//GetCameraInput()->SetActive(false);

	projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Characters/Ceva", "untitled.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("plane");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "plane50.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	// Create a shader program for drawing face polygon with the color of the normal
	{
		Shader *shader = new Shader("ShaderLab7");
		shader->AddShader("Source/Laboratoare/Laborator7/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Laborator7/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(1, 1, 0), glm::vec3(1, 0, 0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(0, 1, 0), glm::vec3(1, 0, 0), glm::vec3(0, 0, 1)),

			VertexFormat(glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(1, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(1, 1, -1), glm::vec3(1, 0, 0), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(0, 1, -1), glm::vec3(1, 0, 0), glm::vec3(0, 1, 0)),

			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), glm::vec3(0, -1, 0)),
			VertexFormat(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0), glm::vec3(0, -1, 0)),
			VertexFormat(glm::vec3(1, 0, -1), glm::vec3(1, 0, 0), glm::vec3(0, -1, 0)),
			VertexFormat(glm::vec3(0, 0, -1), glm::vec3(1, 0, 0), glm::vec3(0, -1, 0)),
			// TODO: Complete the information for the cube
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,
			0, 3, 2,

			4, 5, 6,
			4, 7, 6,

			9, 8, 10,
			//11, 8, 10
			/*
			1, 7, 3,
			1, 5, 7,

			6, 7, 4,
			7, 5, 4,

			0, 4, 1,
			1, 4, 5,

			2, 6, 4,
			0, 2, 4
			*/
		};

		meshes["cube1"] = new Mesh("generated cube 1");
		meshes["cube1"]->InitFromData(vertices, indices);
	}

	//Light & material properties
	{
		lightPosition = glm::vec3(0, 2, 0);
		materialShininess = 50;
		materialKd = 1;
		materialKs = 1;
	}
}

void Laborator7::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);	
}

void Laborator7::Update(float deltaTimeSeconds)
{
	/*
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 1, 0));
		RenderSimpleMesh(meshes["sphere"], shaders["ShaderLab7"], modelMatrix, glm::vec3(1, 0, 0));
	}
	*/
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		//modelMatrix = glm::translate(modelMatrix, glm::vec3(2, 2, 2));
		modelMatrix = glm::rotate(modelMatrix, RADIANS(30.0f), glm::vec3(1, 0, 0));
		//modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
		RenderSimpleMesh(meshes["cube1"], shaders["ShaderLab7"], modelMatrix, glm::vec3(1,0,0));
	}
	/*
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(-2, 0.5f, 0));
		modelMatrix = glm::rotate(modelMatrix, RADIANS(60.0f), glm::vec3(1, 1, 0));
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab7"], modelMatrix, glm::vec3(0, 0.5, 0));
	}
	*/

	// Render the point light in the scene
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, lightPosition);
	
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f));
		RenderMesh(meshes["sphere"], shaders["Simple"], modelMatrix);
	}
}

void Laborator7::FrameEnd()
{
	//DrawCoordinatSystem();
}

void Laborator7::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, const glm::vec3 &color)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// Set shader uniforms for light & material properties
	// TODO: Set light position uniform

	int location = glGetUniformLocation(shader->program, "light_position");
	glUniform3fv(location, 1, glm::value_ptr(lightPosition));

	// TODO: Set eye position (camera position) uniform
	//glm::vec3 eyePosition = GetSceneCamera()->transform->GetWorldPosition();
	glm::vec3 eyePosition = camera->position;

	location = glGetUniformLocation(shader->program, "eye_position");
	glUniform3fv(location, 1, glm::value_ptr(eyePosition));

	// TODO: Set material property uniforms (shininess, kd, ks, object color) 

	location = glGetUniformLocation(shader->program, "material_shininess");
	glUniform1i(location, materialShininess);

	location = glGetUniformLocation(shader->program, "material_kd");
	glUniform1f(location, materialKd);

	location = glGetUniformLocation(shader->program, "material_ks");
	glUniform1f(location, materialKs);

	location = glGetUniformLocation(shader->program, "object_color");
	glUniform3fv(location, 1, glm::value_ptr(color));

	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
	
	// Bind view matrix
	//glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	glm::mat4 viewMatrix = camera->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	//glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

// Documentation for the input functions can be found in: "/Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Laborator7::OnInputUpdate(float deltaTime, int mods)
{
	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		float cameraSpeed = 2.0f;

		if (window->KeyHold(GLFW_KEY_W)) {

			camera->MoveForward(cameraSpeed * deltaTime);
			// TODO : translate the camera forward
		}

		if (window->KeyHold(GLFW_KEY_A)) {
			// TODO : translate the camera to the left
			camera->TranslateRight(-cameraSpeed * deltaTime);
		}

		if (window->KeyHold(GLFW_KEY_S)) {

			camera->MoveForward(-cameraSpeed * deltaTime);
			// TODO : translate the camera backwards
		}

		if (window->KeyHold(GLFW_KEY_D)) {

			camera->TranslateRight(cameraSpeed * deltaTime);
			// TODO : translate the camera to the right
		}

		if (window->KeyHold(GLFW_KEY_Q)) {
			// TODO : translate the camera down
			camera->TranslateUpword(-cameraSpeed * deltaTime);
		}

		if (window->KeyHold(GLFW_KEY_E)) {

			camera->TranslateUpword(cameraSpeed * deltaTime);
			// TODO : translate the camera up
		}
	}
	else {

		if (window->KeyHold(GLFW_KEY_W)) {

			lightY += deltaTime;
			// TODO : translate the camera forward
		}

		if (window->KeyHold(GLFW_KEY_A)) {
			// TODO : translate the camera to the left
			lightX -= deltaTime;
		}

		if (window->KeyHold(GLFW_KEY_S)) {

			lightY -= deltaTime;
			// TODO : translate the camera backwards
		}

		if (window->KeyHold(GLFW_KEY_D)) {

			lightX += deltaTime;
			// TODO : translate the camera to the right
		}

		if (window->KeyHold(GLFW_KEY_E)) {

			lightZ += deltaTime;
			// TODO : translate the camera to the right
		}

		if (window->KeyHold(GLFW_KEY_Q)) {

			lightZ -= deltaTime;
			// TODO : translate the camera to the right
		}

		lightPosition = glm::vec3(lightX, lightY, lightZ);
	}
}

void Laborator7::OnKeyPress(int key, int mods)
{
	// add key press event
}

void Laborator7::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Laborator7::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Laborator7::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Laborator7::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator7::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Laborator7::OnWindowResize(int width, int height)
{
}
