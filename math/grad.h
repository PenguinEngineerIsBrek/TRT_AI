#ifndef GRAD_H
#define GRAD_H
#include "partial_diff.h"

double grad(double (*f)(double, double), double x, double y)
{
    return partder(f, x, y, 0) + partder(f, x, y, 1);
}

#endif
