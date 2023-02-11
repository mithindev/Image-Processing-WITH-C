#include <stdio.h>
#include <math.h>

double correlation(int x[234][175][3],int y[234][175][3],int m,int n,int k);

void main() {
    int check = 0;
    int width_t1, height_t1, max_color_t1, width_c1, height_c1, max_color_c1;
    char magic_number[3];

    FILE* t1 = fopen("test1p3c.ppm", "r");
    FILE* c1= fopen("test1p3.ppm", "r");

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
        printf("good to go\n");
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
    double red_cc,green_cc,blue_cc,gray_cc;
    red_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 0);
    printf("red channel correlation = %.2lf \n",red_cc);
    green_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 1);
    printf("green channel correlation = %.2lf \n",green_cc);
    blue_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 2);
    printf("blue channel correlation = %.2lf \n",blue_cc);
    gray_cc=((0.3*red_cc)+(0.59*green_cc)+(0.11*blue_cc));
    printf("gray channel correlation = %.2lf \n",gray_cc);
}

double correlation(int x[234][175][3],int y[234][175][3],int m,int n,int k)
{ int i,j;
  double xa,ya,num=0,dem=0,xc,yc,xsf=0,ysf=0,cr,xs=0,ys=0;
  for (i=0;i<m;i++)
   for (j=0;j<n;j++)
    {xs += x[i][j][k];
     ys += y[i][j][k];
    }
  xa=xs/(m*n);
  ya=ys/(m*n);
  for (i=0;i<m;i++)
   for (j=0;j<n;j++)
    {
        xc=x[i][j][k]-xa;
        yc=y[i][j][k]-ya;
        num += xc*yc;
        xsf += xc*xc;
        ysf += yc*yc;
    }
  dem = sqrt(xsf*ysf);
  cr=num/dem;
  return cr;
  }
