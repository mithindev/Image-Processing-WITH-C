#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double correlationCoefficient(int *image1, int *image2, int size);

int main() {
       // Open the input images
    
    FILE *f1 = fopen("test1p3.ppm", "r");
    
    FILE *f2 = fopen("test1p3c.ppm", "r");
    
    printf("Image 1 :");
    // Read the header of the first image
    char header[3];
    int width, height, maxValue;
    fscanf(f1, "%s %d %d %d", header, &width, &height, &maxValue);
    printf("%s %d %d %d\n", header, width, height, maxValue);

    // Make sure the image is in P6 PPM format
    if (header[0] != 'P' || header[1] != '3') {
        printf("Error: Input image 1 is not in P6 PPM format\n");
        return 1;
    }

    printf("Image 2 :");
    // Read the header of the second image
    fscanf(f2, "%s %d %d %d", header, &width, &height, &maxValue);
    printf("%s %d %d %d\n", header, width, height, maxValue);

    // Make sure the image is in P6 PPM format
    if (header[0] != 'P' || header[1] != '3') {
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

    int size = sizeof(pixels1) / sizeof(pixels1[0]); 
    double similarity = correlationCoefficient(pixels1, pixels2, size);
    printf("Similarity: %f", similarity);

    // Free the memory
    free(pixels1);
    free(pixels2);

    // Close the files
    fclose(f1);
    fclose(f2);

    return 0;
}

double correlationCoefficient(int *image1, int *image2, int size) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < size; i++) {
        mean1 += image1[i];
        mean2 += image2[i];
    }
    mean1 /= size;
    mean2 /= size;

    double numerator = 0, denominator1 = 0, denominator2 = 0;
    for (int i = 0; i < size; i++) {
        numerator += (image1[i] - mean1) * (image2[i] - mean2);
        denominator1 += pow((image1[i] - mean1), 2);
        denominator2 += pow((image2[i] - mean2), 2);
    }

    return numerator / sqrt(denominator1 * denominator2);
}