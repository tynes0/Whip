#version 330 core

layout(location = 0) out vec4 color;

uniform vec3 u_color;

in vec3 v_Position;

void main()
{
	color = vec4(u_color, 1.0f);
}