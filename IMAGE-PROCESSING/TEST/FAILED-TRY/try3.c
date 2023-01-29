#include <stdio.h>
#include <math.h>

double correlationCoefficient(int x[], int y[], int n)
{
    int sum_x = 0, sum_y = 0, sum_xy = 0;
    int squareSum_x = 0, squareSum_y = 0;
 
    for (int i = 0; i < n; i++)
    {
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
        sum_xy = sum_xy + x[i] * y[i];
        squareSum_x = squareSum_x + x[i] * x[i];
        squareSum_y = squareSum_y + y[i] * y[i];
    }
 
    double corr = (double)(n * sum_xy - sum_x * sum_y) /
                  sqrt((n * squareSum_x - sum_x * sum_x) *
                       (n * squareSum_y - sum_y * sum_y));
    return corr;
}

int main()
{
    int n = 100; // number of pixels in image
    int image1[n], image2[n];

    // populate image1 and image2 with pixel values

    double similarity = correlationCoefficient(image1, image2, n);
    printf("Similarity: %f\n", similarity);
    return 0;
}
