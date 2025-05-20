#version 410 core

in vec4 p0, p1;
uniform float t;
uniform mat4 mc;

void main(void)
{
  vec4 pos = mix(p0, p1, t); //
  gl_Position = mc * p0;
}
