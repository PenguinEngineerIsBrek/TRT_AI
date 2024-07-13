// Find the sigmoid function of x
#ifndef SIGMOID_H
#define SIGMOID_H
#include <math.h>

float sigmoid(float x)
{
    return 1 / (1 + exp(-x));
}
#endif