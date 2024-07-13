#ifndef WRITE_JSON_H
#define WRITE_JSON_H

#include <stdio.h>
#include <stdlib.h>
#include "cJSON/cJSON.h"

int write_value(char val_name[], char path[], double new_value)
{
    // Open the file
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open the file for reading.\n");
        return 1;
    }

    // Read the file contents into a string
    char buffer[1024];
    size_t len = fread(buffer, 1, sizeof(buffer) - 1, fp);
    fclose(fp);

    if (len == 0)
    {
        printf("Error: File is empty or read error.\n");
        return 1;
    }
    buffer[len] = '\0'; // Null-terminate the string

    // Parse the JSON data
    cJSON *json = cJSON_Parse(buffer);
    if (json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            printf("Error: %s\n", error_ptr);
        }
        return 1;
    }

    // Modify the JSON data
    cJSON *val = cJSON_GetObjectItemCaseSensitive(json, val_name);
    if (val != NULL)
    {
        if (cJSON_IsNumber(val))
        {
            cJSON_SetNumberValue(val, new_value);
        }
        else
        {
            printf("Error: The key exists but is not a number.\n");
            cJSON_Delete(json);
            return 1;
        }
    }
    else
    {
        printf("Error: Key not found. Adding the key.\n");
        cJSON_AddNumberToObject(json, val_name, new_value);
    }

    // Convert the modified JSON object back to a string
    char *modified_json_data = cJSON_Print(json);
    if (modified_json_data == NULL)
    {
        printf("Error: Failed to print JSON.\n");
        cJSON_Delete(json);
        return 1;
    }

    // Write the modified JSON data back to the file
    fp = fopen(path, "w");
    if (fp == NULL)
    {
        printf("Error: Unable to open the file for writing.\n");
        cJSON_free(modified_json_data);
        cJSON_Delete(json);
        return 1;
    }

    fprintf(fp, "%s", modified_json_data);
    fclose(fp);

    // Clean up
    cJSON_free(modified_json_data);
    cJSON_Delete(json);

    return 0;
}

#endif
