#include <iostream>

#include "ordersView.hpp"
#include "loggedMainView.hpp"
#include "../util/util.hpp"

View* ordersView::display(Session& session)
{
    std::string input;

    clearScreen();

    session.printOrders(std::cout);
    std::cout << std::endl;

    while(true)
    {
        std::cout << "1. Back" << std::endl;


        std::cin >> input;

        if (input == "1")
        {
            return new LoggedMainView();
        }
        else
        {
            clearScreen();
            std::cout << "Wrong input! Try again" << std::endl;
        }
    }
}

std::string ordersView::getDisplayName()
{
    return "ordersView";
}