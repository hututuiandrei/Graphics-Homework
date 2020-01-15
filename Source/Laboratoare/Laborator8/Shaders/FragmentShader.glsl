#version 330

// TODO: get color value from vertex shader
in vec3 world_position;
in vec3 world_normal;
in vec3 color;

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
	float ambient_light = 0.25;

	// TODO: compute diffuse light component
	float diffuse_light = 0;
	diffuse_light = max(dot(world_normal,L), 0);


	// TODO: compute specular light component
	float _specular_light = 0;
	_specular_light = dot(world_normal,H);
	float specular_light = (dot(world_normal,L) > 0 ? _specular_light : 0);

	float cut_off = radians(material_radius);
	float spot_light = dot(-L, light_direction);
	float spot_light_limit = cos(cut_off);
 
	// Quadratic attenuation
	float linear_att = (spot_light - spot_light_limit) / (1 - spot_light_limit);
	float light_att_factor = pow(linear_att, 2);

	float light;
	// TODO: compute light
	if(spot_enable == 1)
		light = ambient_light + (spot_light * light_att_factor) * 1 / pow(distance(light_position, world_position),2);
	else
		light = ambient_light + (diffuse_light + specular_light) * 1 / pow(distance(light_position, world_position),2);
	
	if(light < ambient_light)
		light = ambient_light;

	vec3 color = light * object_color;

	// TODO: write pixel out color
	out_color = vec4(color, 1);
}