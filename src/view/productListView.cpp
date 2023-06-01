#include "productListView.hpp"

#include <iostream>
#include "../util/util.hpp"
#include "loggedMainView.hpp"
#include "../core/product.hpp"


View* ProductListView::display(session& session)
{
    auto& database = session.database;

        clearScreen();
        for(Product& product : session.database.getAllProduct() )
        {
            std::cout << product.name << " / ";
            std::cout << product.price << std::endl;
        }
    std::cout<<"1. Buy product"<<std::endl;
    std::cout<<"2. Back to main menu"<<std::endl;
    int choice;
    std::cin >> choice;
    if (choice == 1){
        //kup
    }else
        return new LoggedMainView();
}

