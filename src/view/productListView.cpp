#include "productListView.hpp"

#include <iostream>
#include "../util/util.hpp"
#include "loggedMainView.hpp"


View* ProductListView::display(Session& session)
{
    auto& database = session.database;

    clearScreen();
    for(Product & product : session.database.getAllProduct())
    {
        if (product.status != Product::Status::Available)
            continue;

        std::cout << "- " << product.name << " | "<< product.price << " USD" << std::endl;
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
             if (productToBuy == product.name)
             {
                 product.status = Product::Status::Preparation;
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
