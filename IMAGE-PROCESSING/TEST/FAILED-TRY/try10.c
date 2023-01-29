#include <stdio.h>
#include <stdlib.h>

int main() {
    // if (argc != 3) {
    //     printf("Usage: %s <image1.ppm> <image2.ppm>\n", argv[0]);
    //     return 1;
    // }

    // Open the input images
    FILE *f1 = fopen("test1p6.ppm", "rb");
    FILE *f2 = fopen("test1p6.ppm", "rb");
    if (!f1 || !f2) {
        printf("Error: Failed to open one of the input images\n");
        return 1;
    }

    // Read the header of the first image
    char magic[3];
    int width, height, maxValue;
    fscanf(f1, "%s %d %d %d", magic, &width, &height, &maxValue);

    // Make sure the image is in P6 PPM format
    if (magic[0] != 'P' || magic[1] != '6') {
        printf("Error: Input image 1 is not in P6 PPM format\n");
        return 1;
    }

    // Read the header of the second image
    fscanf(f2, "%s %d %d %d", magic, &width, &height, &maxValue);

    // Make sure the image is in P6 PPM format
    if (magic[0] != 'P' || magic[1] != '6') {
        printf("Error: Input image 2 is not in P6 PPM format\n");
        return 1;
    }

    // Allocate memory for the pixel data
    unsigned char *pixels1 = malloc(width * height * 3);
    unsigned char *pixels2 = malloc(width * height * 3);

    // Read the pixel data from the input images
    fread(pixels1, sizeof(unsigned char), width * height * 3, f1);
    fread(pixels2, sizeof(unsigned char), width * height * 3, f2);

    // Do something with the pixel data, for example, compare them

    // Free the memory
    free(pixels1);
    free(pixels2);

    // Close the files
    fclose(f1);
    fclose(f2);

    return 0;
}