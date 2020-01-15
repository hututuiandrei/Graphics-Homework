#version 330

// TODO: get color value from vertex shader
in vec3 world_position;
in vec3 world_normal;
in vec4 color;

// Uniforms for light properties
uniform vec3 light_direction;
uniform vec3 light_position;
uniform vec3 eye_position;
uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;
uniform vec3 object_color;
uniform int spot_enable;
uniform float material_radius;

layout(location = 0) out vec4 out_color;

void main()
{

	vec3 L = normalize( light_position - world_position );
	vec3 V = normalize( eye_position - world_position );
	vec3 H = normalize( L + V );

	// TODO: define ambient light component
	float ambient_light = 0.25f;

	// TODO: compute diffuse light component
	float diffuse_light = 0;
	diffuse_light = max(dot(world_normal,L), 0);


	// TODO: compute specular light component
	float _specular_light = 0;
	_specular_light = dot(world_normal,H);
	float specular_light = (dot(world_normal,L) > 0 ? _specular_light : 0);

	float light;
	// TODO: compute light
	light = ambient_light + (diffuse_light + specular_light) * 200000 / pow(distance(light_position, world_position),2);
	
	if(light < ambient_light)
		light = ambient_light;

	out_color = light * color;

	// TODO: write pixel out color
}