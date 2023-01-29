#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    int width, height, max_color;
    // char magic_number[3];
    FILE* fp1 = fopen("test1p3.ppm", "r");
    if (!fp1) {
        printf("Error: Failed to open the first input image\n");
        return 1;
    }
    FILE* fp2 = fopen("test2p3.ppm", "r");
    if (!fp2) {
        printf("Error: Failed to open the second input image\n");
        return 1;
    }

    // fscanf(fp, "%s", magic_number);
    // if (magic_number[0] != 'P' || magic_number[1] != '3') {
    //     printf("Invalid file format.\n");
    //     return 1;
    // }

    fscanf(fp1, "%d %d %d", &width, &height, &max_color);
    printf("Width: %d, Height: %d, Max color: %d\n", width, height, max_color);

    fscanf(fp2, "%d %d %d", &width, &height, &max_color);
    printf("Width: %d, Height: %d, Max color: %d\n", width, height, max_color);

    

    int pixels1[height][width][3];
    int pixels2[height][width][3];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                fscanf(fp1, "%d", &pixels1[i][j][k]);
                fscanf(fp2, "%d", &pixels1[i][j][k]);
            }
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
