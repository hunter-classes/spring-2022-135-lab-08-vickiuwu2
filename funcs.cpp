#include <iostream> 
#include <string> 
#include <fstream>

#include "imageio.h"
#include "funcs.h"

void invert(std::string imagefile, std::string result)
{
    int image[MAX_H][MAX_W]; //initialize arrays
    int height, width;

    readImage(imagefile, image, height, width); //reads image & dimensions

    int output[MAX_H][MAX_W]; 

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            output[row][col] = 255 - image[row][col]; //subtract pixel by 255 to find the invert
        }
    }

    writeImage(result, output, height, width); //print image
}

void invertHalf(std::string imagefile, std::string result)
{
    int image[MAX_H][MAX_W]; //initialize arrays 
    int height, width;

    readImage(imagefile, image, height, width); //reads image & dimensions

    int output[MAX_H][MAX_W]; 

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (col >= (width/2)) //if col is greater than or equal to half, invert 
            {
                output[row][col] = 255 - image[row][col]; 
            }
        }
    }

    writeImage(result, output, height, width); //print image
}

void whiteBox(std::string imagefile, std::string result)
{
    int image[MAX_H][MAX_W]; //initialize arrays 
    int height, width;

    readImage(imagefile, image, height, width); //reads image & dimensions

    int output[MAX_H][MAX_W]; 

    for (int row = 0; row < height; row++)
    {
		for (int col = 0; col < width; col++)
        {
            //if box is on the center dimensions, turn color to white
			if ((row >= height/4) && (row <= height * 3/4) && (col >= width/4) && (col <= width * 3/4))
            {
                image[row][col] = 255; 
            }
		}
	}

 	writeImage(result, output, height, width); //print image
}

void frame(std::string imagefile, std::string result)
{
    int image[MAX_H][MAX_W]; //initialize arrays 
    int height, width;

    readImage(imagefile, image, height, width); //reads image & dimensions

    int output[MAX_H][MAX_W]; 

	for (int row = 0; row < height; row++)
    {
		for (int col = 0; col < width; col++)
        {
            //if box is on the below dimensions, turn color to white
			if (((row <= height * 3/4) && (row >= height/4) && (col >= width/4) && (col <= width*3/4)) && ((row == height * 3/4) || (row == height/4) || (col == width/4) || (col == width * 3/4)))
            {
				output[row][col] = 255;
            }
		}
	}

	writeImage(result, output, height, width); //print image
}

void scale(std::string imagefile, std::string result)
{
    int image[MAX_H][MAX_W]; //initialize arrays 
    int height, width;

    readImage(imagefile, image, height, width); //reads image & dimensions

    int output[MAX_H][MAX_W]; 

    for (int row = 0; row < (height * 2); row++)
    {
        for (int col = 0; col < (width * 2); col++)
        {
            int r = row/2;
            int c = col/2;

            //increase height/width by 1 for each pixel
            output[row][col] = image[r][c];
            output[row][col+1] = image[r][c];
            output[row+1][col] = image[r][c];
            output[row+1][col+1] = image[r][c];
        }
    }

    writeImage(result, output, height, width); //print image
}

void pixelate(std::string imagefile, std::string result)
{
    int image[MAX_H][MAX_W]; //initialize arrays 
    int height, width;

    readImage(imagefile, image, height, width); //reads image & dimensions

    int output[MAX_H][MAX_W]; 

    for (int row = 0; row < height; row += 2)
    {
        for (int col = 0; col < width; col += 2)
        {
            //average of 2x2 window
            int average = (image[row][col] + image[row][col + 1] + image[row+1][col] + image[row+1][col+1])/4;
            //assign average to all pixels in 2x2 window
            output[row][col] = average;
            output[row][col+1] = average;
            output[row+1][col] = average;
            output[row+1][col+1] = average;
        }
    }

    writeImage(result, output, height, width);
}