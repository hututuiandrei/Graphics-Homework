#version 330

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texture_coord;
layout(location = 3) in vec3 v_color;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

// Uniforms for light properties
uniform vec3 light_position;
uniform int obj_code;
uniform vec3 eye_position;
uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;
uniform vec3 object_color;
uniform float material_radius;

// Output values to fragment shader
out vec3 world_position;
out vec3 world_normal;
out vec4 color;

float random(vec2 co){

    return 5 * fract(sin(dot(co,vec2(12.9898,78.233)))*43758.5453123);
}

void main()
{

	vec3 v_pos;
	float posX = v_position.x;
	float posY = v_position.y;
	float posZ = v_position.z;	

	if(obj_code == 0) {

		float k1 = random(vec2(posX, posY));
		float k2 = random(vec2(posX, posY - 1));

		v_pos = vec3(posX + k1, posY - k2, posZ - k1);

	} 
	else {

		v_pos = vec3(posX, posY, posZ);
	}
	// TODO: compute world space vertex position and normal
	// TODO: send world position and world normal to Fragment Shader
	world_position = (Model * vec4(v_position,1)).xyz;	
	world_normal = normalize (mat3(Model) * v_normal);

	if(obj_code == 3) {

		color = vec4(0.8, 0, 0, 1);
	} 
	else if(obj_code == 4){

		color = vec4(0.8, 0.8, 0.2, 1);
	}
	else if(obj_code == 0) {

		color = vec4(v_color, 0.2);
	}
	else {

		color = vec4(v_color, 1);
	}
	gl_Position = Projection * View * Model * vec4(v_pos, 1.0);
}