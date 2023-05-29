#pragma once
#include <string>
#include "database.hpp"

struct session
{
    std::string userEmail{};

    Database database;
    //TODO: Implement cart variable
};