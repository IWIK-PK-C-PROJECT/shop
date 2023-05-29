#include "loggedMainView.hpp"

#include <iostream>
#include "../util/util.hpp"

#include "welcomeView.hpp"
#include "loginView.hpp"

std::unique_ptr<View> LoggedMainView::display(session& session)
{
    std::string input;
    clearScreen();
    std::cout << "1. LogOut" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cin >> input;
    if (input == "1")
    {
        return std::make_unique<WelcomeView>();
    }
    else if (input == "2")
    {
        return {};
    }

    return {};
}