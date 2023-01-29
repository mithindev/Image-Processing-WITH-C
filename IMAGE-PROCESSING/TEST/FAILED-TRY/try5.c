#include <stdio.h>
#include <stdlib.h>
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
    int image1[] = {1, 2, 3, 4, 5};
    int image2[] = {1, 2, 3, 4, 5};
    int size = sizeof(image1) / sizeof(image1[0]);

    double similarity = correlationCoefficient(image1, image2, size);
    printf("Similarity: %f", similarity);
    return 0;
}