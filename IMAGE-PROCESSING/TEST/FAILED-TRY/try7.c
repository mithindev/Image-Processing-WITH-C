#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800 // Width of the new image
#define HEIGHT 600 // Height of the new image

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <image1.ppm> <image2.ppm> <output.ppm>\n", argv[0]);
        return 1;
    }

    // Open the input images
    FILE *f1 = fopen(argv[1], "rb");
    FILE *f2 = fopen(argv[2], "rb");
    if (!f1 || !f2) {
        printf("Error: Failed to open one of the input images\n");
        return 1;
    }

    // Open the output image
    FILE *fo = fopen(argv[3], "wb");
    if (!fo) {
        printf("Error: Failed to open the output image\n");
        return 1;
    }

    // Write the PPM header to the output image
    fprintf(fo, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    // Read the pixel data from the input images and write to the output image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH / 2; x++) {
            unsigned char pixel[3];

            // Read a pixel from the first input image
            fread(pixel, sizeof(unsigned char), 3, f1);

            // Write the pixel to the output image
            fwrite(pixel, sizeof(unsigned char), 3, fo);
        }

        for (int x = 0; x < WIDTH / 2; x++) {
            unsigned char pixel[3];

            // Read a pixel from the second input image
            fread(pixel, sizeof(unsigned char), 3, f2);

            // Write the pixel to the output image
            fwrite(pixel, sizeof(unsigned char), 3, fo);
        }
    }

    // Close the files
    fclose(f1);
    fclose(f2);
    fclose(fo);

    return 0;
}
