#ifndef READ_JSON_H
#define READ_JSON_H
#include <stdio.h>
#include "cJSON/cJSON.h"

double read_value(char val_name[], char path[])
{
    // Open the file
    FILE *fp = fopen("data.json", "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open the file.\n");
        return 1;
    }

    // Read the file contents into a string
    char buffer[1024];
    int len = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    // Parse the JSON data
    cJSON *json = cJSON_Parse(buffer);
    if (json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            printf("Error: %s\n", error_ptr);
        }
        cJSON_Delete(json);
        return 1;
    }

    // Access the JSON data
    cJSON *val = cJSON_GetObjectItemCaseSensitive(json, val_name);
    if (cJSON_IsNumber(val))
    {
        return val->valuedouble;
    }

    // Delete the JSON object
    cJSON_Delete(json);
}
#endif