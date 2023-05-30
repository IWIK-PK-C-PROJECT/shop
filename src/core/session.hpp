#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "database.hpp"

struct session
{
    std::string userEmail{};

    Database database;

    void loadUserFile();

    void saveUserFile();

    //TODO: Implement cart variable
};