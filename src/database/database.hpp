#pragma once

#include <vector>
#include "user.hpp"

class Database
{
public:
    Database() = default;

    bool isUserExist(const std::string & email) const;
    User getUser(const std::string & email) const;

    bool canAddUser(const User & userToAdd) const;
    void addUser(const User & userToAdd);

private:
    std::vector<User> users;
};