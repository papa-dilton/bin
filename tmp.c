#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include "bmp.h"

typedef struct
{
    int rgbtRed;
    int rgbtGreen;
    int rgbtBlue;
}LARGERGBTRIPLE;


int sobel_gx(BYTE kernel[]);
int main(void)
{
    /*if (argc != 4)
    {
        printf("Incorrect usage\n");
        return 1;
    }*/


    RGBTRIPLE a = {0, 20, 30};
    RGBTRIPLE b = {1, 50, 60};
    RGBTRIPLE j = {0, 80, 90};
    RGBTRIPLE d = {0, 130, 140};
    RGBTRIPLE e = {0, 140, 150};
    RGBTRIPLE f = {0, 150, 160};
    RGBTRIPLE g = {0, 210, 220};
    RGBTRIPLE h = {0, 230, 240};
    RGBTRIPLE i = {0, 250, 255};
    RGBTRIPLE image[] = {a, b, j, d, e, f, g, h, i};

/*
    int r = 1;
    int c = 1;
    RGBTRIPLE image[][] = {{a, b, j}, {d, e, f}, {g, h, i}};



    RGBTRIPLE AVG;
    AVG.rgbtRed =   round(((double) image[r-1][c-1].rgbtRed + image[r-1][c].rgbtRed + image[r-1][c+1].rgbtRed + image[r][c-1].rgbtRed + image[r][c].rgbtRed + image[r][c+1].rgbtRed + image[r+1][c-1].rgbtRed + image[r+1][c].rgbtRed + image[r+1][c+1].rgbtRed) / 9);
    AVG.rgbtGreen = round(((double) image[r-1][c-1].rgbtGreen + image[r-1][c].rgbtGreen + image[r-1][c+1].rgbtGreen + image[r][c-1].rgbtGreen + image[r][c].rgbtGreen + image[r][c+1].rgbtGreen + image[r+1][c-1].rgbtGreen + image[r+1][c].rgbtGreen + image[r+1][c+1].rgbtGreen) / 9);
    AVG.rgbtBlue =  round(((double) image[r-1][c-1].rgbtBlue + image[r-1][c].rgbtBlue + image[r-1][c+1].rgbtBlue + image[r][c-1].rgbtBlue + image[r][c].rgbtBlue + image[r][c+1].rgbtBlue + image[r+1][c-1].rgbtBlue + image[r+1][c].rgbtBlue + image[r+1][c+1].rgbtBlue) / 9);


    printf("Average is : %i\n", AVG.rgbtRed);


*/


BYTE pixel_data_r[9];
BYTE pixel_data_g[9];
BYTE pixel_data_b[9];

for (int q = 0; q < 9; q++)
{
    pixel_data_r[q] = image[q].rgbtRed;
    pixel_data_g[q] = image[q].rgbtGreen;
    pixel_data_b[q] = image[q].rgbtBlue;
}


LARGERGBTRIPLE sobelx;
LARGERGBTRIPLE sobely;
//apply sobel operatior
sobelx.rgbtRed = sobel_gx(pixel_data_r);
sobelx.rgbtGreen = sobel_gx(pixel_data_g);
sobelx.rgbtBlue = sobel_gx(pixel_data_b);



printf("%i\n", sobelx.rgbtBlue);

}

int sobel_gx(BYTE kernel[])
{
    int sum = 0;
    sum += kernel[0] * -1;
    sum += kernel[1] * 0;
    sum += kernel[2] * 1;
    sum += kernel[3] * -2;
    sum += kernel[4] * 0;
    sum += kernel[5] * 2;
    sum += kernel[6] * -1;
    sum += kernel[7] * 0;
    sum += kernel[8] * 1;
    return sum;
}
