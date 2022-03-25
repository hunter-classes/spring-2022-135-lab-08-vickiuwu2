#include <iostream>
#include "imageio.h"
#include "funcs.h"

int main() 
{ 
    invert("image1.pgm", "taskA-image1.pgm");
    invertHalf("image1.pgm", "taskB-image1.pgm");
    whiteBox("image1.pgm", "taskC-image1.pgm");
    frame("image1.pgm", "taskD-image1.pgm");
    scale("image1.pgm", "taskE-image1.pgm");
    pixelate("image1.pgm", "taskF-image1.pgm");

    invert("image2.pgm", "taskA-image2.pgm");
    invertHalf("image2.pgm", "taskB-image2.pgm");
    whiteBox("image2.pgm", "taskC-image2.pgm");
    frame("image2.pgm", "taskD-image2.pgm");
    scale("image2.pgm", "taskE-image2.pgm");
    pixelate("image2.pgm", "taskF-image2.pgm");

    return 0;
}