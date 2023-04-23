#pragma once
#include "user.hpp"

class Database
{
public:
    Database() = default;

    bool canAddUser(const User& user);
    void addUser(const User& user);
};