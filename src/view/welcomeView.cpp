#include "welcomeView.hpp"

#include <iostream>
#include "../util/util.hpp"

#include "registerView.hpp"
#include "loginView.hpp"

View* WelcomeView::display(session& session)
{
    std::string input;
    clearScreen();
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Sign up" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cin >> input;
    if (input == "1")
    {
        return new LoginView();
    }
    else if (input == "2")
    {
        return new RegisterView();
    }

    return nullptr;
}
