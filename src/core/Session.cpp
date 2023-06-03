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
    }

    productFile.close();
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
}