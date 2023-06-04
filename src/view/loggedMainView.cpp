#include "loggedMainView.hpp"

#include <iostream>
#include "../util/util.hpp"

#include "welcomeView.hpp"
#include "loginView.hpp"

#include "productListView.hpp"
#include "addProductView.hpp"
#include "ordersView.h"

View* LoggedMainView::display(Session& session)
{
    std::string input;

    clearScreen();

    while(true)
    {
        std::cout << "1. Show Products" << std::endl;
        std::cout << "2. Add Product" << std::endl;
        std::cout << "3. Show my orders" << std::endl;
        std::cout << "4. LogOut" << std::endl;
        std::cout << "5. Exit" << std::endl;

        std::cin >> input;

        if (input == "1")
        {
            return new ProductListView();
        }
        else if (input == "2")
        {
            return new AddProductView();
        }
        else if (input == "3")
        {
            return new ordersView();
        }
        else if (input == "4")
        {
            session.saveOrdersFile();                // save files

            session.userEmail = "";                  // clear email
            session.database.getAllOrders().clear(); // clear orders

            return new WelcomeView();
        }
        else if (input == "5")
        {
            return nullptr;
        }
        else
        {
            clearScreen();
            std::cout << "Wrong input! Try again" << std::endl;
        }
    }
}

std::string LoggedMainView::getDisplayName()
{
    return "LoggedMainView";
}
