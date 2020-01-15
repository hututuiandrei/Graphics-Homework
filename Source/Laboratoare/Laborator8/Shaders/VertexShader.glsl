#version 330

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texture_coord;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

// Uniforms for light properties
uniform vec3 light_position;
uniform vec3 light_direction;
uniform vec3 eye_position;
uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;
uniform vec3 object_color;
uniform int spot_enable;
uniform float material_radius;

// Output values to fragment shader
out vec3 world_position;
out vec3 world_normal;
out vec3 color;

void main()
{
	// TODO: compute world space vertex position and normal
	// TODO: send world position and world normal to Fragment Shader
	world_position = (Model * vec4(v_position,1)).xyz;	
	world_normal = normalize (mat3(Model) * v_normal);

	color = object_color;
	gl_Position = Projection * View * Model * vec4(v_position, 1.0);
}