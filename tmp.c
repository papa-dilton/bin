#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include "bmp.h"


int main(void)
{
    /*if (argc != 4)
    {
        printf("Incorrect usage\n");
        return 1;
    }*/


    RGBTRIPLE a = {10, 20, 30};
    RGBTRIPLE b = {40, 50, 60};
    RGBTRIPLE j = {70, 80, 90};
    RGBTRIPLE d = {110, 130, 140};
    RGBTRIPLE e = {120, 140, 150};
    RGBTRIPLE f = {130, 150, 160};
    RGBTRIPLE g = {200, 210, 220};
    RGBTRIPLE h = {220, 230, 240};
    RGBTRIPLE i = {240, 250, 255};

    int r = 1;
    int c = 1;
/*
    RGBTRIPLE image[][] = {{a, b, j}, {d, e, f}, {g, h, i}};



    RGBTRIPLE AVG;
    AVG.rgbtRed =   round(((double) image[r-1][c-1].rgbtRed + image[r-1][c].rgbtRed + image[r-1][c+1].rgbtRed + image[r][c-1].rgbtRed + image[r][c].rgbtRed + image[r][c+1].rgbtRed + image[r+1][c-1].rgbtRed + image[r+1][c].rgbtRed + image[r+1][c+1].rgbtRed) / 9);
    AVG.rgbtGreen = round(((double) image[r-1][c-1].rgbtGreen + image[r-1][c].rgbtGreen + image[r-1][c+1].rgbtGreen + image[r][c-1].rgbtGreen + image[r][c].rgbtGreen + image[r][c+1].rgbtGreen + image[r+1][c-1].rgbtGreen + image[r+1][c].rgbtGreen + image[r+1][c+1].rgbtGreen) / 9);
    AVG.rgbtBlue =  round(((double) image[r-1][c-1].rgbtBlue + image[r-1][c].rgbtBlue + image[r-1][c+1].rgbtBlue + image[r][c-1].rgbtBlue + image[r][c].rgbtBlue + image[r][c+1].rgbtBlue + image[r+1][c-1].rgbtBlue + image[r+1][c].rgbtBlue + image[r+1][c+1].rgbtBlue) / 9);


    printf("Average is : %i\n", AVG.rgbtRed);
*/
printf("%i\n", a.rgbtGreen);
}