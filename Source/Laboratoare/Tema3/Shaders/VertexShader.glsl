#version 330

layout(location = 0) in vec3 v_position;
layout(location = 2) in vec2 v_texture_coord;
layout(location = 3) in vec3 v_color;

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

out vec2 texcoord;

uniform sampler2D height_map;
uniform float in_map_size;
uniform int in_map_size_int;

out float map_size;

void main()
{
	// TODO: compute world space vertex position and normal
	// TODO: send world position and world normal to Fragment Shader
    float h = 0.0;
	int scale = 50;

	float posX = v_position.x;
	float posZ = v_position.z;

	vec2 ceva = vec2(posX / (in_map_size_int + 1), posZ / (in_map_size_int + 1));

    h = texture(height_map, ceva).r * scale;
	
	map_size = in_map_size;
	texcoord = v_texture_coord;
	world_position = vec3(v_position.x, h, v_position.z);

	gl_Position = Projection * View * Model * vec4(vec3(v_position.x, h, v_position.z), 1.0);
}