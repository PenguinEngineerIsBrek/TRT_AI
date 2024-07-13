#ifndef DIFF_H
#define DIFF_H
const float delta = 1.0e-6;
double derive(double (*f)(double), double x0)
{
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}
#endif