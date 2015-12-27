#version 410

in vec4 position;
out vec4 o_position;

void main() {
    o_position = position + vec4(1.0, 0.0, 0.0, 0.0);
}
