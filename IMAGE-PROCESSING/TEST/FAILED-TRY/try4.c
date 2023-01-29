#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare image variables
    int width, height, max_color;
    unsigned char *image;

    // Read image from file
    FILE *in_file = fopen("test1.ppm", "rb");
    fscanf(in_file, "P6\n%d %d\n%d\n", &width, &height, &max_color);
    image = (unsigned char *) malloc(width * height * 3);
    fread(image, 1, width * height * 3, in_file);
    fclose(in_file);

    // Convert to grayscale
    for (int i = 0; i < width * height * 3; i += 3) {
        int avg = (image[i] + image[i + 1] + image[i + 2]) / 3;
        image[i] = avg;
        image[i + 1] = avg;
        image[i + 2] = avg;
    }

    // Write grayscale image to file
    FILE *out_file = fopen("output.ppm", "wb");
    fprintf(out_file, "P6\n%d %d\n%d\n", width, height, max_color);
    fwrite(image, 1, width * height * 3, out_file);
    fclose(out_file);

    free(image);
    return 0;
}