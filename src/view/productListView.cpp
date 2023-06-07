#include <iostream>

#include "productListView.hpp"
#include "../util/util.hpp"
#include "loggedMainView.hpp"
#include "../core/Order.hpp"


View* ProductListView::display(Session& session)
{
    auto& database = session.database;

    clearScreen();
    for(Product & product : session.database.getAllProduct())
    {
        if (product.status != Product::Status::Available)
            continue;

        std::cout << product << std::endl;
    }

    std::cout << "1. Buy product" << std::endl;
    std::cout << "2. Back to main menu" << std::endl;

    std::string choice;
    std::cin >> choice;

    if (choice == "1")
    {
        std::string productToBuy;

        std::cout << "Choose a product (type its name)" << std::endl;
        std::cin >> productToBuy;

        for(Product& product : session.database.getAllProduct() )
        {
             if (productToBuy == product.name && product.status == Product::Status::Available)
             {
                 product.status = Product::Status::Preparation;
                 session.database.getAllOrders().emplace_back(productToBuy, std::chrono::system_clock::now());

                 return new ProductListView();
             }
        }
        std::cout << "Didnt find matching product, press anything to continue." <<std::endl;
        std::cin.get();
        std::cin.get();

        return new ProductListView();
    }
    else
        return new LoggedMainView();
}

std::string ProductListView::getDisplayName()
{
    return "ProductListView";
}