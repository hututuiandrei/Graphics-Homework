#include "Tema3.h"
#include "Model1.h"

#include <vector>
#include <string>
#include <iostream>
#include <stb/stb_image.h>

#include <Core/Engine.h>

#define CHUNKSIZE 100

using namespace std;

Tema3::Tema3()
{
}

Tema3::~Tema3()
{
}

void Tema3::Init()
{
	int width, height, channels;
	{
		heightMapTextureID = 0;
		stbi_uc* heightPixels;
		string textureLoc = "Resources/Textures/";
		heightPixels = stbi_load((textureLoc + "heightmap.png").c_str(), &width, &height, &channels, STBI_grey);

		map_size = height;

		if (heightMapTextureID)
			glDeleteTextures(1, &heightMapTextureID);
		glGenTextures(1, &heightMapTextureID);
		glBindTexture(GL_TEXTURE_2D, heightMapTextureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4);
		glPixelStorei(GL_PACK_ALIGNMENT, 1);
		CheckOpenGLError();

		glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, (void*)heightPixels);

		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
		CheckOpenGLError();

		stbi_image_free(heightPixels);
	}

	loadChunk(0, 0);
	loadChunk(1, 0);
	loadChunk(0, 1);
	loadChunk(1, 1);

	{
		dirtTextureID = 1;
		stbi_uc* heightPixels;
		string textureLoc = "Resources/Textures/";
		heightPixels = stbi_load((textureLoc + "dirt.jpg").c_str(), &width, &height, &channels, 0);

		if (dirtTextureID)
			glDeleteTextures(1, &dirtTextureID);
		glGenTextures(1, &dirtTextureID);
		glBindTexture(GL_TEXTURE_2D, dirtTextureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4);
		glPixelStorei(GL_PACK_ALIGNMENT, 1);
		CheckOpenGLError();

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (void*)heightPixels);

		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
		CheckOpenGLError();

		stbi_image_free(heightPixels);
	}
	

	// Create a shader program for drawing face polygon with the color of the normal
	{
		Shader* shader = new Shader("ShaderTema3");
		shader->AddShader("Source/Laboratoare/Tema3/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Tema3/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	//Light & material properties
	{
		lightPosition = glm::vec3(0, 1, 1);
		lightDirection = glm::vec3(0, -1, 0);
		materialShininess = 30;
		materialKd = 0.5;
		materialKs = 0.5;
	}
}
void Tema3::loadChunk(int i, int j) {

		Model1* render = new Model1();
		render->loadTerrain(i * CHUNKSIZE, (i + 1) * CHUNKSIZE, j * CHUNKSIZE, (j + 1) * CHUNKSIZE);
		vector<glm::vec3> vertices = render->getVertices();
		vector<unsigned short> indices = render->getIndices();
		vector<glm::vec3> normals = render->getNormals();
		vector<glm::vec2> tex_coords = render->getTexCoords();

		string terrain = "terrain" + to_string(i) + to_string(j);

		cout << terrain;

		meshes[terrain] = new Mesh("generated " + terrain);
		meshes[terrain]->InitFromData(vertices, normals, tex_coords, indices);
		render->clearMesh();
}

void Tema3::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0.52f, 0.81f, 0.98f, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema3::Update(float deltaTimeSeconds)
{

	// Render ground
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.01f, 0));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
		RenderSimpleMesh(meshes["terrain00"], shaders["ShaderTema3"], modelMatrix);
	}

	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.01f, 0));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
		RenderSimpleMesh(meshes["terrain10"], shaders["ShaderTema3"], modelMatrix);
	}

	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.01f, 0));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
		RenderSimpleMesh(meshes["terrain01"], shaders["ShaderTema3"], modelMatrix);
	}

	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.01f, 0));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
		RenderSimpleMesh(meshes["terrain11"], shaders["ShaderTema3"], modelMatrix);
	}

	// Render the point light in the scene
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, lightPosition);
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f));
		RenderMesh(meshes["sphere"], shaders["Simple"], modelMatrix);
	}
}

void Tema3::FrameEnd()
{
	DrawCoordinatSystem();
}

