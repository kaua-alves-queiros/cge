#include "../include/vector3.h"
#include <math.h>

cge_vector3* cge_vector3_create(float x, float y, float z)
{
    cge_vector3* self = (cge_vector3*)malloc(sizeof(cge_vector3));
    self->x = x;
    self->y = y;
    self->z = z;
    return self;
}

void cge_vector3_add(cge_vector3* self, cge_vector3* to_add)
{
    self->x += to_add->x;
    self->y += to_add->y;
    self->z += to_add->z;
}

void cge_vector3_subtract(cge_vector3* self, cge_vector3* to_subtract)
{
    self->x -= to_subtract->x;
    self->y -= to_subtract->y;
    self->z -= to_subtract->z;
}

void cge_vector3_multiply(cge_vector3* self, cge_vector3* to_multiply)
{
    self->x = self->x * to_multiply->x;
    self->y = self->y * to_multiply->y;
    self->z = self->z * to_multiply->z;
}

void cge_vector3_divide(cge_vector3* self, cge_vector3* to_divide)
{
    self->x = self->x / to_divide->x;
    self->y = self->y / to_divide->y;
    self->z = self->z / to_divide->z;
}

void cge_vector3_add_scalar(cge_vector3* self, float to_add)
{
    self->x += to_add;
    self->y += to_add;
    self->z += to_add;
}

void cge_vector3_subtract_scalar(cge_vector3* self, float to_subtract)
{
    self->x -= to_subtract;
    self->y -= to_subtract;
    self->z -= to_subtract;
}

void cge_vector3_multiply_scalar(cge_vector3* self, float to_multiply)
{
    self->x = self->x * to_multiply;
    self->y = self->y * to_multiply;
    self->z = self->z * to_multiply;
}

void cge_vector3_divide_scalar(cge_vector3* self, float to_divide)
{
    self->x = self->x / to_divide;
    self->y = self->y / to_divide;
    self->z = self->z / to_divide;
}

void cge_vector3_negate(cge_vector3* self)
{
    self->x = -self->x;
    self->y = -self->y;
    self->z = -self->z;
}

float cge_vector3_magnitude_squared(cge_vector3* self)
{
    float sum_of_squares = (self->x * self->x) + (self->y * self->y) + (self->z * self->z);

    return sum_of_squares;
}

float cge_vector3_magnitude(cge_vector3* self)
{
    float sum_of_squares = vector3_magnitude_squared(self);

    return sqrtf(sum_of_squares);
}

void cge_vector3_normalize(cge_vector3* self)
{
    float magnitude = vector3_magnitude(self);

    if(magnitude == 0.0f)
    {
        self->x = 0.f;
        self->y = 0.f;
        self->x = 0.f;
    }
    else
    {
        self->x = self->x / magnitude;
        self->y = self->y / magnitude;
        self->z = self->z / magnitude;
    }
}


float cge_vector3_distance(cge_vector3* self, cge_vector3* b)
{
    cge_vector3* distance = cge_vector3_create(self->x - b->x, self->y - b->y, self->z - b->z);
    float magnitude = cge_vector3_magnitude(distance);
    free(distance);

    return magnitude;
}

void cge_vector3_lerp(cge_vector3* self, cge_vector3* b, float t)
{
    self->x = self->x + (b->x - self->x) * t;
    self->y = self->y + (b->x - self->y) * t;
    self->z = self->z + (b->z - self->z) * t;
}

void cge_vector3_clamp(cge_vector3* self, cge_vector3* minimum, cge_vector3* maximum)
{
     if (self->x < minimum->x) self->x = minimum->x;
    if (self->x > maximum->x) self->x = maximum->x;

    if (self->y < minimum->y) self->y = minimum->y;
    if (self->y > maximum->y) self->y = maximum->y;

    if (self->z < minimum->z) self->z = minimum->z;
    if (self->z > maximum->z) self->z = maximum->z;
}

void cge_vector3_reflect(cge_vector3* self, const cge_vector3* normal) {
    float dot = self->x * normal->x + self->y * normal->y + self->z * normal->z;

    self->x = self->x - 2.0f * dot * normal->x;
    self->y = self->y - 2.0f * dot * normal->y;
    self->z = self->z - 2.0f * dot * normal->z;
}

void cge_vector3_project(cge_vector3* self, const cge_vector3* b) {
    float dot_ab = self->x * b->x + self->y * b->y + self->z * b->z;

    float dot_bb = b->x * b->x + b->y * b->y + b->z * b->z;

    float scalar = dot_ab / dot_bb;

    self->x = scalar * b->x;
    self->y = scalar * b->y;
    self->z = scalar * b->z;
}

void cge_vector3_reject(cge_vector3* self, const cge_vector3* b) {
    float dot_ab = self->x * b->x + self->y * b->y + self->z * b->z;
    float dot_bb = b->x * b->x + b->y * b->y + b->z * b->z;
    float scalar = dot_ab / dot_bb;

    float proj_x = scalar * b->x;
    float proj_y = scalar * b->y;
    float proj_z = scalar * b->z;

    self->x = self->x - proj_x;
    self->y = self->y - proj_y;
    self->z = self->z - proj_z;
}
