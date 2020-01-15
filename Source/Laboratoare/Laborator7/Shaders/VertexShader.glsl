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
uniform vec3 eye_position;
uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

uniform vec3 object_color;

// Output value to fragment shader
out vec3 color;

void main()
{
	// TODO: compute world space vectors
	vec3 world_pos = (Model * vec4(v_position,1)).xyz;	
	vec3 world_normal = normalize( mat3(Model) * v_normal );

	vec3 L = normalize( light_position - world_pos );
	vec3 V = normalize( eye_position - world_pos );
	vec3 H = normalize( L + V );

	// TODO: define ambient light component
	float ambient_light = 0.25f;

	// TODO: compute diffuse light component
	float diffuse_light = 0;
	diffuse_light = max(dot(world_normal,L), 0);

	// TODO: compute specular light component
	float _specular_light = 0;
	_specular_light = dot(world_normal,H);

	float specular_light; 
	
	if (dot(world_normal,L) > 0) {
		
		specular_light = _specular_light;
	
	} else {
		
		specular_light = 0;
	
	}
	
	if (diffuse_light > 0)
	{
	}

	// TODO: compute light
	float light = ambient_light + (diffuse_light + specular_light) * 1 / pow(distance(light_position, world_pos),2);

	// TODO: send color light output to fragment shader
	color = light * object_color;

	gl_Position = Projection * View * Model * vec4(v_position, 1.0);
}
