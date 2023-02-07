#include <stdio.h>
#include <stdlib.h>

// Function to read an image from a file
void read_image(const char *filename, int *width, int *height, unsigned char **image) {
  int i, j;
  FILE *fp;

  // Open the file for reading
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error: Could not open file %s\n", filename);
    exit(1);
  }

  // Read the width, height, and maximum value
  fscanf(fp, "P5\n%d %d\n255\n", width, height);

  // Allocate memory for the image data
  *image = (unsigned char *) malloc(*width * *height * sizeof(unsigned char));

  // Read the image data
  fread(*image, sizeof(unsigned char), *width * *height, fp);

  // Close the file
  fclose(fp);
}

// Function to write an image to a file
void write_image(const char *filename, int width, int height, unsigned char *image) {
  int i, j;
  FILE *fp;

  // Open the file for writing
  fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error: Could not open file %s\n", filename);
    exit(1);
  }

  // Write the header information
  fprintf(fp, "P5\n%d %d\n255\n", width, height);

  // Write the image data
  fwrite(image, sizeof(unsigned char), width * height, fp);

  // Close the file
  fclose(fp);
}

int main(int argc, char *argv[]) {
  int i, j;
  int width, height;
  int new_width, new_height;
  unsigned char *image;
  unsigned char *new_image;
  double x_ratio, y_ratio;
  int floor_x, floor_y;

  // Read the original image
  read_image("input.pgm", &width, &height, &image);

  // Get the new dimensions
  new_width = ...;
  new_height = ...;

  // Allocate memory for the resized image
  new_image = (unsigned char *) malloc(new_width * new_height * sizeof(unsigned char));

  // Calculate the scaling ratios
  x_ratio = (double) width / new_width;
  y_ratio = (double) height / new_height;

  // Resize the image
  for (i = 0; i < new_height; i++) {
    for (j = 0; j < new_width; j++) {
      floor_x = (int) (j * x_ratio);
      floor_y = (int) (i * y_ratio);
      new_image[i * new_width + j] = image[floor_y * width + floor_x];
    }
  }
