#include "../include/vector3.h"
#include <math.h>

void cge_vector3_add(float* a, float* b, float* out)
{
    out[0] = a[0] + b[0];
    out[1] = a[1] + b[1];
    out[2] = a[2] + b[2];
}

void cge_vector3_subtract(float* a, float* b, float* out)
{
    out[0] = a[0] - b[0];
    out[1] = a[1] - b[1];
    out[2] = a[2] - b[2]; 
}

void cge_vector3_multiply(float* a, float* b, float* out)
{
    out[0] = a[0] * b[0];
    out[1] = a[1] * b[1];
    out[2] = a[2] * b[2];
}

void cge_vector3_divide(float* a, float* b, float* out)
{
    out[0] = a[0] / b[0];
    out[1] = a[1] / b[1];
    out[2] = a[2] / b[2];
}

void cge_vector3_add_scalar(float* a, float b, float* out)
{
    out[0] = a[0] + b;
    out[1] = a[1] + b;
    out[2] = a[2] + b;
}

void cge_vector3_subtract_scalar(float* a, float b, float* out)
{
    out[0] = a[0] - b;
    out[1] = a[1] - b;
    out[2] = a[2] - b;
}

void cge_vector3_multiply_scalar(float* a, float b, float* out)
{
    out[0] = a[0] * b;
    out[1] = a[1] * b;
    out[2] = a[2] * b;
}

void cge_vector3_divide_scalar(float* a, float b, float* out)
{
    out[0] = a[0] / b;
    out[1] = a[1] / b;
    out[2] = a[2] / b;
}

void cge_vector3_negate(float* a, float* out)
{
    out[0] = -a[0];
    out[1] = -a[1];
    out[2] = -a[2];
}

float cge_vector3_magnitude_squared(float* a)
{
    return (a[0] * a[0]) + (a[1] * a[1]) + (a[2] * a[2]);
}

float cge_vector3_magnitude(float* a)
{
    float square_sum = cge_vector3_magnitude_squared(a);

    return sqrt(square_sum);
}

void cge_vector3_normalize(float* a, float* out)
{
    float magnitude = cge_vector3_magnitude(a);

    if(magnitude > 1e-6f) {
        out[0] = a[0] / magnitude;
        out[1] = a[1] / magnitude;
        out[2] = a[2] / magnitude;
    }
    else
    {
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
    }
}

float cge_vector3_distance(float* a, float* b)
{
    float subtract[3] = {
        a[0] - b[0],
        a[1] - b[1],
        a[2] - b[2]
    };

    return cge_vector3_magnitude(subtract);
}

float cge_vector3_dot(float* a, float* b)
{
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

void  cge_vector3_lerp(float* a, float* b, float t, float* out)
{
    out[0] = a[0] + (a[0] - b[0]) * t;
    out[1] = a[1] + (a[1] - b[1]) * t;
    out[2] = a[2] + (a[2] - b[2]) * t;
}

void  cge_vector3_clamp(float* a, float* minimum, float* maximum, float* out)
{
    if(a[0] < minimum[0])
    {
        out[0] = minimum[0];
    }
    else if(a[0] > maximum[0])
    {
        out[0] = maximum[0];
    }
    else
    {
        out[0] = a[0];
    }

    if(a[1] < minimum[1])
    {
        out[1] = minimum[1];
    }
    else if(a[1] > maximum[1])
    {
        out[1] = maximum[1];
    }
    else
    {
        out[1] = a[1];
    }

    if(a[2] < minimum[2])
    {
        out[2] = minimum[2];
    }
    else if(a[2] > maximum[2])
    {
        out[2] = maximum[2];
    }
    else
    {
        out[2] = a[2];
    }
}

void cge_vector3_reflect(float* a, float* b, float* out)
{
    float dot = cge_vector3_dot(a, b);
    float scale = 2.0f * dot;

    out[0] = a[0] - scale * b[0];
    out[1] = a[1] - scale * b[1];
    out[2] = a[2] - scale * b[2];
}

void  cge_vector3_project(float*  a, float* b, float* out)
{
    float a_dot = cge_vector3_dot(a, b);
    float b_magnitude_squared = cge_vector3_magnitude_squared(b);

    if (b_magnitude_squared != 0.0f) {
        float scale = a_dot / b_magnitude_squared;
        out[0] = scale * b[0];
        out[1] = scale * b[1];
        out[2] = scale * b[2];
    }
    else
    {
        out[0] = out[1] = out[2] = 0.0f;
    }
}
}

void  cge_vector3_reject(float*  self, float*  b, float* out);

float*  cge_vector3_rotate_by_quaternion(float* a, float* quaternion, float* out);
float*  cge_vector3_hadamard(float* a, float* b, float* out);