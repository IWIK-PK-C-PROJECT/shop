#include "loggedMainView.hpp"

#include <iostream>
#include "../util/util.hpp"

#include "welcomeView.hpp"
#include "loginView.hpp"

#include "productListView.hpp"
#include "addProductView.hpp"

View* LoggedMainView::display(Session& session)
{
    std::string input;
    clearScreen();
    std::cout << "1. Show Products" << std::endl;
    std::cout << "2. Add Product" << std::endl;
    std::cout << "3. LogOut" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cin >> input;
    if (input == "3")
    {
        return new WelcomeView();
    }
    else if (input == "4")
    {
        return nullptr;
    }
    else if (input == "1")
    {
        return new ProductListView();
    }
    else if (input == "2")
    {
        return new AddProductView();
    }

    return nullptr;
}

std::string LoggedMainView::getDisplayName()
{
    return "LoggedMainView";
}
