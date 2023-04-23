#include "database.hpp"

bool Database::canAddUser(const User &userToAdd)
{
    for(const auto &user : users)
    {
        if(userToAdd.email == user.email)
            return false;
    }

    return true;
}

void Database::addUser(const User &userToAdd)
{
    users.push_back(userToAdd);
}
