#version 330

// TODO: get color value from vertex shader
in vec3 world_position;
in vec2 texcoord;
in float map_size;

// Uniforms for light properties
uniform vec3 eye_position;
uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;
uniform vec3 object_color;
uniform int spot_enable;
uniform float material_radius;

uniform sampler2D dirt_texture;
uniform sampler2D height_map;

layout(location = 0) out vec4 out_color;

void main()
{

	vec3 light_position = vec3(100, 150, 100);

	vec3 normal;

	float height = texture(height_map, texcoord).r;
	vec2 texelSize = vec2(1.0/map_size, 1.0/map_size);
	float heightRight = texture(height_map, vec2(texcoord.x + texelSize.x, texcoord.y)).r;
	float heightUp= texture(height_map, vec2(texcoord.x, texcoord.y + texelSize.y)).r;

	normal = normalize(vec3(height - heightRight, 1, height - heightUp));

	vec3 L = normalize(light_position - world_position );

	float diffuse_light = 0;
	diffuse_light = max(dot(normal,L), 0);

	float light;
	
	light = diffuse_light * 1 / pow(distance(light_position, world_position),2) * 150000;

	vec4 color_texture = texture(dirt_texture, texcoord) / 10;	

	vec4 color = light * color_texture;

	// TODO: write pixel out color
	out_color = color;
}