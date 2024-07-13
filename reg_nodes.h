#ifndef REG_NODES_H
#define REG_NODES_H
#include <stdio.h>
#include <stdlib.h>
#include "cJSON/cJSON.h"
#include "FNN/node.h"
#include "FNN/layer.h"
#include <math.h>
#include "FNN/act.h"
int reg_nodes(char path[], int num, struct layer NN[num], float *y)
{
    cJSON *arr = cJSON_CreateArray();

    for (int i = 0; i < num; i++)
    {
        cJSON *larr = cJSON_CreateArray();
        for (int j = 0; j < NN[i].num; j++)
        {
            cJSON *root = cJSON_CreateObject();
            cJSON_AddNumberToObject(root, "bias", NN[i].nodes[j].bias);
            cJSON_AddNumberToObject(root, "x", NN[i].nodes[j].value);
            if (i == num - 1)
            {
                cJSON_AddNumberToObject(root, "y", y[j]);
            }
            cJSON_AddItemToArray(larr, root);
        }
        cJSON_AddItemToArray(arr, larr);
    }
    char *ArrSTR = cJSON_Print(arr);
    FILE *file = fopen(path, "w");
    if (file == NULL)
    {
        perror("Unable to open file");
        cJSON_Delete(arr);
        free(ArrSTR);
        return 1;
    }
    fprintf(file, "%s", ArrSTR);
    cJSON_Delete(arr);
    free(ArrSTR);
    return 0;
}
#endif