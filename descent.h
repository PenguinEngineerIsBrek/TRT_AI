#ifndef DESCENT_H
#define DESCENT_H

#include "math/grad.h"
#include "math/cost.h"
#include "FNN/node.h"
#include "FNN/layer.h"
#include "FNN/act.h"
#include <stdio.h>
#include <stdlib.h>

void gradient_descent(struct layer prev, struct layer curr, struct node *n, double y, double alpha, double t, int it, int idx, int mode, int o)
{
    int iteration = 0;
    double prev_cost = cost_(n->value, y);

    while (iteration < it)
    {
        for (int i = 0; i < prev.num; i++)
        {
            double gradient = partder(cost_, n->value, y, 0) * prev.nodes[i].value;
            prev.nodes[i].weights[idx] -= alpha * gradient;
            n->bias -= alpha * gradient;
        }
        act(prev, curr, n, mode);
        double new_cost = cost_(n->value, y);
        if (o == 1)
        {
            printf("%.4f %.4f %.4f %d\n", new_cost, n->value, n->bias, iteration);
        }
        if (fabs(new_cost - prev_cost) < t)
        {
            break;
        }

        prev_cost = new_cost;
        iteration++;
    }
}

#endif
