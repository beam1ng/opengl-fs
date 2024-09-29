#include "vertex_triangle_shapes.h"
#include "objects.h"
#include "stdbool.h"
#include <stdlib.h> // for malloc and free
#include <string.h> // for memcpy
#include <stdio.h>

#define QUAD_VERTEX_COUNT 6 // 2 triangles * 3 vertices each
#define VERTEX_COMPONENTS 3 // x, y and z components per vertex
#define UV_COMPONENTS 2 // x and y components per vertex

// Allocates memory, copies the quad vertices, and returns the size of the
// array.
struct scene_object*  GetQuadNormalized(){
  struct scene_object *object_data = GetEmptySceneObject();

  static const float quadVertices[] = {
    // upper left triangle
    -1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 0.0f,
    // lower right triangle
    -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f};

  static const float uv[] = {
    //upper left triangle
    0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
    //upper right triangle
    0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f};

  int vertexCount = QUAD_VERTEX_COUNT * VERTEX_COMPONENTS;
  size_t vertexArraySize = vertexCount * sizeof(float);

  object_data->vertices = (float *)malloc(vertexArraySize);
  if (object_data->vertices == NULL) {
    return NULL;
  }

  memcpy(object_data->vertices, quadVertices, vertexArraySize);

  object_data->vertexCount = QUAD_VERTEX_COUNT;
  object_data->vertexArrayCount = VERTEX_COMPONENTS * vertexCount;

  int uvCount = QUAD_VERTEX_COUNT * UV_COMPONENTS;
  size_t uvArraySize = uvCount * sizeof(float);

  object_data->texCoord0 = (float *)malloc(uvArraySize);
  if (object_data->texCoord0 == NULL) {
    return NULL;
  }

  memcpy(object_data->texCoord0, uv, uvArraySize);

  object_data->texCoord0ArrayLength = uvCount;

  return object_data;
}

struct scene_object*  GetEmptySceneObject(){
  struct scene_object* object = (struct scene_object*)(malloc(sizeof(struct scene_object)));
  object->texCoord0 = NULL;
  object->texCoord1 = NULL;
  object->texCoord2 = NULL;
  object->texCoord3 = NULL;
  object->texCoord4 = NULL;
  object->texCoord5 = NULL;
  object->texCoord6 = NULL;
  object->texCoord7 = NULL;
  object->texCoord0ArrayLength = 0;
  object->texCoord1ArrayLength = 0;
  object->texCoord2ArrayLength = 0;
  object->texCoord3ArrayLength = 0;
  object->texCoord4ArrayLength = 0;
  object->texCoord5ArrayLength = 0;
  object->texCoord6ArrayLength = 0;
  object->texCoord7ArrayLength = 0;
  object->vertices = NULL;
  object->vertexArrayCount = 0;
  object->vertexCount = 0;
  return object;
}

void dispose_scene_object(struct scene_object* object){
  free(object->texCoord0);
  free(object->texCoord1);
  free(object->texCoord2);
  free(object->texCoord3);
  free(object->texCoord4);
  free(object->texCoord5);
  free(object->texCoord6);
  free(object->texCoord7);
  free(object->vertices);
  free(object);
}