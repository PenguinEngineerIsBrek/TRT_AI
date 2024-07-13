#ifndef ACT_H
#define ACT_H

#include "node.h"
#include "layer.h"
#include <math.h>
#include "../math/relu.h"
#include "../math/sigmoid.h"
#include <stdio.h>

void act(struct layer prev, struct layer curr, struct node *n, int mode)
{
    int len1 = prev.num;
    int len2 = curr.num;
    float pre = 0.0;

    for (int i = 0; i < len2; i++)
    {
        if (&curr.nodes[i] == n)
        {
            for (int j = 0; j < len1; j++)
            {
                pre += prev.nodes[j].weights[i] * prev.nodes[j].value;
            }
        }
    }

    switch (mode)
    {
    case 0:
        n->value = tanh(relu(pre + n->bias));
        break;
    case 1:
        n->value = relu(pre + n->bias);
        break;
    case 2:
        n->value = tanh(pre + n->bias);
        break;
    case 3:
        n->value = sigmoid(pre + n->bias);
        break;
    default:
        perror("Need a proper activation function.\n");
        break;
    }
}
#endif