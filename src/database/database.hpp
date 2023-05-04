#pragma once

#include <vector>
#include "user.hpp"

class Database
{
public:
    Database() = default;

    bool canAddUser(const User & userToAdd);
    void addUser(const User & userToAdd);

private:
    std::vector<User> users;
};