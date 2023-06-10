#include <algorithm>
#include "Session.hpp"

void Session::loadUserFile()
{
    std::fstream usersFile;
    usersFile.open("users.txt", std::ios::in );
    if (!usersFile.good()) {
        std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
        return;
    }

    while (!usersFile.eof()) {
        User userToAdd;
        usersFile >> userToAdd.email;
        usersFile >> userToAdd.name;
        usersFile >> userToAdd.surname;
        usersFile >> userToAdd.password;

        if( userToAdd.email.empty() or userToAdd.name.empty() or userToAdd.surname.empty() or userToAdd.password.empty() )
            continue;

        database.addUser(userToAdd);
    }

    usersFile.close();
}

void Session::loadProductFile()
{
    std::fstream productFile;
    productFile.open("products.txt", std::ios::in );
    if (!productFile.good()) {
        std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
        return;
    }
    int tempStatus;
    while (!productFile.eof()) {
        Product productToAdd;
        productFile >> productToAdd.name;
        productFile >> productToAdd.price;
        productFile >> tempStatus;
        productToAdd.status = static_cast<Product::Status>(tempStatus);
        if( productToAdd.name.empty() ) //  or productToAdd.price.empty()
            continue;

        database.addProduct(productToAdd);
    }

    productFile.close();
}

void Session::saveUserFile()
{
    std::fstream usersFile;
    usersFile.open("users.txt", std::ofstream::out | std::ofstream::trunc);
    for(User& user : database.getAllUsers() )
    {
        usersFile << user.email << " ";
        usersFile << user.name << " ";
        usersFile << user.surname << " ";
        usersFile << user.password;
        usersFile << std::endl;
    }

    usersFile.close();
}

void Session::saveProductFile()
{
    std::fstream productFile;
    productFile.open("products.txt", std::ofstream::out | std::ofstream::trunc);
    for(Product& product : database.getAllProduct() )
    {
        productFile << product.name << " ";
        productFile << product.price << " ";
        productFile << static_cast<int>(product.status) << " ";
        productFile << std::endl;
    }

    productFile.close();
}

void Session::loadOrdersFile()
{
    if(userEmail.empty())
        return;

    std::ifstream ordersFile;

    ordersFile.open("orders/" + userEmail + ".txt", std::ios::in );

    if (!ordersFile.good())
    {
        std::cout << "Can`t open orders file for "<< userEmail << std::endl;
        return;
    }

    std::time_t date_temp;
    std::string product_temp;

    while (!ordersFile.eof())
    {
        ordersFile >> date_temp;
        ordersFile.get();
        ordersFile >> product_temp;

        if(date_temp == 0 || product_temp.empty())
            continue;

        database.getAllOrders().emplace_back(product_temp, date_temp);

        date_temp = 0;
        product_temp = "";
    }

    ordersFile.close();
}

void Session::saveOrdersFile()
{
    if(userEmail.empty())
        return;

    std::ofstream ordersFile;
    ordersFile.open("orders/" + userEmail + ".txt", std::ofstream::out | std::ofstream::trunc );


    for(auto & order : database.getAllOrders() )
    {
        ordersFile << order.getOrderDate() << " ";
        ordersFile << order.getProductName() <<  std::endl;
    }

    ordersFile.close();
}

void Session::printOrders(std::ostream & os)
{
    for( const auto & order : database.getAllOrders())
        os << ctime(&order.getOrderDate()) << ' '<< *std::find_if(database.getAllProduct().begin(), database.getAllProduct().end(),[&order](const Product & p){return p.name == order.getProductName();}) << std::endl;
}

Session::Session()
{
    loadUserFile();
    loadProductFile();
}

Session::~Session()
{
    saveUserFile();
    saveProductFile();
    saveOrdersFile();
}