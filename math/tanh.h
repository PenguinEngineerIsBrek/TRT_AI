#ifndef TANH_H
#define TANH_H
#include <math.h>
double tan_h(double x)
{
    double exp_2x = exp(2 * x);
    return (exp_2x - 1) / (exp_2x + 1);
}
#endif