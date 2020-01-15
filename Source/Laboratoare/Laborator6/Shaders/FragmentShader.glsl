#version 330

// TODO: get values from fragment shader

in vec3 frag_position;
in vec3 frag_normal;
in vec3 frag_coordinate;
in vec3 frag_color;
uniform float elapsed_time;

out vec4 out_position;
out vec4 out_normal;
out vec4 out_coordinate;
out vec4 out_color;

void main()
{
	// TODO: write pixel out color

	out_color = vec4(elapsed_time, elapsed_time, 0.0, 1.0);

}