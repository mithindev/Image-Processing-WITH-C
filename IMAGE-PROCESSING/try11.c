#include <stdio.h>

int main() {
    
    // Open the image file for reading.
    FILE* fp = fopen("image.ppm", "r");

    // Read the header Information.
    char header[3];
    int width, height, max_color;
    fscanf(fp, "%s", header);
    fscanf(fp, "%d %d %d", &width, &height, &max_color);
    if (header[0] != 'P' || header[1] != '3') {
        printf("Invalid file format.\n");
        return 1;
    }

    int pixels[height][width][3];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                fscanf(fp, "%d", &pixels[i][j][k]);
            }
        }
    }

    fclose(fp);
    return 0;
}
