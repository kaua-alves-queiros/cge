#ifndef CGE_VECTOR3_H
#define CGE_VECTOR3_H
#include <stdlib.h>
#include "./vector4.h"

typedef struct cge_vector3 cge_vector3;

struct cge_vector3
{
    float x;
    float y;
    float z;
};


cge_vector3* cge_vector3_create(float x, float y, float z);

void cge_vector3_add(cge_vector3* self, cge_vector3* to_add);
void cge_vector3_subtract(cge_vector3* self, cge_vector3* to_subtract);
void cge_vector3_multiply(cge_vector3* self, cge_vector3* to_multiply);
void cge_vector3_divide(cge_vector3* self, cge_vector3* to_divide);

void cge_vector3_add_scalar(cge_vector3* self, float to_add);
void cge_vector3_subtract_scalar(cge_vector3* self, float to_subtract);
void cge_vector3_multiply_scalar(cge_vector3* self, float to_multiply);
void cge_vector3_divide_scalar(cge_vector3* self, float to_divide);

void cge_vector3_negate(cge_vector3* self);

float cge_vector3_magnitude_squared(cge_vector3* self);
float cge_vector3_magnitude(cge_vector3* self);
void cge_vector3_normalize(cge_vector3* self);
float cge_vector3_distance(cge_vector3* self, cge_vector3* b);

void cge_vector3_lerp(cge_vector3* self, cge_vector3* b, float t);
void cge_vector3_clamp(cge_vector3* self, cge_vector3* minimum, cge_vector3* maximum);
void cge_vector3_reflect(cge_vector3* self, cge_vector3* normal);
void cge_vector3_project(cge_vector3* self, cge_vector3* b);
void cge_vector3_reject(cge_vector3* self, cge_vector3* b);

void cge_vector3_rotate_by_quaternion(cge_vector3* self, cge_vector4* quaternion);
void cge_vector3_hadamard(cge_vector3* self, cge_vector3* b);
#endif