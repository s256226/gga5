#include "gg.h"
using namespace gg;

#include "object.h"

//
// 頂点配列オブジェクトの作成（モーフィング対応）
//
//   vertices: 頂点数
//   p0: 変形前の頂点位置 GLfloat[3]
//   p1: 変形後の頂点位置 GLfloat[3]
//   lines: 線分数
//   index: 線分インデックス
//   戻り値: 作成された VAO 名
//
GLuint createObject(GLuint vertices, const GLfloat(*p0)[3], const GLfloat(*p1)[3], GLuint lines, const GLuint* index)
{
  GLuint vao, vbo[2], ibo;

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // p0 用 VBO
  glGenBuffers(2, vbo);

  glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat[3]) * vertices, p0, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
  glEnableVertexAttribArray(0); // layout(location = 0) in vec4 p0;

  // p1 用 VBO
  glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat[3]) * vertices, p1, GL_STATIC_DRAW);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
  glEnableVertexAttribArray(1); // layout(location = 1) in vec4 p1;

  // インデックスバッファ
  glGenBuffers(1, &ibo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * lines, index, GL_STATIC_DRAW);

  // 後片付け
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  return vao;
}
