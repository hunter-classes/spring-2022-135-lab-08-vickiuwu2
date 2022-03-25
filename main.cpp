#include <iostream>
#include <array> 
#include <string> 
#include <fstream>

#include "imageio.h"
#include "funcs.h"

const std::array<std::string, 2> names_of_images = {"image1.pgm", "image2.pgm"};
const std::array<std::string, 6> task = {"A", "B", "C", "D", "E", "F"}; 

typedef void (*tasks) (std::string input, std::string result); 

int main() 
{ 
    std::string input; 
    std::string result; 

    tasks funcs[] = {invert, invertHalf, whiteBox, frame, scale, pixelate}; 

    for(int i = 0; i < task.size(); i++) 
    {
        for(int j = 0; j < names_of_images.size(); j++) 
        {
            std::string out_name = "task" + task[j] + "-" + names_of_images[j];
            funcs[i](names_of_images[j], result);
        }
    }

    return 0;
}