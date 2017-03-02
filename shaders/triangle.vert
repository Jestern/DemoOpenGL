#version 450
layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_colour;
out vec3 colour;

uniform mat4 matrix; // our matrix

void main () {
    colour = vertex_colour;
    gl_Position = matrix * vec4 (vertex_position, 1.0);
}
