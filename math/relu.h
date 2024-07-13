#ifndef RELU_H
#define RELU_H
#include <math.h>
#define new_max(x, y) (((x) >= (y)) ? (x) : (y))

float relu(float x)
{
    return new_max(0, x);
}
#endif