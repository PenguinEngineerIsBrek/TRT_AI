#ifndef INIT_NODES_H
#define INIT_NODES_H
#include "NN.h"
#include "layer.h"
#include "node.h"
#include <stdlib.h>
void init_nodes(struct network *nn)
{
    for (int i = 0; i < sizeof(nn->layers) / sizeof(struct layer); i++)
    {
        nn->layers[i].nodes = calloc(nn->layers[i].num, sizeof(struct node));
        if (nn->layers[i].nodes == NULL)
        {
            // Handle allocation failure
            fprintf(stderr, "Memory allocation failed\n");
        }
    }
}
void free_nodes(struct network *nn)
{
    for (int i = 0; i < sizeof(nn->layers) / sizeof(struct layer); i++)
    {
        free(nn->layers[i].nodes);
    }
}

#endif
