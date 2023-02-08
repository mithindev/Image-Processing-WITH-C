#include <stdio.h>
#include <math.h>

float correlation();

int main() {
    int check = 0;
    int width_t1, height_t1, max_color_t1, width_c1, height_c1, max_color_c1;
    char magic_number[3];

    FILE* t1 = fopen("test.ppm", "r");
    FILE* c1= fopen("comp.ppm", "r");

    while(check != 1){
        check = 1;

    fscanf(t1, "%s", magic_number);
    if (magic_number[0] != 'P' || magic_number[1] != '3') {
        printf("Invalid file format.\n");
        check = 0;
    }

    fscanf(c1, "%s", magic_number);
    if (magic_number[0] != 'P' || magic_number[1] != '3') {
        printf("Invalid file format.\n");
        check = 0;
    }
    if(check != 0){
    fscanf(t1, "%d %d %d", &width_t1, &height_t1, &max_color_t1);
    printf("test_1:\nWidth: %d, Height: %d, Max color: %d\n", width_t1, height_t1, max_color_t1);

    fscanf(c1, "%d %d %d", &width_c1, &height_c1, &max_color_c1);
    printf("comp_1:\nWidth: %d, Height: %d, Max color: %d\n", width_c1, height_c1, max_color_c1);

    if(width_t1 != width_c1 || height_t1 != height_c1 || max_color_t1 != max_color_c1){
        printf("the dimensions of the input image is not equal");
        check = 0;
    }
    printf("good to go");
    }

    }

    int pixels_t1[height_t1][width_t1][3];
    for (int i = 0; i < height_t1; i++) {
        for (int j = 0; j < width_t1; j++) {
            for (int k = 0; k < 3; k++) {
                fscanf(t1, "%d", &pixels_t1[i][j][k]);
            }
        }
    }

    int pixels_c1[height_c1][width_c1][3];
    for (int i = 0; i < height_c1; i++) {
        for (int j = 0; j < width_c1; j++) {
            for (int k = 0; k < 3; k++) {
                fscanf(t1, "%d", &pixels_c1[i][j][k]);
            }
        }
    }
    printf("%d",pixels_c1[25][64][2]);

    float red_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 0);
    printf("red channel correlation = %f",red_cc);
    float green_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 1);
    printf("green channel correlation = %f",green_cc);
    float blue_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 2);
    printf("blue channel correlation = %f",blue_cc);


}


float correlation(int x[1080][1920][3],int y[1080][1920][3],int m,int n,int k)
{ int i,j,xs=0,ys=0;
  float xa,ya,num=0,dem=0,xc,yc,xsf=0,ysf=0,cr;
  for (i=0;i<m;i++)
   for (j=0;j<n;j++)
    {xs += x[i][j][k];
     ys += y[i][j][k];
    }
  printf("hi");
  xa=(float)xs/(m*n);
  ya=(float)ys/(m*n);
  for (i=0;i<m;i++)
   for (j=0;j<n;j++)
    {
        xc=(float)x[i][j][k]-xa;
        yc=(float)y[i][j][k]-ya;
        num += xc*yc;
        xsf += (float)xc*xc;
        ysf += (float)ys*ys;
    }
  dem = sqrt(xs*ys);
  cr=num/dem;
  return cr;
  }