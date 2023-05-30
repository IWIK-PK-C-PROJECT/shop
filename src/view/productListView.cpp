#include "productListView.hpp"

#include <iostream>
#include "../util/util.hpp"
#include "loggedMainView.hpp"
#include "../core/product.hpp"


View* ProductListView::display(session& session)
{
    auto& database = session.database;

    while(true)
    {
        clearScreen();
        for(Product& product : session.database.getAllProduct() )
        {
            std::cout << product.name << " / ";
            std::cout << product.price << std::endl;
        }
    }
}

