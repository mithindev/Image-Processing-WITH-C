#include <stdio.h>
#include <math.h>
#include <string.h>

double correlation(int (*x)[180][320], int (*y)[180][320], int m, int n, int k);
int main()
{
    int check = 0;
    int width_t1, height_t1, max_color_t1, width_c1, height_c1, max_color_c1;
    char header[3], mode;

    printf("select the mode Automatic or Manual or Exit [A/M/E]   ");
    scanf("%c", &mode);

    if (mode == 'A' || mode == 'a')
    {
        FILE *fp = fopen("files.txt", "r");
        fscanf(fp, "%s", header);
        if (header[0] != 'A')
        {
            printf("Invalid file format.\n");
            return 0;
        }
        int n_test, n_comp;
        fscanf(fp, "%d %d", &n_test, &n_comp);
        double correlations[n_test][n_comp];
        char file[2][10][10];
        for (int i = 0; i < n_test; i++)
        {
            fscanf(fp, "%s", header);
            strcpy(file[0][i], header);
        }
        for (int i = 0; i < n_comp; i++)
        {
            fscanf(fp, "%s", header);
            strcpy(file[1][i], header);
        }
        fclose(fp);
        for (int i = 0; i < n_test; i++)
        {
            for (int j = 0; j < n_comp; j++)
            {
                FILE *tt = fopen(file[0][i], "r");
                FILE *cc = fopen(file[1][j], "r");

                fscanf(tt, "%s", header);
                if (header[0] != 'P' || header[1] != '3')
                {
                    printf("Invalid file format.\n");
                    return 0;
                }

                fscanf(cc, "%s", header);
                if (header[0] != 'P' || header[1] != '3')
                {
                    printf("Invalid file format or file doesnt exist.\n");
                    return 0;
                }

                fscanf(tt, "%d %d %d", &width_t1, &height_t1, &max_color_t1);
                printf("test_1:\nWidth: %d, Height: %d, Max color: %d\n", width_t1, height_t1, max_color_t1);

                fscanf(cc, "%d %d %d", &width_c1, &height_c1, &max_color_c1);
                printf("comp_1:\nWidth: %d, Height: %d, Max color: %d\n", width_c1, height_c1, max_color_c1);

                if (width_t1 != width_c1 || height_t1 != height_c1 || max_color_t1 != max_color_c1)
                {
                    printf("the dimensions of the input image is not equal");
                    return 0;
                }
                printf("good to go\n");

                int pixels_t1[3][height_t1][width_t1];
                int pixels_c1[3][height_c1][width_c1];
                for (int i = 0; i < height_t1; i++)
                {
                    for (int j = 0; j < width_t1; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            fscanf(tt, "%d", &pixels_t1[k][i][j]);
                            fscanf(cc, "%d", &pixels_c1[k][i][j]);
                        }
                    }
                }

                fclose(tt);
                fclose(cc);
                double red_cc, green_cc, blue_cc, gray_cc;
                red_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 0);
                printf("red channel correlation = %.3lf \n", red_cc);
                green_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 1);
                printf("green channel correlation = %.3lf \n", green_cc);
                blue_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 2);
                printf("blue channel correlation = %.3lf \n", blue_cc);
                gray_cc = ((0.3 * red_cc) + (0.59 * green_cc) + (0.11 * blue_cc));
                printf("gray channel correlation = %.3lf \n", gray_cc);
                correlations[i][j] = gray_cc;
            }
        }
        FILE *out = fopen("output.txt", "w");
        for (int i = 0; i <= n_test; i++)
        {
            printf("\n");
            fprintf(out, "\n");
            for (int k = 0; k < n_comp * 19; k++)
            {
                printf("-");
                fprintf(out, "-");
            }
            printf("\n");
            fprintf(out, "\n");
            for (int j = 0; j <= n_comp; j++)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        printf("|\tcorrelation\t|");
                        fprintf(out, "|\tcorrelation\t|");
                    }
                    else
                    {
                        printf("\t%s\t|", file[1][j - 1]);
                        fprintf(out, "\t%s\t|", file[1][j - 1]);
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        printf("|\t%s\t|", file[0][i - 1]);
                        fprintf(out, "|\t%s\t|", file[0][i - 1]);
                    }
                    else
                    {
                        printf("\t%.3lf\t\t|", correlations[i - 1][j - 1]);
                        fprintf(out, "\t%.3lf\t\t|", correlations[i - 1][j - 1]);
                    }
                }
            }
        }
        printf("\n");
        fprintf(out, "\n");
        for (int k = 0; k < n_comp * 19; k++)
        {
            printf("-");
            fprintf(out, "-");
        }
        fclose(fp);
    }

    else if (mode == 'M' || mode == 'm')
    {
        int mean;
        char test[20], comp[20];
        printf("select the type of mean for combining three channels\nAVG - 0\nRGB - 1\nRMS - 2\n");
        scanf("%d", &mean);
        printf("enter the relative path of test file    ");
        scanf("%s", &test);
        printf("enter the relative path of comp file    ");
        scanf("%s", &comp);

        FILE *t1 = fopen(test, "r");
        FILE *c1 = fopen(comp, "r");

        check = 1;

        fscanf(t1, "%s", header);
        if (header[0] != 'P' || header[1] != '3')
        {
            printf("Invalid file format.\n");
            check = 0;
            return 0;
        }

        fscanf(c1, "%s", header);
        if (header[0] != 'P' || header[1] != '3')
        {
            printf("Invalid file format or file doesnt exist.\n");
            check = 0;
            return 0;
        }
        if (check != 0)
        {
            fscanf(t1, "%d %d %d", &width_t1, &height_t1, &max_color_t1);
            printf("test_1:\nWidth: %d, Height: %d, Max color: %d\n", width_t1, height_t1, max_color_t1);

            fscanf(c1, "%d %d %d", &width_c1, &height_c1, &max_color_c1);
            printf("comp_1:\nWidth: %d, Height: %d, Max color: %d\n", width_c1, height_c1, max_color_c1);

            if (width_t1 != width_c1 || height_t1 != height_c1 || max_color_t1 != max_color_c1)
            {
                printf("the dimensions of the input image is not equal");
                check = 0;
                return 0;
            }
            printf("good to go\n");
        }

        int pixels_t1[3][height_t1][width_t1];
        int pixels_c1[3][height_c1][width_c1];
        for (int i = 0; i < height_t1; i++)
        {
            for (int j = 0; j < width_t1; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    fscanf(t1, "%d", &pixels_t1[k][i][j]);
                    fscanf(c1, "%d", &pixels_c1[k][i][j]);
                }
            }
        }
        fclose(t1);
        fclose(c1);

        double red_cc, green_cc, blue_cc, gray_cc;
        red_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 0);
        printf("red channel correlation = %.3lf \n", red_cc);
        green_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 1);
        printf("green channel correlation = %.3lf \n", green_cc);
        blue_cc = correlation(pixels_t1, pixels_c1, height_t1, width_t1, 2);
        printf("blue channel correlation = %.3lf \n", blue_cc);
        switch (mean)
        {
        case 0: // average
            gray_cc = (red_cc + green_cc + blue_cc) / 3;
            break;
        case 1: // rgb to gray
            gray_cc = ((0.3 * red_cc) + (0.59 * green_cc) + (0.11 * blue_cc));
            break;
        default:
            gray_cc = sqrt(((red_cc * red_cc) + (green_cc * green_cc) + (blue_cc * blue_cc)) / 3);
        }
        printf("gray channel correlation = %.3lf \n", gray_cc);
    }
    else
    {
        return 0;
    }
    return 0;
}

double correlation(int (*x)[180][320], int (*y)[180][320], int m, int n, int k)
{
    int i, j;
    double xa, ya, num = 0, dem = 0, xc, yc, xsf = 0, ysf = 0, cr, xs = 0, ys = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            xs += x[k][i][j];

            ys += y[k][i][j];
        }
    }

    xa = xs / (m * n);
    ya = ys / (m * n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            xc = (x[k][i][j]) - xa;
            yc = (y[k][i][j]) - ya;
            num += xc * yc;
            xsf += xc * xc;
            ysf += yc * yc;
        }
    }
    dem = sqrt(xsf * ysf);
    cr = num / dem;
    return cr;
}