#include "util.hpp"
#include <iostream>
#include <stdlib.h>

void clearScreen()
{
    #if _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    std::cout << "-----------" << std::endl;
    //std::cout << "\033[2K\033[1;1H";
}