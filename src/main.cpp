#include <iostream>
#include "util/util.hpp"

int main() {
    std::string input;

    while(true)
    {
        clearScreen();
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Sign up" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cin >> input;
        if (input == "1")
        {

        }
        else if (input == "2")
        {

        }
        else if (input == "3")
        {
            return 0;
        }
        else
        {

        }
    }

        return 0;
}
