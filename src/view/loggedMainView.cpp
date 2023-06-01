#include "loggedMainView.hpp"

#include <iostream>
#include "../util/util.hpp"

#include "welcomeView.hpp"
#include "loginView.hpp"

#include "productListView.hpp"

View* LoggedMainView::display(session& session)
{
    std::string input;
    clearScreen();
    std::cout << "1. Show Products" << std::endl;
    std::cout << "2. LogOut" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cin >> input;
    if (input == "2")
    {
        return new WelcomeView();
    }
    else if (input == "3")
    {
        return nullptr;
    }
    else if (input == "1")
    {
        return new ProductListView();
    }

    return nullptr;
}

std::string LoggedMainView::getDisplayName()
{
    return "LoggedMainView";
}
