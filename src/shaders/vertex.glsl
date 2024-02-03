# version 330 core
layout (location = 0) in vec3 apos;

void main() {
    gl_Position(apos.x, apos.y, apos.z, 1.0);
}