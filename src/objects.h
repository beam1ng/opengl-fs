#ifndef OBJECTS_H
#define OBJECTS_H
struct scene_object{
  float* vertices;
  float* texCoord0;
  float* texCoord1;
  float* texCoord2;
  float* texCoord3;
  float* texCoord4;
  float* texCoord5;
  float* texCoord6;
  float* texCoord7;
  int vertexArrayCount;
  int vertexCount;
  int texCoord0ArrayLength;
  int texCoord1ArrayLength;
  int texCoord2ArrayLength;
  int texCoord3ArrayLength;
  int texCoord4ArrayLength;
  int texCoord5ArrayLength;
  int texCoord6ArrayLength;
  int texCoord7ArrayLength;
};
#endif