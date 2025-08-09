#ifndef CGE_VECTOR3_H
#define CGE_VECTOR3_H
#include <stdlib.h>
#include "./vector4.h"

void cge_vector3_add(float* a, float* b, float* out);
void cge_vector3_subtract(float* a, float* b, float* out);
void cge_vector3_multiply(float* a, float* b, float* out);
void cge_vector3_divide(float* a, float* b, float* out);

void cge_vector3_add_scalar(float* a, float b, float* out);
void cge_vector3_subtract_scalar(float* a, float b, float* out);
void cge_vector3_multiply_scalar(float* a, float b, float* out);
void cge_vector3_divide_scalar(float* a, float b, float* out);

void cge_vector3_negate(float* a, float* out);

float cge_vector3_magnitude_squared(float* a);
float cge_vector3_magnitude(float* a);
void cge_vector3_normalize(float* a, float* out);
float cge_vector3_distance(float* a, float* b);
float cge_vector3_dot(float* a, float* b);
void  cge_vector3_lerp(float* a, float* b, float t, float* out);
void  cge_vector3_clamp(float* a, float* minimum, float* maximum, float* out);
void  cge_vector3_reflect(float* a, float* b, float* out);
void  cge_vector3_project(float*  a, float* b, float* out);
void  cge_vector3_reject(float*  self, float*  b, float* out);

float*  cge_vector3_rotate_by_quaternion(float* a, float* quaternion, float* out);
float*  cge_vector3_hadamard(float* a, float* b, float* out);

#endif