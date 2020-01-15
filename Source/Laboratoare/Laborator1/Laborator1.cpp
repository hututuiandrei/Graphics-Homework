#include "Laborator1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

// Order of function calling can be seen in "Source/Core/World.cpp::LoopUpdate()"
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/World.cpp

Laborator1::Laborator1()
{
}

Laborator1::~Laborator1()
{
}

void Laborator1::Init()
{
	// Load a mesh from file into GPU memory
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("archer");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Characters/Archer", "Archer.fbx");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("teapot");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "teapot.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("quad");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "quad.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}
}

void Laborator1::FrameStart()
{

}

int a = 0, b = 0, c = 1;
string mesh = "box";

string mesh1 = "teapot";
string mesh2 = "sphere";
string mesh3 = "box";
float x = 0, y = 0, z = 0;
void Laborator1::Update(float deltaTimeSeconds)
{
	glm::ivec2 resolution = window->props.resolution;

	// sets the clear color for the color buffer

	glClearColor(a, b, c, 1/255);

	// clears the color buffer (using the previously set color) and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);

	// render the object
	RenderMesh(meshes["box"], glm::vec3(1, 0.5f, 0), glm::vec3(0.5f));

	RenderMesh(meshes[mesh], glm::vec3(y, z, x), glm::vec3(0.5f));

	// render the object again but with different properties

	float speed = 5;

	if (window->KeyHold(GLFW_KEY_W)) {

		x += -speed * deltaTimeSeconds;
	}

	if (window->KeyHold(GLFW_KEY_S)) {

		x += speed * deltaTimeSeconds;
	}

	if (window->KeyHold(GLFW_KEY_A)) {

		y += -speed * deltaTimeSeconds;
	}

	if (window->KeyHold(GLFW_KEY_D)) {

		y += speed * deltaTimeSeconds;
	}

	if (window->KeyHold(GLFW_KEY_Q)) {

		z += speed * deltaTimeSeconds;
	}

	if (window->KeyHold(GLFW_KEY_E)) {

		z += -speed * deltaTimeSeconds;
	}

}

void Laborator1::FrameEnd()
{
	DrawCoordinatSystem();
}

// Read the documentation of the following functions in: "Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Laborator1::OnInputUpdate(float deltaTime, int mods)
{
	// treat continuous update based on input
};

void Laborator1::OnKeyPress(int key, int mods)
{
	// add key press event
	if (key == GLFW_KEY_F) {
		// do something
		if (mesh.compare("box") == 0) {

			mesh = mesh1;
		}
		else if (mesh.compare("teapot") == 0) {

			mesh = mesh2;
		}
		else if (mesh.compare("sphere") == 0) {

			mesh = mesh3;
		}
	}

	if (key == GLFW_KEY_B) {

		a = 1;
		b = 0;
		c = 1;
	}
};

void Laborator1::OnKeyRelease(int key, int mods)
{
	// add key release event
};

void Laborator1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
};

void Laborator1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
};

void Laborator1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
	// treat mouse scroll event
}

void Laborator1::OnWindowResize(int width, int height)
{
	// treat window resize event
}
