#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double correlationCoefficient(int *image1, int *image2, int size) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < size; i++) {
        mean1 += image1[i];
        mean2 += image2[i];
    }
    mean1 /= size;
    mean2 /= size;

    double numerator = 0, denominator1 = 0, denominator2 = 0;
    for (int i = 0; i < size; i++) {
        numerator += (image1[i] - mean1) * (image2[i] - mean2);
        denominator1 += pow((image1[i] - mean1), 2);
        denominator2 += pow((image2[i] - mean2), 2);
    }

    return numerator / sqrt(denominator1 * denominator2);
}

int main() {
    int width, height, max_color;
    char magic_number[3];
    FILE* fp = fopen("test1p3.ppm", "r");

    fscanf(fp, "%s", magic_number);
    if (magic_number[0] != 'P' || magic_number[1] != '3') {
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
    printf("%d", pixels);

    fclose(fp);
    return 0;
}
