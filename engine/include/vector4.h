#ifndef CGE_VECTOR4_H
#define CGE_VECTOR4_H

typedef struct cge_vector4 cge_vector4;

struct cge_vector4
{
    float x;
    float y;
    float z;
    float w;
};

cge_vector4* cge_vector4_create(float x, float y, float z, float w);

#endif