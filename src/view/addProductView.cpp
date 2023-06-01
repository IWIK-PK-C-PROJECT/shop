#include "addProductView.hpp"
#include "../util/util.hpp"
#include "../core/product.hpp"
#include "loggedMainView.hpp"

View *AddProductView::display(Session & session) {

    std::string check;
    Product productToAdd;

    auto& database = session.database;

    while(true)
    {
        clearScreen();
        std::cout<< "Name:";
        std::cin >> productToAdd.name;
        std::cout<< "Price:";
        std::cin >> productToAdd.price;
        std::cout <<"Is this data ok? [Y/N] ";
        std::cin >> check;
        if (check == "Y" || check == "y")
        {
            if( database.canAddProduct(productToAdd))
            {
                database.addProduct(productToAdd);
                std::cout << "Product successfully added" << std::endl;
                return new LoggedMainView();
            }
            std::cout << "Invalid data, please fill correct data" << std::endl;
        }

        std::cout << "Do you want to exit? [Y/N] ";
        std::cin >> check;
        if (check == "Y" || check == "y")
        {
            return new LoggedMainView();
        }
    }
    return nullptr;
}

std::string AddProductView::getDisplayName() {
    return "AddProductView";
}
