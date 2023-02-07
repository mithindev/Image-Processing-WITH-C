#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare image variables
    int width, height, max_color;
    unsigned char *image;
    int new_width, new_height;
    unsigned char *new_image;
    double x_ratio, y_ratio;
    int floor_x, floor_y;


    char str[100];
    printf("Enter the name of the file (with .ppm) :");
    gets(str);
    // Read image from file
    FILE *in_file = fopen(str, "rb");
    fscanf(in_file, "P6\n%d %d\n%d\n", &width, &height, &max_color);
    image = (unsigned char *) malloc(width * height * 3);
    fread(image, 1, width * height * 3, in_file);
    fclose(in_file);
    // Convert to Grayscale
    for (int i = 0; i < width * height * 3; i += 3) {
        int avg = (0.299*image[i] + 0.587*image[i + 1] + 0.114*image[i + 2]);
        image[i] = avg;
        image[i + 1] = avg;
        image[i + 2] = avg;
    }

    for (int i = 0; i < new_height; i++) {
      for (int j = 0; j < new_width; j++) {
        floor_x = (int) (j * x_ratio);
        floor_y = (int) (i * y_ratio);
        new_image[i * new_width + j] = image[floor_y * width + floor_x];
      }
    }


    // Write Gray Level Sliced image to file
    FILE *out_file = fopen("output_withB.ppm", "wb");
    fprintf(out_file, "P6\n%d %d\n%d\n", width, height, max_color);
    fwrite(image, 1, width * height * 3, out_file);
    fclose(out_file);
    free(image);
    return 0;
}