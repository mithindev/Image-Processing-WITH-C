#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j;
  int width, height;
  int new_width, new_height;
  unsigned char *image;
  unsigned char *new_image;
  double x_ratio, y_ratio;
  int floor_x, floor_y;

  // Read the original image
  // Code to read image width, height and pixel data from file

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

  // Write the resized image to a file
  // Code to write new_image to file

  // Free the memory
  free(image);
  free(new_image);

  return 0;
}
