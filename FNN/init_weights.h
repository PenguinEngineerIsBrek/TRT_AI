#ifndef INIT_WEIGHTS_H
#define INIT_WEIGHTS_H
#include "NN.h"
#include "layer.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>
void init_weights(struct network *nn)
{
    for (int i = 0; i < sizeof(nn->layers) / sizeof(struct layer); i++)
    {
        if (i != sizeof(nn->layers) / sizeof(struct layer) - 1)
        {
            for (int j = 0; j < nn->layers[i].num; j++)
            {
                nn->layers[i].nodes[j].weights = calloc(nn->layers[i + 1].num, sizeof(float));
            }
        }
        else
        {
            break;
        }
    }
}

void free_weights(struct network *nn)
{
    for (int i = 0; i < sizeof(nn->layers) / sizeof(struct layer); i++)
    {
        if (i != sizeof(nn->layers) / sizeof(struct layer) - 1)
        {
            for (int j = 0; j < nn->layers[i].num; j++)
            {
                free(nn->layers[i].nodes[j].weights);
            }
        }
        else
        {
            break;
        }
    }
}
#endif
