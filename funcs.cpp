#include <iostream> 
#include <string> 
#include <cassert>
#include <vector>
#include <fstream>
#include "funcs.h"
#include "imageio.h"

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
            output[row][col] = 255 - (image[row][col]); //subtract pixel by 255 to find the invert
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
                output[row][col] = 255 - (image[row][col]); 
            }
            else
            {
                output[row][col] = image[row][col];
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
                output[row][col] = 255; 
            }
            else
            {
                output[row][col] = image[row][col];
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
            else
            {
                output[row][col] = image[row][col];
            }
		}
	}

	writeImage(result, output, height, width); //print image
}

void scale(std::string name, std::string out_name) {
    int height, width; 
    int image[MAX_H][MAX_W];
    readImage(name, image, height, width); 

    std::ofstream ostr;
    ostr.open(out_name);
    if (ostr.fail()) {
        std::cout << "Unable to write file\n";
        exit(1);
    };

    std::vector<int> row_vector; 


    ostr << "P2" << std::endl;

    ostr << width * 2 << ' ';
    ostr << height * 2 << std::endl;
    ostr << 255 << std::endl;

    for (int hor = 0; hor < height; hor++) {
        for (int ver = 0; ver < width; ver++) {
            assert(image[hor][ver] < 256);
            assert(image[hor][ver] >= 0);

            ostr << image[hor][ver] << ' ';
            ostr << image[hor][ver] << ' ';

            row_vector.push_back(image[hor][ver]);
            row_vector.push_back(image[hor][ver]);
        }

        for(int z = 0; z < row_vector.size(); z++) {
            ostr << row_vector[z] << " ";
        }

        ostr << std::endl;
        row_vector.clear();
    }

    ostr.close();
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

    writeImage(result, output, height, width); //print image
}