#include "helpers.h"
#include <math.h>
#include <cs50.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            const BYTE avg = round(((double) image[r][c].rgbtRed + image[r][c].rgbtGreen + image[r][c].rgbtBlue) / 3);
            image[r][c].rgbtRed = avg;
            image[r][c].rgbtGreen = avg;
            image[r][c].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < floor(width / 2); c++)
        {
            //Buffer the current pixel
            buffer.rgbtRed = image[r][c].rgbtRed;
            buffer.rgbtGreen = image[r][c].rgbtGreen;
            buffer.rgbtBlue = image[r][c].rgbtBlue;

            //Move right to left pixel
            image[r][c].rgbtRed = image[r][width - c - 1].rgbtRed;
            image[r][c].rgbtGreen = image[r][width - c - 1].rgbtGreen;
            image[r][c].rgbtBlue = image[r][width - c - 1].rgbtBlue;

            //Buffer to right pixel
            image[r][width - c - 1].rgbtRed = buffer.rgbtRed;
            image[r][width - c - 1].rgbtGreen = buffer.rgbtGreen;
            image[r][width - c - 1].rgbtBlue = buffer.rgbtBlue;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[width][height];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            tmp[i][j].rgbtRed = image[i][j].rgbtRed;
            tmp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            tmp[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            //edge case (literally)
            if (true)
            {
                //make array of all 9 available neighbors and remove if unavailable
                int options[] = {true, true, true, true, true, true, true, true, true};
                if (r == 0)
                {
                    //top
                    options[0] = options[1] = options[2] = false;
                }
                else if (r == height - 1)
                {
                    //bottom
                    options[6] = options[7] = options[8] = false;
                }

                if (c == 0)
                {
                    //left
                    options[0] = options[3] = options[6] = false;
                }
                else if (c == width - 1)
                {
                    //right
                    options[2] = options[5] = options[8] = false;
                }




                //make a place for the new pixel to wait (not a pixel because a byte is too small)
                int red_sums = 0;
                int green_sums = 0;
                int blue_sums = 0;

                int count = 0;

                //loop through available pixels
                for (int i = 0; i < 9; i++)
                {
                    if (options[i])
                    {
                        const int CUR_ROW = floor(r + ((double) i / 3) - 1);
                        const int CUR_COL = c + (i % 3) - 1;
                        //map number i to pixel number
                        /*
                        if (CUR_ROW < 0 || CUR_COL < 0)
                        {
                            printf("At %i, %i\n", r, c);
                            printf("%i : %i,%i\n", i, CUR_ROW, CUR_COL);
                        }*/

                        red_sums += tmp[CUR_ROW][CUR_COL].rgbtRed;
                        green_sums += tmp[CUR_ROW][CUR_COL].rgbtGreen;
                        blue_sums += tmp[CUR_ROW][CUR_COL].rgbtBlue;

                        count++;
                    }
                }

                image[r][c].rgbtRed = round((double) red_sums / count);
                image[r][c].rgbtGreen = round((double) green_sums / count);
                image[r][c].rgbtBlue = round((double) blue_sums / count);

            }
            else
            {
                //center pixel, all 9 neighbors usable
                RGBTRIPLE avg;
                avg.rgbtRed =  (int) round(((double) image[r-1][c-1].rgbtRed + image[r-1][c].rgbtRed + image[r-1][c+1].rgbtRed + image[r][c-1].rgbtRed + image[r][c].rgbtRed + image[r][c+1].rgbtRed + image[r+1][c-1].rgbtRed + image[r+1][c].rgbtRed + image[r+1][c+1].rgbtRed) / 9);
                avg.rgbtGreen = (int) round(((double) image[r-1][c-1].rgbtGreen + image[r-1][c].rgbtGreen + image[r-1][c+1].rgbtGreen + image[r][c-1].rgbtGreen + image[r][c].rgbtGreen + image[r][c+1].rgbtGreen + image[r+1][c-1].rgbtGreen + image[r+1][c].rgbtGreen + image[r+1][c+1].rgbtGreen) / 9);
                avg.rgbtBlue =  (int) round(((double) image[r-1][c-1].rgbtBlue + image[r-1][c].rgbtBlue + image[r-1][c+1].rgbtBlue + image[r][c-1].rgbtBlue + image[r][c].rgbtBlue + image[r][c+1].rgbtBlue + image[r+1][c-1].rgbtBlue + image[r+1][c].rgbtBlue + image[r+1][c+1].rgbtBlue) / 9);

                if (r == 1 && c == 1)
                {
                    printf("%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n", image[r-1][c-1].rgbtRed , image[r-1][c].rgbtRed , image[r-1][c+1].rgbtRed , image[r][c-1].rgbtRed , image[r][c].rgbtRed , image[r][c+1].rgbtRed , image[r+1][c-1].rgbtRed , image[r+1][c].rgbtRed , image[r+1][c+1].rgbtRed);
                }
                image[r][c].rgbtRed = avg.rgbtRed;
                image[r][c].rgbtGreen = avg.rgbtGreen;
                image[r][c].rgbtBlue = avg.rgbtBlue;

            }

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
