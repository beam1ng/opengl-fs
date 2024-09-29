#ifndef VERTEX_TRIANGLE_SHAPES_H
#define VERTEX_TRIANGLE_SHAPES_H
#include "objects.h"
#include "stdbool.h"
struct scene_object* GetQuadNormalized();
struct scene_object*  GetEmptySceneObject();
void dispose_scene_object(struct scene_object* object);
#endif