void Tema3::RenderSimpleMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix, const glm::vec3 & color)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// Set shader uniforms for light & material properties
	// TODO: Set light position uniform?
	int light_position = glGetUniformLocation(shader->program, "light_position");
	glUniform3f(light_position, lightPosition.x, lightPosition.y, lightPosition.z);

	int light_direction = glGetUniformLocation(shader->program, "light_direction");
	glUniform3f(light_direction, lightDirection.x, lightDirection.y, lightDirection.z);

	// TODO: Set eye position (camera position) uniform?
	glm::vec3 eyePosition = GetSceneCamera()->transform->GetWorldPosition();
	int eye_position = glGetUniformLocation(shader->program, "eye_position");
	glUniform3f(eye_position, eyePosition.x, eyePosition.y, eyePosition.z);

	// TODO: Set material property uniforms (shininess, kd, ks, object color)?
	int material_shininess = glGetUniformLocation(shader->program, "material_shininess");
	glUniform1i(material_shininess, materialShininess);

	int material_kd = glGetUniformLocation(shader->program, "material_kd");
	glUniform1f(material_kd, materialKd);

	int material_ks = glGetUniformLocation(shader->program, "material_ks");
	glUniform1f(material_ks, materialKs);

	int material_radius = glGetUniformLocation(shader->program, "material_radius");
	glUniform1f(material_radius, radius);

	int object_color = glGetUniformLocation(shader->program, "object_color");
	glUniform3f(object_color, color.r, color.g, color.b);

	int spot_enable = glGetUniformLocation(shader->program, "spot_enable");
	glUniform1i(spot_enable, spotEnable);

	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Bind view matrix
	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));


	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, heightMapTextureID);

	glUniform1i(glGetUniformLocation(shader->program, "height_map"), 0);

	glActiveTexture(GL_TEXTURE1);

	glBindTexture(GL_TEXTURE_2D, dirtTextureID);

	glUniform1i(glGetUniformLocation(shader->program, "dirt_texture"), 1);

	glUniform1f(glGetUniformLocation(shader->program, "in_map_size"), map_size);
	glUniform1i(glGetUniformLocation(shader->program, "in_map_size_int"), map_size);
	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

// Documentation for the input functions can be found in: "/Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Tema3::OnInputUpdate(float deltaTime, int mods)
{
	float speed = 2;

	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		glm::vec3 up = glm::vec3(0, 1, 0);
		glm::vec3 right = GetSceneCamera()->transform->GetLocalOXVector();
		glm::vec3 forward = GetSceneCamera()->transform->GetLocalOZVector();
		forward = glm::normalize(glm::vec3(forward.x, 0, forward.z));

		if (window->KeyHold(GLFW_KEY_W)) lightPosition -= forward * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_A)) lightPosition -= right * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_S)) lightPosition += forward * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_D)) lightPosition += right * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_E)) lightPosition += up * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_Q)) lightPosition -= up * deltaTime * speed;

		if (window->KeyHold(GLFW_KEY_H)) lightDirection = glm::rotate(glm::mat4(1), deltaTime * speed, glm::vec3(1, 0, 0)) * glm::vec4(lightDirection, 1);
		if (window->KeyHold(GLFW_KEY_J)) lightDirection = glm::rotate(glm::mat4(1), -deltaTime * speed, glm::vec3(1, 0, 0)) * glm::vec4(lightDirection, 1);
		if (window->KeyHold(GLFW_KEY_K)) lightDirection = glm::rotate(glm::mat4(1), deltaTime * speed, glm::vec3(0, 1, 0)) * glm::vec4(lightDirection, 1);
		if (window->KeyHold(GLFW_KEY_L)) lightDirection = glm::rotate(glm::mat4(1), -deltaTime * speed, glm::vec3(0, 1, 0)) * glm::vec4(lightDirection, 1);

		if (window->KeyHold(GLFW_KEY_I)) radius -= radius * deltaTime * speed;
		if (window->KeyHold(GLFW_KEY_O)) radius += radius * deltaTime * speed;

	}
}

void Tema3::OnKeyPress(int key, int mods)
{
	// add key press event
	if (key == GLFW_KEY_F) {
		spotEnable = (spotEnable + 1) % 2;
	}
}

void Tema3::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Tema3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema3::OnWindowResize(int width, int height)
{
}