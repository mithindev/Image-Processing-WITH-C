#include <stdio.h>

int main() {
  
  printf("Image 1\n");
  int width1, height1, max_color1;
  char magic_number1[3];
  FILE *fp1 = fopen("test1p3.ppm", "r");

  fscanf(fp1, "%s", magic_number1);
  if (magic_number1[0] != 'P' || magic_number1[1] != '3') {
    printf("Invalid file format.\n");
    return 1;
  }

  fscanf(fp1, "%d %d %d", &width1, &height1, &max_color1);
  printf("Width: %d, Height: %d, Max color: %d\n", width1, height1, max_color1);

  int pixels1[height1][width1][3];
  for (int i = 0; i < height1; i++) {
    for (int j = 0; j < width1; j++) {
      for (int k = 0; k < 3; k++) {
        fscanf(fp1, "%d", &pixels1[i][j][k]);
      }
    }
  }

  printf("Image 2");

  int width2, height2, max_color2;
  char magic_number2[3];
  FILE *fp2 = fopen("test2p3.ppm", "r");

  fscanf(fp2, "%s", magic_number2);
  if (magic_number2[0] != 'P' || magic_number2[1] != '3') {
    printf("Invalid file format.\n");
    return 1;
  }

  fscanf(fp2, "%d %d %d", &width2, &height2, &max_color2);
  printf("Width: %d, Height: %d, Max color: %d\n", width2, height2, max_color2);

  int pixels2[height2][width2][3];
  for (int i = 0; i < height2; i++) {
    for (int j = 0; j < width2; j++) {
      for (int k = 0; k < 3; k++) {
        fscanf(fp2, "%d", &pixels2[i][j][k]);
      }
    }
  }
  
  fclose(fp2);
  fclose(fp1);
  return 0;
}