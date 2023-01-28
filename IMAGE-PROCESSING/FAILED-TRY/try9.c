#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <image1.ppm> <image2.ppm>\n", argv[0]);
        return 1;
    }

    // Open the first input image
    FILE *f1 = fopen(argv[1], "rb");
    if (!f1) {
        printf("Error: Failed to open the first input image\n");
        return 1;
    }

    // Open the second input image
    FILE *f2 = fopen(argv[2], "rb");
    if (!f2) {
        printf("Error: Failed to open the second input image\n");
        return 1;
    }

    // Read the pixel data from the first input image
    int width1, height1, max_color1;
    fscanf(f1, "P6 %d %d %d", &width1, &height1, &max_color1);
    unsigned char *pixels1 = (unsigned char *)malloc(width1 * height1 * 3);
    fread(pixels1, sizeof(unsigned char), width1 * height1 * 3, f1);

    // Read the pixel data from the second input image
    int width2, height2, max_color2;
    fscanf(f2, "P6 %d %d %d", &width2, &height2, &max_color2);
    unsigned char *pixels2 = (unsigned char *)malloc(width2 * height2 * 3);
    fread(pixels2, sizeof(unsigned char), width2 * height2 * 3, f2);

    // Close the files
    fclose(f1);
    fclose(f2);

    // Do something with the pixel data (e.g. compare the images, concatenate them, etc.)
    // ...

    // Free the allocated memory
    free(pixels1);
    free(pixels2);

    return 0;
}
