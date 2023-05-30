#include "database.hpp"
#include <vector>


bool Database::isUserExist(const std::string &email) const {
    for(const auto & user : users)
    {
        if(user.email == email)
            return true;
    }
    return false;
}

User Database::getUser(const std::string &email) const
{
    for(const auto & user : users)
    {
        if(user.email == email)
            return user;
    }

    return {};
}

bool Database::canAddUser(const User & userToAdd) const
{
    if (userToAdd.email == "" || userToAdd.password == ""){
        return false;
    }

    for(const auto & user : users)
    {
        if(userToAdd.email == user.email)
            return false;
    }

    return true;
}

void Database::addUser(const User & userToAdd)
{
    users.push_back(userToAdd);
}

std::vector<User>& Database::getAllUsers()
{
    return users;
}

void Database::addProduct(const Product & productToAdd)
{
    products.push_back(productToAdd);
}

std::vector<Product>& Database::getAllProduct()
{
    return products;
}
