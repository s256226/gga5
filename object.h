//
// 頂点配列オブジェクトの作成（モーフィング対応バージョン）
//
//   vertices: 頂点数
//   p0: 変形前の頂点位置
//   p1: 変形後の頂点位置
//   lines: 線分数
//   index: 線分の頂点インデックス
//   戻り値: 作成された VAO
//
extern GLuint createObject(GLuint vertices, const GLfloat(*p0)[3], const GLfloat(*p1)[3], GLuint lines, const GLuint* index);
