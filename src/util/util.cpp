#include "util.hpp"
#include <iostream>
#include <stdlib.h>

void clearScreen()
{
    system("clear");
    std::cout << "-----------" << std::endl;
    //std::cout << "\033[2K\033[1;1H";
}