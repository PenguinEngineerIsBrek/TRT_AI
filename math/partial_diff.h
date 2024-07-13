#ifndef PARTIAL_DIFF_H
#define PARTIAL_DIFF_H
#include "diff.h" // Make sure this header defines `delta`

double partder(double (*f)(double, double), double x, double y, int var)
{
    if (var == 0)
    { // Partial derivative with respect to x
        double x1 = x - delta;
        double x2 = x + delta;
        double y1 = f(x1, y);
        double y2 = f(x2, y);
        return (y2 - y1) / (x2 - x1);
    }
    else if (var == 1)
    { // Partial derivative with respect to y
        double y1 = y - delta;
        double y2 = y + delta;
        double f1 = f(x, y1);
        double f2 = f(x, y2);
        return (f2 - f1) / (y2 - y1);
    }
    return 0.0; // Default case, should not reach here
}

#endif
