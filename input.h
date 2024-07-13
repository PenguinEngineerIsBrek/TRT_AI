#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>
#include <stdlib.h>

float calc_brightness(char filename[], int n)
{
    int width, height, channels;
    unsigned char *image_data = stbi_load(filename, &width, &height, &channels, 0);

    if (!image_data)
    {
        printf("Error loading image: %s\n", stbi_failure_reason());
        return 0;
    }

    size_t num_pixels = (size_t)width * height;
    float *brightness_values = (float *)malloc(num_pixels * sizeof(float));

    for (size_t i = 0; i < num_pixels; i++)
    {
        unsigned char r = image_data[i * channels + 0];
        unsigned char g = image_data[i * channels + 1];
        unsigned char b = image_data[i * channels + 2];

        // Calculate the perceived brightness
        float brightness = 0.2126f * (r / 255.0f) + 0.7152f * (g / 255.0f) + 0.0722f * (b / 255.0f);

        brightness_values[i] = brightness;
    }

    stbi_image_free(image_data);

    return brightness_values[n];
    free(brightness_values);
}