#include "database.hpp"

bool Database::canAddUser(const User &userToAdd)
{
    if (userToAdd.email == "" || userToAdd.password == ""){
        return false;
    }

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
