#pragma once

#include <vector>
#include "user.hpp"
#include "product.hpp"

class Database
{
public:
    Database() = default;

    bool isUserExist(const std::string & email) const;
    User getUser(const std::string & email) const;

    bool canAddUser(const User & userToAdd) const;
    void addUser(const User & userToAdd);

    std::vector<User>& getAllUsers();

    void addProduct(const Product & productToAdd);
    bool canAddProduct(const Product &productToAdd) const;

    std::vector<Product>& getAllProduct();

private:
    std::vector<User> users {};
    std::vector<Product> products {};
};