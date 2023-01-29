#include <stdio.h>



int main() {
    int width, height, max_color;
    char header[3];
    FILE* fp = fopen("test1p3.ppm", "r");

    fscanf(fp, "%s", header);
    if (header[0] != 'P' || header[1] != '3') {
        printf("Invalid file format.\n");
        return 1;
    }

    fscanf(fp, "%d %d %d", &width, &height, &max_color);
    printf("Width: %d, Height: %d, Max color: %d\n", width, height, max_color);

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
